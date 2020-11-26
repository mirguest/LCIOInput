#ifndef k4_LCIO_INPUT_H
#define k4_LCIO_INPUT_H

#include "k4LCIOReader/k4LCIOReader.h"
#include "k4FWCore/DataHandle.h"
#include "GaudiAlg/GaudiAlgorithm.h"

#include <string>
#include <vector>
#include <map>

class IIncidentSvc;

class k4LCIOInput : public GaudiAlgorithm {

  public:

    k4LCIOInput(const std::string& name, ISvcLocator* svcLoc);

    virtual StatusCode initialize();
    virtual StatusCode execute();
    virtual StatusCode finalize();

  private:

    template<typename T>
    bool registCollection(const std::string& col);

    int m_nEvents;

    std::vector<std::pair<std::string, std::string>> m_collections;

    //input file(s)
    std::vector<std::string> m_files;
    std::string m_file;

    //map of collections to read: key is the collection name, value is the collection type
    Gaudi::Property<std::vector<std::string>> m_readCols{this, "collections", {}, "Places of collections to read"};

    //the map of collection name to its corresponding DataHandle
    std::map<std::string, DataObjectHandleBase*> m_dataHandles;

    //LCIO file handler
    k4LCIOReader m_lcioReader;

    // Pointer to the incident service.
    SmartIF<IIncidentSvc> m_incidentSvc;
};

template<typename T>
bool k4LCIOInput::registCollection(const std::string& col)
{
    auto handle = dynamic_cast<DataHandle<T>*>( m_dataHandles[col] );

    T* pCol = m_lcioReader.getCollection<T>(col);
    if ( pCol ) {
        handle->put(pCol);
        return true;
    }
    else {
        //FIXME:
        pCol = new T;
        handle->put(pCol);
        return false;
    }
}

#endif

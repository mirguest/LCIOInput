gaudi_subdir(k4LCIOInput v0r1)

find_package(ROOT COMPONENTS RIO Tree)
find_package(EDM4HEP REQUIRED)
find_package(k4LCIOReader REQUIRED)

set(k4LCIOInput_srcs
    src/k4LCIOInput.cc
    )

gaudi_add_module(k4LCIOInput ${k4LCIOInput_srcs}
    INCLUDE_DIRS k4FWCore ${EDM4HEP_INCLUDE_DIR} ${k4LCIOReader_INCLUDE_DIR}
    LINK_LIBRARIES GaudiKernel GaudiAlgLib k4FWCore k4LCIOReader::k4LCIOReader
    )

#gaudi_add_test()

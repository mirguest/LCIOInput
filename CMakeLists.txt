CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)

find_package(ROOT COMPONENTS RIO Tree)

find_package(GaudiProject)
set(CMAKE_CXX_STANDARD 17 CACHE STRING "")

gaudi_project(k4LCIOInput v0r1
              USE Gaudi v33r1
              USE k4FWCore v0r1)
find_package(EDM4HEP REQUIRED)
find_package(k4LCIOReader REQUIRED)


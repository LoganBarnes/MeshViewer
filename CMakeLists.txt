cmake_minimum_required(VERSION 3.9)
project(MeshViewer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

######################
### EXTERNAL REPOS ###
######################
include(DownloadProject)

# Download and unpack pybind11 at configure time
download_project(PROJ pybind11
        PREFIX thirdparty
        GIT_REPOSITORY https://github.com/pybind/pybind11.git
        GIT_TAG v2.2.2
        UPDATE_DISCONNECTED 1
        )

# compile pybind11 with current project
add_subdirectory(${pybind11_SOURCE_DIR} ${pybind11_BINARY_DIR})

###########################
### Mesh Viewer Project ###
###########################
set(MESH_SOURCES
        src/api/bind_api.hpp
        src/api/bind_mesh.cpp
        src/mesh/Mesh.hpp
        src/pymesh.cpp
        )

pybind11_add_module(pymesh ${MESH_SOURCES})
target_include_directories(pymesh PRIVATE src)

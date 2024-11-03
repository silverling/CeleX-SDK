cmake_minimum_required(VERSION 3.12)

project(CeleXSDK CXX)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV 4 REQUIRED)
find_package(PkgConfig REQUIRED)
    pkg_check_modules(libusb REQUIRED libusb-1.0)
find_package(Threads REQUIRED)


set(CELEX_SRCS 
    CeleX/base/xthread.cpp
    CeleX/base/filedirectory.cpp
    CeleX/base/dataqueue.cpp
    CeleX/configproc/tinyxml/tinyxmlparser.cpp
    CeleX/configproc/tinyxml/tinyxmlerror.cpp
    CeleX/configproc/tinyxml/tinyxml.cpp
    CeleX/configproc/tinyxml/tinystr.cpp
    CeleX/eventproc/datarecorder.cpp
    CeleX/eventproc/dataprocessthread.cpp
    CeleX/eventproc/celex5processeddata.cpp
    CeleX/eventproc/celex5dataprocessor.cpp
    CeleX/eventproc/celex5.cpp
    CeleX/configproc/xmlreader.cpp
    CeleX/configproc/wireincommand.cpp
    CeleX/configproc/celex5cfgmgr.cpp
    CeleX/cx3driver/usbinterface.cpp
    CeleX/cx3driver/package.cpp
    CeleX/cx3driver/cypress.cpp
    CeleX/cx3driver/celedriver.cpp
    CeleX/cx3driver/bulktransfer.cpp
)

add_library(CeleX SHARED ${CELEX_SRCS})

target_include_directories(CeleX PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(CeleX PUBLIC ${OpenCV_LIBS})
target_include_directories(CeleX PUBLIC ${libusb_INCLUDE_DIRS})
target_link_libraries(CeleX PUBLIC ${libusb_LIBRARIES})
target_link_libraries(CeleX PUBLIC Threads::Threads)

# Samples
set(CeleX_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/CeleX/include)
set(CeleX_LIB CeleX)
add_subdirectory(Samples)
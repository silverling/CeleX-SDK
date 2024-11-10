find_package(OpenCV 4 CONFIG REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets PrintSupport)

add_executable(
    CeleXDemo
    main.cpp
    mainwindow.cpp
    celex5widget.cpp
    settingswidget.cpp
    cfgslider.cpp
    sliderwidget.cpp
    celex5cfg.cpp
    videostream.cpp
    qcustomplot.cpp
)

target_link_libraries(CeleXDemo PRIVATE opencv_core opencv_highgui opencv_imgproc)
target_link_libraries(CeleXDemo PRIVATE Qt5::Widgets Qt5::PrintSupport)
set_target_properties(CeleXDemo PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
target_include_directories(CeleXDemo PRIVATE ${CeleX_INCLUDE_DIRS})
target_link_libraries(CeleXDemo PRIVATE ${CeleX_LIB})
target_include_directories(CeleXDemo PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/include")
target_link_options(CeleXDemo PRIVATE -L${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg/lib/Linux -lavcodec -lavformat -lavutil -lswresample)
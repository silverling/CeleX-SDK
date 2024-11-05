find_package(OpenCV 4 CONFIG REQUIRED)

add_executable(convertBinToCSV convertBinToCSV.cpp)
target_include_directories(convertBinToCSV PRIVATE ${CeleX_INCLUDE_DIRS})
target_link_libraries(convertBinToCSV PRIVATE ${CeleX_LIB})
target_link_libraries(convertBinToCSV PRIVATE opencv_core opencv_highgui opencv_imgproc)

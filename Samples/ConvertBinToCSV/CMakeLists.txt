add_executable(convertBinToCSV convertBinToCSV.cpp)
target_include_directories(convertBinToCSV PUBLIC ${CeleX_INCLUDE_DIRS})
target_link_libraries(convertBinToCSV ${CeleX_LIB})

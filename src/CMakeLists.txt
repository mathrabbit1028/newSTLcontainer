add_subdirectory(util)
add_subdirectory(NNsort)

add_executable(timeComparison timeComparison.cpp)
target_link_libraries(timeComparison PUBLIC util_obj NNsort_obj)
add_executable(binaryComparison binaryComparison.cpp)
target_link_libraries(binaryComparison PUBLIC util_obj NNsort_obj)
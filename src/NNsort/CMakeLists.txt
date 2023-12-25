add_library(NNsort_obj OBJECT predict.cpp
                              Algos.cpp
                              STLalgos.cpp)

target_link_libraries(NNsort_obj PUBLIC bcrypt)
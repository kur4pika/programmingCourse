add_library(data_structures
        vector/vector.c matrix/matrix.c matrix/matrix.h)

target_link_libraries(data_structures algorithms)
add_library(data_structures
        vector/vector.c matrix/matrix.c matrix/matrix.h string/string.c string/string.h)

target_link_libraries(data_structures algorithms)


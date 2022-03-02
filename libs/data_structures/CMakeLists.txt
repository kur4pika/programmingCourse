add_library(data_structures
        vector/vector.c matrix/matrix.c matrix/matrix.h string/string.c string/string.h string/tasks/tasks.c string/tasks/tasks.h string/tasks/test_tasks/test_tasks.c string/tasks/test_tasks/test_tasks.h string/test_functions/test_functions.c string/test_functions/test_functions.h)

target_link_libraries(data_structures algorithms)


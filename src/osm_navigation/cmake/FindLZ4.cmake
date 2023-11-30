find_path(LZ4_INCLUDE_DIRS 
    NAMES lz4.h
    PATHS /usr/include
)


execute_process(
    COMMAND "gcc -dumpmachine"
    RESULT_VARIABLE LZ4_GCC
)

find_library(LZ4_LIBRARIES
    NAMES lz4
    PATHS /usr/lib/${LZ4_GCC}
)

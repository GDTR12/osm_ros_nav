find_path(PROTOZERO_INCLUDE_DIR
    NAMES protozero/version.hpp
    PATHS /usr/include
)


set(PROTOZERO_INCLUDE_DIRS ${PROTOZERO_INCLUDE_DIR})
include_directories(${PROTOZERO_INCLUDE_DIRS})

if(PROTOZERO_INCLUDE_DIR)
    set(PROTOZERO_FOUND TRUE)
endif()
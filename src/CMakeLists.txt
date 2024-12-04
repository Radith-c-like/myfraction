project(src)

set(HEADER_FILES fraction.h program.h)
set(SOURCE_FILES fraction.cpp program.cpp)

add_library(src_lib ${SOURCE_FILES} ${HEADER_FILES})



message("这是Sort.cmake!!!")

include_directories("${PROJECT_SOURCE_DIR}/sort")

file (GLOB_RECURSE SORT_HEADERS ./sort/*.hpp)
source_group(Sort FILES ${SORT_HEADERS})



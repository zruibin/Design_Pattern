
message("这是DP.cmake!!!")

include_directories("${PROJECT_SOURCE_DIR}/DP")

file (GLOB_RECURSE DP_HEADERS ./DP/*.hpp)
source_group(Design_Pattern FILES ${DP_HEADERS})



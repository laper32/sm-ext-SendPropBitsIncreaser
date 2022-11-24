add_library(sendpropbitsincreaser SHARED
    ${CMAKE_CURRENT_LIST_DIR}/extension.cpp
)

target_include_directories(sendpropbitsincreaser PUBLIC
    ./
)

target_link_libraries(sendpropbitsincreaser PUBLIC amsdk)

set_target_properties(sendpropbitsincreaser PROPERTIES PREFIX "" SUFFIX ".ext.2.${HL2SDK_GAME}${LIB_SHARED_EXT}")


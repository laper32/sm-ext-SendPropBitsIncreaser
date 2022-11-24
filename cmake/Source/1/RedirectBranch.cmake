add_library(source1_sdk INTERFACE)

if (HL2SDK_GAME MATCHES "dota")
    message(FATAL_ERROR "Not provided.")
elseif (HL2SDK_GAME MATCHES "csgo")
    target_link_libraries(source1_sdk INTERFACE csgo_sdk)
    include(${CMAKE_CURRENT_LIST_DIR}/CSGO/Impl.cmake)
elseif (HL2SDK_GAME MATCHES "doi")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "insurgency")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "blade")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "portal2")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "swarm")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "l4d2")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "contagion")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "nd")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "l4d")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "tf2")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "bms")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "sdk2013")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "dods")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "hl2dm")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "css")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "eye")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "bgt")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "ep2")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "darkm")
    message(FATAL_ERROR "Not implemented")
elseif (HL2SDK_GAME MATCHES "ep1")
    message(FATAL_ERROR "Not implemented")
else()
    message(FATAL_ERROR "Unknown engine version found: \"${HL2SDK_GAME}\"")
endif()
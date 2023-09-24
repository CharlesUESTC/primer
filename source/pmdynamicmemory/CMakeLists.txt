add_library(PMDynamicMemory STATIC)

set(PRIVATE_SOURCE
    strblob.cpp
    strblob.h
)

target_sources(PMDynamicMemory
    PRIVATE
        ${PRIVATE_SOURCE}
)
target_include_directories(PMDynamicMemory
    PRIVATE
        ${OJ_ROOT_SOURCE_DIR}
)

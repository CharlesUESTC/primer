add_library(PMDynamicMemory STATIC)

set(PRIVATE_SOURCE
    queryresult.h
    strblob.cpp
    strblob.h
    textquery.cpp
    textquery.h
)

target_sources(PMDynamicMemory
    PRIVATE
        ${PRIVATE_SOURCE}
)
target_include_directories(PMDynamicMemory
    PRIVATE
        ${OJ_ROOT_SOURCE_DIR}
)

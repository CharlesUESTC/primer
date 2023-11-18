add_library(PMCopyControl STATIC)

set(PRIVATE_SOURCE
    hasptr.cpp
    hasptr.h
)

target_sources(PMCopyControl
    PRIVATE
        ${PRIVATE_SOURCE}
)
target_include_directories(PMCopyControl
    PRIVATE
        ${OJ_ROOT_SOURCE_DIR}
)

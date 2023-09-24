add_library(PMClasses STATIC)

set(PRIVATE_SOURCE
    salesdata.cpp
    salesdata.h
)

target_sources(PMClasses
    PRIVATE
        ${PRIVATE_SOURCE}
)
target_include_directories(PMClasses
    PRIVATE
        ${OJ_ROOT_SOURCE_DIR}
)

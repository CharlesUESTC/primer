add_library(PMFunctions STATIC)

set(PRIVATE_SOURCE
    makeplural.h
)

target_sources(PMFunctions
    PRIVATE
        ${PRIVATE_SOURCE}
)

set_target_properties(PMFunctions PROPERTIES LINKER_LANGUAGE CXX)

set(AVGPRICE_SOURCES
    avgprice.cpp
)

set(USEBLOB_SOURCES
    useblob.cpp
)

add_executable(avgprice)
target_sources(avgprice
    PRIVATE
        ${AVGPRICE_SOURCES}
)
target_include_directories(avgprice
    PRIVATE
        ${OJ_ROOT_SOURCE_DIR}
)
target_link_libraries(avgprice
    PRIVATE
        PMClasses
)

add_executable(useblob)
target_sources(useblob
    PRIVATE
        ${USEBLOB_SOURCES}
)
target_include_directories(useblob
    PRIVATE
        ${OJ_ROOT_SOURCE_DIR}
)
target_link_libraries(useblob
    PRIVATE
        PMDynamicMemory
)

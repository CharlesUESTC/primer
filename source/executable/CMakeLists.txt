set(AVGPRICE_SOURCES
    avgprice.cpp
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

set(USEBLOB_SOURCES
    useblob.cpp
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

set(QUERYMAIN_SOURCES
    querymain.cpp
)
add_executable(querymain)
target_sources(querymain
    PRIVATE
        ${QUERYMAIN_SOURCES}
)
target_include_directories(querymain
    PRIVATE
        ${OJ_ROOT_SOURCE_DIR}
)
target_link_libraries(querymain
    PRIVATE
        PMDynamicMemory
)

set(USEHASPTR_SOURCES
    usehasptr.cpp
)
add_executable(usehasptr)
target_sources(usehasptr
    PRIVATE
        ${USEHASPTR_SOURCES}
)
target_include_directories(usehasptr
    PRIVATE
        ${OJ_ROOT_SOURCE_DIR}
)
target_link_libraries(usehasptr
    PRIVATE
        PMCopyControl
)

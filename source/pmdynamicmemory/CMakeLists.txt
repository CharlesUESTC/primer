set(USEBLOB_SOURCES
    strblob.h
    useblob.cpp
)

add_executable(useblob)

target_sources(useblob
    PRIVATE
        ${USEBLOB_SOURCES}
)

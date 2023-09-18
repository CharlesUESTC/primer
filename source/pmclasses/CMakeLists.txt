set(AVGPRICE_SOURCES
    avgprice.cpp
    salesdata.cpp
    salesdata.h
)

add_executable(avgprice)

target_sources(avgprice
    PRIVATE
        ${AVGPRICE_SOURCES}
)

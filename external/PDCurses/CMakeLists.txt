cmake_minimum_required(VERSION 3.10)
project(PDCurses C)

file(GLOB PDCURSES_SRC
    pdcurses/*.c
    wincon/*.c
)

add_library(PDCurses STATIC ${PDCURSES_SRC})

target_include_directories(PDCurses PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

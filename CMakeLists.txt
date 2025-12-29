cmake_minimum_required(VERSION 3.5)
project(AscriibeEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------------------------
# Output folders
# ---------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

foreach(OUTPUTCONFIG Debug Release RelWithDebInfo MinSizeRel)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin/${OUTPUTCONFIG})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin/${OUTPUTCONFIG})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin/${OUTPUTCONFIG})
endforeach()

# ---------------------------------------------------------
# SDL2
# ---------------------------------------------------------
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/external/SDL2/cmake")
find_package(SDL2 REQUIRED)


# ---------------------------------------------------------
# SDL2_ttf
# ---------------------------------------------------------
set(SDL2_ttf_DIR "${CMAKE_SOURCE_DIR}/external/SDL2_ttf/cmake")
find_package(SDL2_ttf REQUIRED)


# ---------------------------------------------------------
# PDCurses (version avec les sources dans external/)
# ---------------------------------------------------------
add_subdirectory(external/PDCurses)
set(PDCURSES_LIB PDCurses)


# ---------------------------------------------------------
# Sources
# ---------------------------------------------------------
file(GLOB_RECURSE ENGINE_SOURCES
    AscriibeEngine/*.cpp
)
add_executable(ascriibe_engine
    ${ENGINE_SOURCES}
)

target_include_directories(ascriibe_engine PRIVATE
    external/PDCurses
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
)

target_link_libraries(ascriibe_engine PRIVATE
    ${PDCURSES_LIB}
    SDL2::SDL2
    SDL2::SDL2main
    SDL2_ttf::SDL2_ttf
)

# ---------------------------------------------------------
# COPY DLL TO BUILD FOLDER
# ---------------------------------------------------------
if (WIN32)
	add_custom_command(TARGET ascriibe_engine POST_BUILD
    		COMMAND ${CMAKE_COMMAND} -E copy_if_different     				"$<TARGET_FILE:SDL2::SDL2>"
        		"$<TARGET_FILE_DIR:ascriibe_engine>/"
		COMMENT "Updating SDL2.dll..."
	)

    	add_custom_command(TARGET ascriibe_engine POST_BUILD
        	COMMAND ${CMAKE_COMMAND} -E copy_if_different
            		"$<TARGET_FILE:SDL2_ttf::SDL2_ttf>"
            		"$<TARGET_FILE_DIR:ascriibe_engine>/"
        	COMMENT "Updating SDL2_ttf.dll..."
    )
endif()




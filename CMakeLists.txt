cmake_minimum_required(VERSION 3.25)
project(Tetris)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# Our Project

add_executable(${PROJECT_NAME} WIN32 main.cpp src/Game.cpp include/Game.hpp src/Board.cpp include/Board.hpp include/Vec2.hpp src/raylibCpp.cpp include/raylibCpp.hpp)
target_link_libraries(${PROJECT_NAME} raylib)

# Add a custom target for cleaning the build
add_custom_target(clean-all COMMAND ${CMAKE_BUILD_TOOL} clean COMMAND ${CMAKE_COMMAND} -E remove_directory
        ${CMAKE_BINARY_DIR}/bin COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles COMMAND
        ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/CMakeCache.txt COMMENT "Clean all generated files")
add_custom_target(fclean COMMAND ${CMAKE_BUILD_TOOL} clean COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/bin/tetris COMMENT "Clean executable")
add_custom_target(re COMMAND ${CMAKE_BUILD_TOOL} clean COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} COMMENT "Recompile project")

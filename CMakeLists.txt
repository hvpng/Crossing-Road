cmake_minimum_required(VERSION 3.20)
project(CrossingGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(CrossingGame ${SOURCES})
target_include_directories(CrossingGame PRIVATE include)

# Option A: point SFML_DIR to a local SFML package.
# Example: cmake -S . -B build -DSFML_DIR=third_party/SFML/lib/cmake/SFML
find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)
target_link_libraries(CrossingGame PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

add_custom_command(TARGET CrossingGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:CrossingGame>/assets
    COMMAND ${CMAKE_COMMAND} -E make_directory
            $<TARGET_FILE_DIR:CrossingGame>/save
)

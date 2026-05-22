cmake_minimum_required(VERSION 3.20)
project(CrossingGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(CrossingGame ${SOURCES})
target_include_directories(CrossingGame PRIVATE include)

# Option A: point CMAKE_PREFIX_PATH/SFML_DIR to a local SFML package.
# Example for MSYS2 UCRT64:
# cmake -S . -B build -G Ninja -DCMAKE_PREFIX_PATH=D:/msys2/ucrt64
find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)
target_link_libraries(CrossingGame PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)

add_custom_command(TARGET CrossingGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy -t
            $<TARGET_FILE_DIR:CrossingGame>
            $<TARGET_RUNTIME_DLLS:CrossingGame>
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:CrossingGame>/assets
    COMMAND ${CMAKE_COMMAND} -E make_directory
            $<TARGET_FILE_DIR:CrossingGame>/save
    COMMAND_EXPAND_LISTS
)

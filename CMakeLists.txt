cmake_minimum_required(VERSION 3.10) 

project(CROSSINGGAME) 
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
# Tự động lấy tất cả file cpp trong src/ 

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp) 

add_executable( CROSSINGGAME ${SRC_FILES} ) 

# Include headers 
target_include_directories( CROSSINGGAME PRIVATE include ) 

# Copy assets vào build/ 
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}) 

# Windows multimedia library (PlaySound) 
target_link_libraries( CROSSINGGAME winmm )
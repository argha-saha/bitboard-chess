cmake_minimum_required(VERSION 3.28)

project(Chess LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files
set(SOURCES
        src/main.cpp
        src/Application.cpp
        src/Game.cpp
        src/Board.cpp
        src/Move.cpp
        src/Validator.cpp
        src/Pawn.cpp
        src/Knight.cpp
        src/Bishop.cpp
        src/Rook.cpp
        src/Queen.cpp
        src/King.cpp
)

# Find SDL3
find_package(SDL3 REQUIRED)

# Create executable
add_executable(chess ${SOURCES})

# Include directories
target_include_directories(chess PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link SDL3
target_link_libraries(chess PRIVATE SDL3::SDL3)

# Set output directory
set_target_properties(chess PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
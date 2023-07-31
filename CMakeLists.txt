# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (qt_puzzle)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES_GUI
    src/main.cpp
    src/slidingpuzzle.cpp
    src/slidingpuzzletextif.cpp
)

set(SOURCES_CLI
    src/slidingpuzzlecli.cpp
    src/slidingpuzzle.cpp
    src/slidingpuzzletextif.cpp
)

# Add an executable with the above sources
add_executable(qt_puzzle ${SOURCES_GUI})
add_executable(qt_puzzle_cli ${SOURCES_CLI})

# Set the directories that should be included in the build command for this target
target_include_directories(qt_puzzle
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(qt_puzzle_cli
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries( qt_puzzle_cli
    PRIVATE
        ncurses
)
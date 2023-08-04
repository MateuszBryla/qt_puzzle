# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.5)

# Set the project name and some of the useful variables
project (qt_puzzle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

# Find OpenCV package - used by the image interface
find_package(OpenCV REQUIRED)

# QT-related config
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Configuration for the initial, text-based version
set(SOURCES_CLI
    src/clipuzzle.cpp
    src/slidingpuzzle.cpp
    src/slidingpuzzletextif.cpp
)

add_executable(text_puzzle ${SOURCES_CLI})

target_include_directories(text_puzzle
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

# Configuration for the second version with OpenCV-based rough GUI
set(SOURCES_CV
    src/cvpuzzle.cpp
    src/slidingpuzzle.cpp
    src/slidingpuzzleimageif.cpp    
)

add_executable(cv_puzzle ${SOURCES_CV})

target_include_directories(cv_puzzle
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(cv_puzzle
    PRIVATE
        ${OpenCV_LIBS}
)

# Configuration for the final, QT-based version
set(SOURCES_QT
    src/main.cpp
    src/slidingpuzzle.cpp
    src/slidingpuzzlegui.cpp
    src/slidingpuzzleimageif.cpp
    src/clickablelabel.cpp
)

set(INCLUDES_QT
    include/slidingpuzzle.h
    include/slidingpuzzlegui.h
    include/slidingpuzzleimageif.h
    include/clickablelabel.h
)

add_executable(qt_puzzle ${SOURCES_QT} ${INCLUDES_QT})

target_include_directories(qt_puzzle
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(qt_puzzle
    PRIVATE
        ${OpenCV_LIBS}
        Qt5::Widgets
)
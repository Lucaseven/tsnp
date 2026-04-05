cmake_minimum_required(VERSION 3.16)
project(TSMP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(TSMP
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.h
    src/canvas/CanvasWidget.cpp
    src/canvas/CanvasWidget.h
)

target_link_libraries(TSMP PRIVATE Qt6::Core Qt6::Widgets)

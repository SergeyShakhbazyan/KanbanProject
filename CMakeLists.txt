cmake_minimum_required(VERSION 3.25)
project(KanbanProject)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "/Users/sergeyshakhbazyan/Desktop/6.6.1/macos")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(${Qt6Widgets_INCLUDE_DIRS})

add_executable(KanbanProject main.cpp include/CardWidget.h include/CardWidget.h src/CardWidget.cpp include/MainWindow.h include/KanbanColumn.h src/MainWindow.cpp src/KanbanColumn.cpp)

target_link_libraries(KanbanProject Qt6::Widgets)
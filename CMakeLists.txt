cmake_minimum_required(VERSION 3.6)
project(pioner)



set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH "/home/nikita/Qt5.7.0/5.7/gcc_64")
find_package(Qt5Widgets)


set(SOURCE_FILES main.cpp
        G_Based_Vert.cpp G_Based_Vert.h
        MainWindow.cpp MainWindow.h
        MyQGraphicsView.cpp MyQGraphicsView.h
        Graph.cpp Graph.h)

add_executable(pioner ${SOURCE_FILES})
target_link_libraries(pioner Qt5::Widgets)
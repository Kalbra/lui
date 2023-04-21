cmake_minimum_required(VERSION 3.25)
project(lui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(blocks STATIC
        Blocks/BaseOutputBlock.hpp
        Blocks/LcdNumberOutputBlock.hpp
        Blocks/MaleChannel.hpp
        Blocks/Channel.hpp
        Blocks/FemaleChannel.hpp
        Blocks/Connector.hpp
        Blocks/BaseInputBlock.h Blocks/SpinBoxInputBlock.h Blocks/BaseUpdate.h)

target_include_directories(blocks PUBLIC Blocks)
target_link_libraries(blocks PRIVATE Qt::Core Qt::Widgets)

add_library(project_file_io STATIC
        ProjectFileIO/ProjectFileIO.cpp
        ProjectFileIO/ProjectFileIO.h
        ProjectFileIO/PropertySet.cpp
        ProjectFileIO/PropertySet.h)

target_include_directories(project_file_io PUBLIC ProjectFileIO)
target_link_libraries(project_file_io PRIVATE Qt::Core Qt::Widgets)

add_executable(lui main.cpp mainwindow.cpp mainwindow.h mainframe.cpp mainframe.h newblock.cpp newblock.h newblock.ui)

target_link_libraries(lui
        Qt::Core
        Qt::Gui
        Qt::Widgets
        blocks
        project_file_io
        )

# Doxygen

cmake_minimum_required(VERSION 2.8)
project(miniProject)
set(CMAKE_CXX_STANDARD 14)
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTKMM REQUIRED gtkmm-3.0)
message(${GTKMM_INCLUDE_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTKMM_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTKMM_CFLAGS_OTHER})

add_executable(miniProject main.cpp characterClass.h ProjectClasses.cpp GUI.h GUI.cpp drawingPart.cpp GUIutils.cpp)


TARGET_LINK_LIBRARIES(miniProject ${GTKMM_LIBRARIES})
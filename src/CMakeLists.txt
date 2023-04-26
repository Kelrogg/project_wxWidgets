cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(wx_drawing_tutorial_core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# hack for buggy CMake's FindwxWidgets script
if (DEFINED ENV_WX_CONFIG)
    set (ENV{WX_CONFIG} ${ENV_WX_CONFIG})
endif()

set(wxWidgets_USE_STATIC 1)

find_package(wxWidgets REQUIRED)

file(GLOB_RECURSE all_srcs 
                Controller/*.cpp
                Model/*cpp
                View/*cpp
                pch.cpp
                main.cpp)
#file(GLOB RECURSE all_headers ../headers/*.hpp)
#set(SRCS main.cpp drawingcanvas.cpp pch.cpp)

include(${wxWidgets_USE_FILE})

if (APPLE)
    add_executable(main MACOSX_BUNDLE ${all_srcs} )
    set_target_properties(main PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()
    add_executable(main WIN32 ${all_srcs} main.exe.manifest)
endif()

target_link_libraries(main PRIVATE ${wxWidgets_LIBRARIES})

target_include_directories(main PUBLIC ../headers)
#target_include_directories(main PUBLIC ../headers/Model)
#target_include_directories(main PUBLIC ../headers/View)
#target_include_directories(main PUBLIC ../headers/Controller)

target_precompile_headers(main PUBLIC ../headers/pch.hpp)
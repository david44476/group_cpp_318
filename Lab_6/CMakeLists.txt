cmake_minimum_required(VERSION 3.16)

project(Lab_6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab_6 main.cpp
    errmess.h
    task_selection.cpp
    constans.h
    check_the_input.cpp
    check_the_input.h
    task_selection.h
    errmess.cpp
    stop.cpp
    stop.h

)

include(GNUInstallDirs)
install(TARGETS Lab_6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

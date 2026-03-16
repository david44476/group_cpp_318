cmake_minimum_required(VERSION 3.16)

project(Lab_6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab_6 main.cpp
    errmess.h
    constans.h


    errmess.cpp




    denamic_objects.cpp
    denamic_objects.h
    C_labWork.h
    C_labWork.cpp
    C_Bruteforce.cpp
    lab_6.cpp
    lab_work.h
)

include(GNUInstallDirs)
install(TARGETS Lab_6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

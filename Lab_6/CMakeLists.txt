cmake_minimum_required(VERSION 3.16)

project(Lab_6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab_6 main.cpp
    messout.h
    messout.cpp
    constans.h
    taskSel.cpp
    c_bruteforce.h
    c_bruteforce.cpp
    clearConsole.cpp
    myEmoji.h
    bruteforce.cpp
    taskStr.h
    checkInput.h
    checkInput.cpp
    exit.cpp
    c_palindrome.h
    c_palindrome.cpp
    palindrome.cpp
    c_car.h
    carBase.cpp
    c_car_driver.h
    c_trip.h
    c_dispatcher.h
    c_complexNum.h
    complexNum.cpp
    c_comlexNum.cpp






)

include(GNUInstallDirs)
install(TARGETS Lab_6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

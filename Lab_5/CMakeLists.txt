cmake_minimum_required(VERSION 3.16)

project(Lab_5 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Lab_5
  main.cpp
  constans.h
  continent.cpp
  continent.h
  new_view.cpp
  new_view.h
  stop.h
  task_1.cpp
  task_1.h
  template_functions.h
  type_thecking.cpp
  type_thecking.h
  stop.cpp
  string_packing.cpp
  string_packing.h
  task_5.cpp
  task_5.h
  array_of_str.cpp
  array_of_str.h
)

include(GNUInstallDirs)
install(TARGETS Lab_5
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

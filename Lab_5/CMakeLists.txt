cmake_minimum_required(VERSION 3.16)

project(Lab_5_1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Lab_5_1
  main.cpp
  constans.h
  stop.h
  task_1.cpp
  task_1.h
  new_view.cpp
  new_view.cpp
  new_view.h
  template_functions.h
  type_thecking.cpp
  continent.cpp
  continent.h
)
target_link_libraries(Lab_5_1 Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Lab_5_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

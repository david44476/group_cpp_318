QT += core
QT -= gui

CONFIG += c++11

TARGET = Lab_4
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    task_1.cpp \
    type_thecking.cpp \
    task_2.cpp \
    task_3.cpp \
    task_4.cpp \
    task_5.cpp \
    task_6.cpp \
    task_7.cpp \
    task_8.cpp \
    task_9.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    task_1.h \
    task_2.h \
    task_3.h \
    task_4.h \
    task_5.h \
    task_6.h \
    task_7.h \
    task_8.h \
    template_functions.h \
    type_thecking.h \
    matrix_func.h \
    task_9.h

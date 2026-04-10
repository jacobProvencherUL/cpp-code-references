# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = employeGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += employeCommissionUI.cpp employeGUI.cpp employeHoraireUI.cpp main.cpp patronUI.cpp
HEADERS += employeCommissionUI.h employeGUI.h employeHoraireUI.h patronUI.h
FORMS += employeCommissionUI.ui employeGUI.ui employeHoraireUI.ui patronUI.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++-10
DEFINES += 
INCLUDEPATH += ../source 
LIBS += ../source/dist/Debug/GNU-Linux/libsource.a  

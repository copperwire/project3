TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    celestialbody.cpp \
    solarsystem.cpp \
    euler.cpp \
    verlet.cpp \
    vec3.cpp
INCLUDEPATH += /usr/include

HEADERS += \
    celestialbody.h \
    solarsystem.h \
    euler.h \
    verlet.h \
    vec3.h

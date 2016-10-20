TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    celestialbody.cpp \
    solarsystem.cpp \
    euler.cpp \
    verlet.cpp
INCLUDEPATH += /usr/include

LIBS += -larmadillo -lblas -llapack

HEADERS += \
    celestialbody.h \
    solarsystem.h \
    euler.h \
    verlet.h

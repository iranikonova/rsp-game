TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    shape.cpp \
    gameengine.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    shape.h \
    gameengine.h


TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    shape.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    shape.h


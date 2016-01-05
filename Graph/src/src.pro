TARGET = graph
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ugraph.cpp \
    search.cpp \
    dgraph.cpp \
    graph.cpp \
    unionfind.cpp

HEADERS += \
    ugraph.h \
    search.h \
    dgraph.h \
    graph.h \
    unionfind.h


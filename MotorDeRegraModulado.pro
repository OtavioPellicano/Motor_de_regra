TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += main.cpp \
    pmt.cpp \
    logbox.cpp \
    paridadedownup.cpp \
    medicaocomfalha.cpp \
    avaliacaodasfalhas.cpp \
    pingbackdivergente.cpp \
    solucoeshomologadas.cpp

HEADERS += \
    pmt.h \
    logbox.h \
    paridadedownup.h \
    medicaocomfalha.h \
    avaliacaodasfalhas.h \
    pingbackdivergente.h \
    solucoeshomologadas.h

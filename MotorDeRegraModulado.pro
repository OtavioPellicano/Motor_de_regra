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
    solucoeshomologadas.cpp \
    pttnaocadastrado.cpp \
    avaliacaodostatus.cpp \
    validade.cpp \
    avaliacaodacpu.cpp \
    listadeexcecao.cpp \
    tabeladeassinantes.cpp \
    StringCsv.cpp \
    NormalizacaoDeDados.cpp \
    DePara.cpp \
    ModeloHardwareNaoCompativel.cpp \
    ExcecaoDeInfraestrutura.cpp

HEADERS += \
    pmt.h \
    logbox.h \
    paridadedownup.h \
    medicaocomfalha.h \
    avaliacaodasfalhas.h \
    pingbackdivergente.h \
    solucoeshomologadas.h \
    pttnaocadastrado.h \
    avaliacaodostatus.h \
    validade.h \
    avaliacaodacpu.h \
    listadeexcecao.h \
    tabeladeassinantes.h \
    StringCsv.h \
    NormalizacaoDeDados.h \
    DePara.h \
    ModeloHardwareNaoCompativel.h \
    ExcecaoDeInfraestrutura.h

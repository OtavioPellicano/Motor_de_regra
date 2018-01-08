#ifndef PMT_H
#define PMT_H
#include <iostream>
#include <string>
#include <algorithm>
#include <QDateTime>
#include <map>
#include <QTime>

namespace opmm {

using namespace std;
enum layout {ABR, TGR, NETMETRICS, SEMIGLOBE};
typedef map<string, short> mapStrSht;
typedef map<string, bool> mapStrBool;


class PMT
{

public: //Métodos Públicos
    PMT(string dataHoraRef, string ufServidor, string ufCliente, layout tipoLayout, QTime horaInicio = QTime(10,0,0),
        QTime horaFinal = QTime(22,0,0));

    bool medidaValidaPmt();

private: //Variaveis Privadas
    string mDataHoraRef;
    string mUfServidor;
    string mUfCliente;
    QDateTime mDataHoraNormalizada;

    layout mTipoLayout;
    QTime mHoraInicio;
    QTime mHoraFinal;

    bool flagHorarioVerao = false;

    mapStrSht mMapUfGmt = {
        {"AC", -5},
        {"AL", -3},
        {"AM", -4},
        {"AP", -3},
        {"BA", -3},
        {"CE", -3},
        {"DF", -3},
        {"ES", -3},
        {"GO", -3},
        {"MA", -3},
        {"MG", -3},
        {"MS", -4},
        {"MT", -4},
        {"PA", -3},
        {"PB", -3},
        {"PE", -3},
        {"PI", -3},
        {"PR", -3},
        {"RJ", -3},
        {"RN", -3},
        {"RO", -4},
        {"RR", -4},
        {"RS", -3},
        {"SC", -3},
        {"SE", -3},
        {"SP", -3},
        {"TO", -3}
    };

    mapStrSht mMapUfHorarioVerao
    {
        {"DF", 0},
        {"ES", 0},
        {"GO", 0},
        {"MG", 0},
        {"MS", 0},
        {"MT", 0},
        {"PR", 0},
        {"RJ", 0},
        {"RS", 0},
        {"SC", 0},
        {"SP", 0}
    };

private: //Métodos Privados
    string retirarAspas(const string &strIn);
    void normalizarDataHora();
    void atualizarTabelaHoraVerao();

};

}


#endif // PMT_H

#include <iostream>
#include "pmt.h"
#include <QTime>
#include <QDebug>


using namespace std;

int main()
{

    //SEMIGLOBE
    //string dataRef = "\"12/19/2017 03:00\"";    //SEMIGLOBE
    string dataRef = "\"2017-11-30 15:42:13\""; //TGR

    string ufCliente = "GO";
    string ufServidor = "AC";
    //opmm::layout tipoLayout = opmm::layout::SEMIGLOBE;
    opmm::layout tipoLayout = opmm::layout::TGR;

    opmm::PMT claro(dataRef, ufServidor, ufCliente, tipoLayout);

    if (claro.medidaValidaPmt())
    {
        qDebug() << "Dentro do PMT";
    }
    else
    {
        qDebug() << "Fora do PMT";
    }

    return 0;
}

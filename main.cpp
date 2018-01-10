#include <iostream>
#include "pmt.h"
#include <QTime>
#include <QDebug>
#include <logbox.h>
#include <paridadedownup.h>
#include <medicaocomfalha.h>
#include <avaliacaodasfalhas.h>

using namespace std;

int main()
{

    //SEMIGLOBE
    //string dataRef = "\"12/19/2017 03:00\"";    //SEMIGLOBE
    //string dataRef = "\"2017-11-30 15:42:13\""; //TGR
    //string dataRef = "08/01/2018 14:51:01"; //NETMETRICS
    string dataRef = "2018-01-04 23:58:08.446000"; //ABR


    string ufCliente = "GO";
    string ufServidor = "AC";
    //opmm::layout tipoLayout = opmm::layout::SEMIGLOBE;
    //opmm::layout tipoLayout = opmm::layout::TGR;
    //opmm::layout tipoLayout = opmm::layout::NETMETRICS;
    opmm::layout tipoLayout = opmm::layout::ABR;

    opmm::PMT prest(dataRef, ufServidor, ufCliente, tipoLayout);

    if (prest.medicaoValida())
    {
        qDebug() << "Dentro do PMT";
    }
    else
    {
        qDebug() << "Fora do PMT";
    }


    if (opmm::ParidadeDownUp("##", "3.543").medicaoValida())
    {
        qDebug() << "Paridade valida!";
    }
    else
    {
        qDebug() << "Paridade invalida!";
    }


    if(opmm::MedicaoComFalha("7.43").medicaoValida())
    {
        qDebug() << "Medicao valida!";
    }
    else
    {
        qDebug() << "Medicao invalida!";
    }

    if(opmm::AvaliacaoDasFalhas("1", "-2").medicaoValida())
    {
        qDebug() << "Avaliacao das falhas valida!";
    }
    else
    {
        qDebug() << "Avaliacao das falhas invalida!";
    }



    return 0;
}

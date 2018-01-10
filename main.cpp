#include <iostream>

#include <QTime>
#include <QDebug>
#include <vector>
#include <string>

#include "logbox.h"

#include "medicaocomfalha.h"        //#3
#include "avaliacaodasfalhas.h"     //#4
#include "paridadedownup.h"         //#6
#include "pmt.h"                    //#7
#include "pingbackdivergente.h"     //#8
#include "solucoeshomologadas.h"    //#9
#include "pttnaocadastrado.h"       //#26



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


    vector<string> ipsPrestados;
    ipsPrestados.push_back("192.168.1.1");
    ipsPrestados.push_back("192.168.1.2");
    ipsPrestados.push_back("192.168.1.3");
    ipsPrestados.push_back("192.168.1.4");
    ipsPrestados.push_back("192.168.1.5");

    if(opmm::PingBackDivergente("192.168.0.1",ipsPrestados).medicaoValida())
    {
        qDebug() << "Ping Back Convergente";
    }
    else
    {
        qDebug() << "Ping Back Divergente";
    }


    vector<string> listHomologados;
    listHomologados.push_back("3");
    listHomologados.push_back("5");
    listHomologados.push_back("7.43");


    if(opmm::SolucoesHomologadas("3",listHomologados).medicaoValida())
    {
        qDebug() << "Software Homologado";
    }
    else
    {
        qDebug() << "Software nao Homologado!";
    }


    vector<string> listPttCadastrado;
    listPttCadastrado.push_back("192.168.1.7");
    listPttCadastrado.push_back("192.168.1.5");
    listPttCadastrado.push_back("192.168.1.3");

    if(opmm::PttNaoCadastrado("192.168.1.5", listPttCadastrado).medicaoValida())
    {
        qDebug() << "Ptt cadastrado";
    }
    else
    {
        qDebug() << "Ptt nao cadastrado";
    }






    return 0;
}

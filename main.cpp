#include <iostream>

#include <QTime>
#include <QDebug>
#include <vector>
#include <string>
#include <fstream>

#include "logbox.h"

//Numeracao SCM
#include "medicaocomfalha.h"        //#3* SCM SMP
#include "avaliacaodasfalhas.h"     //#4 SCM
#include "paridadedownup.h"         //#6 SCM SMP
#include "pmt.h"                    //#7 SCM SMP
#include "pingbackdivergente.h"     //#8 SCM SMP
#include "solucoeshomologadas.h"    //#9 SCM
#include "tabeladeassinantes.h"     //#20 SCM
#include "listadeexcecao.h"         //#21 SCM SMP
#include "pttnaocadastrado.h"       //#26 SCM SMP

//Numeracao SMP
#include "avaliacaodostatus.h"      //#9 SMP
#include "avaliacaodacpu.h"         //#11 SMP


//Agrupado
#include "NormalizacaoDeDados.h"


using namespace std;

int main()
{

//    //SEMIGLOBE
//    //string dataRef = "\"12/19/2017 03:00\"";    //SEMIGLOBE
//    //string dataRef = "\"2017-11-30 15:42:13\""; //TGR
//    //string dataRef = "08/01/2018 14:51:01"; //NETMETRICS
//    string dataRef = "2018-01-04 23:58:08.446000"; //ABR


//    string ufCliente = "GO";
//    string ufServidor = "AC";
//    //opmm::layout tipoLayout = opmm::layout::SEMIGLOBE;
//    //opmm::layout tipoLayout = opmm::layout::TGR;
//    //opmm::layout tipoLayout = opmm::layout::NETMETRICS;
//    opmm::layout tipoLayout = opmm::layout::ABR;

//    opmm::PMT prest(dataRef, ufServidor, ufCliente, tipoLayout);

//    if (prest.medicaoValida())
//    {
//        qDebug() << "Dentro do PMT";
//    }
//    else
//    {
//        qDebug() << "Fora do PMT";
//    }


//    if (opmm::ParidadeDownUp("##", "3.543").medicaoValida())
//    {
//        qDebug() << "Paridade valida!";
//    }
//    else
//    {
//        qDebug() << "Paridade invalida!";
//    }


//    if(opmm::MedicaoComFalha("7.43").medicaoValida())
//    {
//        qDebug() << "Medicao valida!";
//    }
//    else
//    {
//        qDebug() << "Medicao invalida!";
//    }

//    if(opmm::AvaliacaoDasFalhas("1", "-2").medicaoValida())
//    {
//        qDebug() << "Avaliacao das falhas valida!";
//    }
//    else
//    {
//        qDebug() << "Avaliacao das falhas invalida!";
//    }


//    vector<string> ipsPrestados;
//    ipsPrestados.push_back("192.168.1.1");
//    ipsPrestados.push_back("192.168.1.2");
//    ipsPrestados.push_back("192.168.1.3");
//    ipsPrestados.push_back("192.168.1.4");
//    ipsPrestados.push_back("192.168.1.5");

//    if(opmm::PingBackDivergente("192.168.0.1",ipsPrestados).medicaoValida())
//    {
//        qDebug() << "Ping Back Convergente";
//    }
//    else
//    {
//        qDebug() << "Ping Back Divergente";
//    }


//    vector<string> listHomologados;
//    listHomologados.push_back("3");
//    listHomologados.push_back("5");
//    listHomologados.push_back("7.43");


//    if(opmm::SolucoesHomologadas("3",listHomologados).medicaoValida())
//    {
//        qDebug() << "Software Homologado";
//    }
//    else
//    {
//        qDebug() << "Software nao Homologado!";
//    }


//    vector<string> listPttCadastrado;
//    listPttCadastrado.push_back("192.168.1.7");
//    listPttCadastrado.push_back("192.168.1.5");
//    listPttCadastrado.push_back("192.168.1.3");

//    if(opmm::PttNaoCadastrado("192.168.1.5", listPttCadastrado).medicaoValida())
//    {
//        qDebug() << "Ptt cadastrado";
//    }
//    else
//    {
//        qDebug() << "Ptt nao cadastrado";
//    }


//    if(opmm::AvaliacaoDoStatus("Cancelled").medicaoValida())
//    {
//        qDebug() << "Status Ok";
//    }
//    else
//    {
//        qDebug() << "Status Nao Ok";
//    }


//    if(opmm::AvaliacaoDaCpu(".79",false).medicaoValida())
//    {
//        qDebug() << "Avaliacao da CPU OK!";
//    }
//    else
//    {
//        qDebug() << "Avaliacao da CPU ERRO!";
//    }


//    vector<string> listaExcecao;
//    listaExcecao.push_back("192.168.1.7");
//    listaExcecao.push_back("192.168.1.5");
//    listaExcecao.push_back("192.168.1.3");

//    if(opmm::ListaDeExcecao("192.168.1.8", listaExcecao).medicaoValida())
//    {
//        qDebug() << "(Lista de excecao) Medida NAO retirada";
//    }
//    else
//    {
//        qDebug() << "(Lista de excecao) Medida retirada";
//    }


//    vector<string> listaAssinantes;
//    listaAssinantes.push_back("otavio");
//    listaAssinantes.push_back("pellicano");


//    if(opmm::TabelaDeAssinantes("otavo", listaAssinantes).medicaoValida())
//    {
//        qDebug() << "(Tabela de Assinantes) encontrado!";
//    }
//    else
//    {
//        qDebug() << "(Tabela de Assinantes) NAO encontrado!";
//    }


  //  ifstream arqOrigem("C:/Users/otaviomello/Documents/ABRTELECOM/Qt Projects/ValidacaoRawData/MotorDeRegra_Modulado/Exemplo de arquivos/Tim-2017-12-01_05.csv");

//    ifstream arqOrigem("C:/Users/otaviomello/Documents/ABRTELECOM/Qt Projects/ValidacaoRawData/MotorDeRegra_Modulado/SCM_4_5/scm4_5_2018-01-01_00_00_01.csv");


    ifstream arqOrigem("C:/Users/otaviomello/Documents/ABRTELECOM/Qt Projects/ValidacaoRawData/MotorDeRegra_Modulado/carga_AJUDTCSRV04_2018-01-01-00-45-17.csv");

    string str;
    if (arqOrigem.is_open())
    {
        for(size_t i = 1; getline(arqOrigem, str); ++i )
        {
            opmm::NormalizacaoDeDados(str, opmm::layout::TGR, opmm::indicador::SCM_8);

        }

        arqOrigem.close();
    }
    else
    {
        cout << "Impossivel abrir o arquivo de origem" << endl;
    }




    return 0;
}

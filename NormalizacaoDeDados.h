#ifndef NormalizacaoDeDados_H
#define NormalizacaoDeDados_H

#include "validade.h"
#include <string>
#include "StringCsv.h"
#include <QDebug>
#include <map>

using namespace std;

typedef map<string, string> mapStrStr;


namespace opmm {
/**
 * @brief The NormalizacaoDeDados class
 * Classe utilizada para normalizar as entradas de diferentes tecnologias
 */

enum indicador{SCM_4, SCM_5, SCM_6, SCM_7, SCM_8, SCM_9, ASSINANTE};

class NormalizacaoDeDados : public Validade
{
    //Funções
public:
    NormalizacaoDeDados(const string &linhaArqCsv, const layout &tipoLayout, const indicador &ind);

private:

    std::string dateTime() const;
    void setDateTime(const std::string &dateTime);

    std::string speedDown() const;
    void setSpeedDown(const std::string &speedDown);

    std::string speedUp() const;
    void setSpeedUp(const std::string &speedUp);

    std::string medidaJitter() const;
    void setMedidaJitter(const std::string &medidaJitter);

    std::string medidaLatencia() const;
    void setMedidaLatencia(const std::string &medidaLatencia);

    string deciceID() const;
    void setDeciceID(const string &deciceID);

    string sourcerIPv4() const;
    void setSourcerIPv4(const string &sourcerIPv4);

    string macAddress() const;
    void setMacAddress(const string &macAddress);

    string manufacture() const;
    void setManufacture(const string &manufacture);

    string softwareVersion() const;
    void setSoftwareVersion(const string &softwareVersion);

    string testPoint() const;
    void setTestPoint(const string &testPoint);

    string availSuccesses() const;
    void setAvailSuccesses(const string &availSuccesses);

    string avgRtt() const;
    void setAvgRtt(const string &avgRtt);

    string jitter() const;
    void setJitter(const string &jitter);

    string packetLossFailure() const;
    void setPacketLossFailure(const string &packetLossFailure);

    string packetLossSuccesses() const;
    void setPacketLossSuccesses(const string &packetLossSuccesses);

    string retirarAspas(const string &strIn);


    //Variaveis
private:
    string mDateTime;           //Data e hora exata do inicio dos testes

    string mDeciceID;           //Identificador da sonda
    string mSourcerIPv4;        //Ultimo endereço IPv4 da fonte
    string mMacAddress;         //MAC address WAN da sonda
    string mManufacture;        //Nome do Vendor do Coletor
    string mSoftwareVersion;    //Versão do software da sonda
    string mTestPoint;          //Endereço IP ou hostname do servidor de teste

    string mSpeedUp;           //Velocidade de upload, quando calculada
    string mSpeedDown;         //Velocidade de download, quando calculada

    string mAvailSuccesses;     //Quantidade de testes de disponibilidade bem sucedidos

    string mAvgRtt;             //Media de round trip time (latencia)
    string mJitter;             //Variança padrão das latencias, quando calculada

    string mPacketLossFailure;  //Número de pacotes enviados com falha
    string mPacketLossSuccesses;//Número de pacotes enviados com sucesso



};



}


#endif // NormalizacaoDeDados_H

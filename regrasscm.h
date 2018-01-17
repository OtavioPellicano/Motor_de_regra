#ifndef REGRASSCM_H
#define REGRASSCM_H


#include "medicaocomfalha.h"        //#3* SCM SMP
#include "avaliacaodasfalhas.h"     //#4 SCM            //Nao é possível implementar ABR
#include "paridadedownup.h"         //#6 SCM SMP        //OK
#include "pmt.h"                    //#7 SCM SMP
#include "pingbackdivergente.h"     //#8 SCM SMP
#include "solucoeshomologadas.h"    //#9 SCM
#include "tabeladeassinantes.h"     //#20 SCM
#include "listadeexcecao.h"         //#21 SCM SMP
#include "pttnaocadastrado.h"       //#26 SCM SMP

#include <string>
#include "StringCsv.h"
#include <vector>

#include <QDir>
#include <QDebug>

typedef std::vector<std::string> vecStr;

namespace opmm {
/**
 * @brief The RegrasSCM class
 * Classe que agrupa todas as regras de SCM
 */

enum indicador{SCM_4, SCM_5, SCM_6, SCM_7, SCM_8, SCM_9};

class RegrasSCM
{
    //Funções
public:
    RegrasSCM(const string &linhaArqCsv, const layout &tipoLayout, const indicador &ind);

    //deviceid;timestamp;isp;type;manufacturer;model;software_version;ip_address;test_point;mem_total;mem_free;cpu_usage(%);os_version;os_type;battery_usage(%);cell_id;cell_id_changed;lac;tac;cgi/e-cgi;imei;imsi;network_type;signal_strength;roaming;wan_mode;network_type_changed;download_state;download_filesize_test(Bytes);download_rate(bps);upload_state;upload_filesize_test(Bytes);upload_rate(bps);udp_state;udp_estimated_triffc(Bytes);udp_latency(ms);udp_jitter(ms);udp_packet_loss_percent(%);total_traffic_sent;total_traffic_received;total_traffic;test_origin(APP|PROBE);source(Manual|Auto)


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


#endif // REGRASSCM_H

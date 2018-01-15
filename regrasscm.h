#ifndef REGRASSCM_H
#define REGRASSCM_H


#include "medicaocomfalha.h"        //#3* SCM SMP
#include "avaliacaodasfalhas.h"     //#4 SCM
#include "paridadedownup.h"         //#6 SCM SMP
#include "pmt.h"                    //#7 SCM SMP
#include "pingbackdivergente.h"     //#8 SCM SMP
#include "solucoeshomologadas.h"    //#9 SCM
#include "tabeladeassinantes.h"     //#20 SCM
#include "listadeexcecao.h"         //#21 SCM SMP
#include "pttnaocadastrado.h"       //#26 SCM SMP

#include <string>
#include "StringCsv.h"
#include <vector>

typedef std::vector<std::string> vecStr;

namespace opmm {
/**
 * @brief The RegrasSCM class
 * Classe que agrupa todas as regras de SCM
 */
class RegrasSCM : public Validade
{
    //Funções
public:
    RegrasSCM(const string &linhaArqCsv, const layout &tipoLayout);

    //deviceid;timestamp;isp;type;manufacturer;model;software_version;ip_address;test_point;mem_total;mem_free;cpu_usage(%);os_version;os_type;battery_usage(%);cell_id;cell_id_changed;lac;tac;cgi/e-cgi;imei;imsi;network_type;signal_strength;roaming;wan_mode;network_type_changed;download_state;download_filesize_test(Bytes);download_rate(bps);upload_state;upload_filesize_test(Bytes);upload_rate(bps);udp_state;udp_estimated_triffc(Bytes);udp_latency(ms);udp_jitter(ms);udp_packet_loss_percent(%);total_traffic_sent;total_traffic_received;total_traffic;test_origin(APP|PROBE);source(Manual|Auto)


    std::string dataHora() const;
    void setDataHora(const std::string &dataHora);

    std::string medidaDown() const;
    void setMedidaDown(const std::string &medidaDown);

    std::string medidaUp() const;
    void setMedidaUp(const std::string &medidaUp);

    std::string medidaJitter() const;
    void setMedidaJitter(const std::string &medidaJitter);

    std::string medidaLatencia() const;
    void setMedidaLatencia(const std::string &medidaLatencia);


private:

    vecStr pttsCadastrados() const;
    void setPttsCadastrados(const vecStr &pttsCadastrados);


    //Variaveis
private:
    std::string mDataHora;  //strCsv[1]
    std::string mMedidaDown;//strCsv[29]
    std::string mMedidaUp;  //strCsv[32]
    std::string mMedidaJitter;//strCsv[36]
    std::string mMedidaLatencia;//strCsv[35]
    std::string mPtt;


    vecStr mPttsCadastrados;

};



}


#endif // REGRASSCM_H

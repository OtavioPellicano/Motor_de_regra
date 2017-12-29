#include "pmt.h"

namespace opmm {



PMT::PMT(string dataHoraRef, string ufServidor, string ufCliente, layout tipoLayout)
    :mDataHoraRef(dataHoraRef), mUfServidor(ufServidor), mUfCliente(ufCliente), mTipoLayout(tipoLayout)
{
    normalizarDataHora();
}

string PMT::retirarAspas(const string &strIn)
{
    string strOut = strIn;
    strOut.erase(remove(strOut.begin(), strOut.end(), '\"'), strOut.end());

    return strOut;
}

/**
 * @brief PMT::normalizarDataHora
 * Normaliza a data para o modelo
 * coloca a data e hora para a referência do coletor
 *
 */
void PMT::normalizarDataHora()
{
    string dataHoraSemAspas = retirarAspas(mDataHoraRef);
    short inc =
            (mMapUfHorarioVerao.find(retirarAspas(mUfServidor)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfServidor)] + mMapUfHorarioVerao[retirarAspas(mUfServidor)] : mMapUfGmt[retirarAspas(mUfServidor)])
           - (mMapUfHorarioVerao.find(retirarAspas(mUfCliente)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfCliente)] + mMapUfHorarioVerao[retirarAspas(mUfCliente)] : mMapUfGmt[retirarAspas(mUfCliente)]);


    switch (mTipoLayout) {
    case ABR:

        break;
    case TGR:

        break;
    case NETMETRICS:

        break;
    case SEMIGLOBE: //MM/DD/AAAA HH:MM SEMIGLOBE

        if(dataHoraSemAspas.size() != 16)
        {
            cout << "Data fora do formato!" << endl;
        }
        else
        {
            int ano = stoi(string(dataHoraSemAspas,6,4));
            int mes = stoi(string(dataHoraSemAspas,0,2));
            int dia = stoi(string(dataHoraSemAspas,3,2));

            int hora = stoi(string(dataHoraSemAspas,11,2));
            int minuto = stoi(string(dataHoraSemAspas,14,2));
            int segundo = 0;

            mDataHoraNormalizada = QDateTime(QDate(ano, mes, dia),QTime(hora, minuto, segundo));

            //Add o incremento
            mDataHoraNormalizada = mDataHoraNormalizada.addSecs(inc*3600);
        }


        break;
    default:
        break;
    }


}

}

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


    switch (mTipoLayout) {
    case ABR:

        break;
    case TGR:   //AAAA-MM-DD HH:MM:SS

        if(dataHoraSemAspas.size() != 19)
        {
            cout << "Data fora do formato!" << endl;
        }
        else
        {
            int ano = stoi(string(dataHoraSemAspas,0,4));
            int mes = stoi(string(dataHoraSemAspas,5,2));
            int dia = stoi(string(dataHoraSemAspas,8,2));

            int hora = stoi(string(dataHoraSemAspas,11,2));
            int minuto = stoi(string(dataHoraSemAspas,14,2));
            int segundo = stoi(string(dataHoraSemAspas,17,2));

            mDataHoraNormalizada = QDateTime(QDate(ano, mes, dia),QTime(hora, minuto, segundo));

            atualizarTabelaHoraVerao();
            short inc =
                    (mMapUfHorarioVerao.find(retirarAspas(mUfServidor)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfServidor)] + mMapUfHorarioVerao[retirarAspas(mUfServidor)] : mMapUfGmt[retirarAspas(mUfServidor)])
                   - (mMapUfHorarioVerao.find(retirarAspas(mUfCliente)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfCliente)] + mMapUfHorarioVerao[retirarAspas(mUfCliente)] : mMapUfGmt[retirarAspas(mUfCliente)]);

            //Add o incremento
            mDataHoraNormalizada = mDataHoraNormalizada.addSecs(inc*3600);

        }

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

            atualizarTabelaHoraVerao();

            short inc =
                    (mMapUfHorarioVerao.find(retirarAspas(mUfServidor)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfServidor)] + mMapUfHorarioVerao[retirarAspas(mUfServidor)] : mMapUfGmt[retirarAspas(mUfServidor)])
                   - (mMapUfHorarioVerao.find(retirarAspas(mUfCliente)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfCliente)] + mMapUfHorarioVerao[retirarAspas(mUfCliente)] : mMapUfGmt[retirarAspas(mUfCliente)]);


            //Add o incremento
            mDataHoraNormalizada = mDataHoraNormalizada.addSecs(inc*3600);
        }


        break;
    default:
        break;
    }


}

/**
 * @brief PMT::atualizarTabelaHoraVerao
 * Faço a atualização em cima de data normalizada
 **/
void PMT::atualizarTabelaHoraVerao()
{
    if (mDataHoraNormalizada >= QDateTime(QDate(2017, 10, 15), QTime(0, 0, 0))
            && mDataHoraNormalizada <= QDateTime(QDate(2018, 2, 17), QTime(23, 59, 59)))
    {
        for (mapStrSht::iterator itMap = mMapUfHorarioVerao.begin(); itMap != mMapUfHorarioVerao.end(); ++itMap)
        {
            itMap->second = 1;
        }
    }
    else if (mDataHoraNormalizada >= QDateTime(QDate(2018, 10, 21), QTime(0, 0, 0))
             && mDataHoraNormalizada <= QDateTime(QDate(2019, 2, 16), QTime(23, 59, 59)))
    {
        for (mapStrSht::iterator itMap = mMapUfHorarioVerao.begin(); itMap != mMapUfHorarioVerao.end(); ++itMap)
        {
            itMap->second = 1;
        }
    }
    else
    {
        for (mapStrSht::iterator itMap = mMapUfHorarioVerao.begin(); itMap != mMapUfHorarioVerao.end(); ++itMap)
        {
            itMap->second = 0;
        }
    }
}

}

#include "pmt.h"

namespace opmm {

PMT::PMT(const string &dataHoraRef, const string &ufServidor, const string &ufCliente, const layout &tipoLayout, QTime horaInicio, QTime horaFinal)
    :mDataHoraRef(dataHoraRef), mUfServidor(ufServidor), mUfCliente(ufCliente), mTipoLayout(tipoLayout),
      mHoraInicio(horaInicio), mHoraFinal(horaFinal)
{

    if (mMapUfGmt.find(ufServidor) == mMapUfGmt.end())
    {
        setMedicaoValida(false);
        return;
    }

    if (mMapUfGmt.find(ufCliente) == mMapUfGmt.end())
    {
        setMedicaoValida(false);
        return;
    }

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
    int dia, mes, ano, hora, minuto, segundo;
    short inc;

    switch (mTipoLayout) {
    case ABR:   //AAAA-MM-DD HH:MM:SS.SSSSSS

        if(dataHoraSemAspas.size() != 26)
        {
            cout << "Data fora do formato!" << endl;
        }
        else
        {

            try
            {
                ano = stoi(string(dataHoraSemAspas,0,4));
                mes = stoi(string(dataHoraSemAspas,5,2));
                dia = stoi(string(dataHoraSemAspas,8,2));

                hora = stoi(string(dataHoraSemAspas,11,2));
                minuto = stoi(string(dataHoraSemAspas,14,2));
                segundo = stoi(string(dataHoraSemAspas,17,2));
            }
            catch(...)
            {
                ano = 1900;
                mes = 1;
                dia = 1;

                hora = 12;
                minuto = 0;
                segundo = 0;
            }

            mDataHoraNormalizada = QDateTime(QDate(ano, mes, dia),QTime(hora, minuto, segundo));

            atualizarTabelaHoraVerao();
            inc =
                    (mMapUfHorarioVerao.find(retirarAspas(mUfServidor)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfServidor)] + mMapUfHorarioVerao[retirarAspas(mUfServidor)] : mMapUfGmt[retirarAspas(mUfServidor)])
                   - (mMapUfHorarioVerao.find(retirarAspas(mUfCliente)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfCliente)] + mMapUfHorarioVerao[retirarAspas(mUfCliente)] : mMapUfGmt[retirarAspas(mUfCliente)]);

            //Add o incremento
            mDataHoraNormalizada = mDataHoraNormalizada.addSecs(inc*3600);
        }

        break;
    case TGR:   //AAAA-MM-DD HH:MM:SS
    case HDM:
        if(dataHoraSemAspas.size() != 19)
        {
            cout << "Data fora do formato!" << endl;
        }
        else
        {

            try
            {
                ano = stoi(string(dataHoraSemAspas,0,4));
                mes = stoi(string(dataHoraSemAspas,5,2));
                dia = stoi(string(dataHoraSemAspas,8,2));

                hora = stoi(string(dataHoraSemAspas,11,2));
                minuto = stoi(string(dataHoraSemAspas,14,2));
                segundo = stoi(string(dataHoraSemAspas,17,2));
            }
            catch(...)
            {
                ano = 1900;
                mes = 1;
                dia = 1;

                hora = 12;
                minuto = 0;
                segundo = 0;
            }

            mDataHoraNormalizada = QDateTime(QDate(ano, mes, dia),QTime(hora, minuto, segundo));

            atualizarTabelaHoraVerao();

            inc =
                    (mMapUfHorarioVerao.find(retirarAspas(mUfServidor)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfServidor)] + mMapUfHorarioVerao[retirarAspas(mUfServidor)] : mMapUfGmt[retirarAspas(mUfServidor)])
                   - (mMapUfHorarioVerao.find(retirarAspas(mUfCliente)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfCliente)] + mMapUfHorarioVerao[retirarAspas(mUfCliente)] : mMapUfGmt[retirarAspas(mUfCliente)]);

            //Add o incremento
            mDataHoraNormalizada = mDataHoraNormalizada.addSecs(inc*3600);

        }

        break;
    case NETMETRICS: //DD/MM/AAAA HH:MM:SS


        if(dataHoraSemAspas.size() != 19)
        {
            cout << "Data fora do formato!";
        }
        else
        {
            try
            {
                ano = stoi(string(dataHoraSemAspas,6,4));
                mes = stoi(string(dataHoraSemAspas,3,2));
                dia = stoi(string(dataHoraSemAspas,0,2));

                hora = stoi(string(dataHoraSemAspas,11,2));
                minuto = stoi(string(dataHoraSemAspas,14,2));
                segundo = stoi(string(dataHoraSemAspas,17,2));
            }
            catch(...)
            {
                ano = 1900;
                mes = 1;
                dia = 1;

                hora = 12;
                minuto = 0;
                segundo = 0;
            }

            mDataHoraNormalizada = QDateTime(QDate(ano, mes, dia),QTime(hora, minuto, segundo));

            atualizarTabelaHoraVerao();

            inc =
                    (mMapUfHorarioVerao.find(retirarAspas(mUfServidor)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfServidor)] + mMapUfHorarioVerao[retirarAspas(mUfServidor)] : mMapUfGmt[retirarAspas(mUfServidor)])
                   - (mMapUfHorarioVerao.find(retirarAspas(mUfCliente)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfCliente)] + mMapUfHorarioVerao[retirarAspas(mUfCliente)] : mMapUfGmt[retirarAspas(mUfCliente)]);


            //Add o incremento
            mDataHoraNormalizada = mDataHoraNormalizada.addSecs(inc*3600);
        }

        break;
    case SEMIGLOBE: //MM/DD/AAAA HH:MM SEMIGLOBE

        if(dataHoraSemAspas.size() != 16)
        {
            cout << "Data fora do formato!" << endl;
        }
        else
        {

            try
            {
                ano = stoi(string(dataHoraSemAspas,6,4));
                mes = stoi(string(dataHoraSemAspas,0,2));
                dia = stoi(string(dataHoraSemAspas,3,2));

                hora = stoi(string(dataHoraSemAspas,11,2));
                minuto = stoi(string(dataHoraSemAspas,14,2));
                segundo = 0;
            }
            catch(...)
            {
                ano = 1900;
                mes = 1;
                dia = 1;

                hora = 12;
                minuto = 0;
                segundo = 0;
            }

            mDataHoraNormalizada = QDateTime(QDate(ano, mes, dia),QTime(hora, minuto, segundo));

            atualizarTabelaHoraVerao();

            inc =
                    (mMapUfHorarioVerao.find(retirarAspas(mUfServidor)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfServidor)] + mMapUfHorarioVerao[retirarAspas(mUfServidor)] : mMapUfGmt[retirarAspas(mUfServidor)])
                   - (mMapUfHorarioVerao.find(retirarAspas(mUfCliente)) != mMapUfHorarioVerao.end() ? mMapUfGmt[retirarAspas(mUfCliente)] + mMapUfHorarioVerao[retirarAspas(mUfCliente)] : mMapUfGmt[retirarAspas(mUfCliente)]);


            //Add o incremento
            mDataHoraNormalizada = mDataHoraNormalizada.addSecs(inc*3600);
        }

        break;
    default:
        break;
    }


    if((mDataHoraNormalizada.time() >= mHoraInicio && mDataHoraNormalizada.time() <= mHoraFinal) && (mDataHoraNormalizada.date() != QDate(1900,1,1)))
    {
        setMedicaoValida(true);
    }
    else
    {
        setMedicaoValida(false);
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


    //Horario de verao de Londres
    if (mDataHoraNormalizada >= QDateTime(QDate(2017, 3, 26), QTime(1, 0, 0))
            && mDataHoraNormalizada <= QDateTime(QDate(2017, 10, 29), QTime(2, 0, 0)))
    {
        mMapUfHorarioVerao["LD"] = 1;
    }
    else if (mDataHoraNormalizada >= QDateTime(QDate(2018, 3, 25), QTime(1, 0, 0))
            && mDataHoraNormalizada <= QDateTime(QDate(2018, 10, 28), QTime(2, 0, 0)))
    {
        mMapUfHorarioVerao["LD"] = 1;
    }
    else if (mDataHoraNormalizada >= QDateTime(QDate(2019, 3, 31), QTime(1, 0, 0))
            && mDataHoraNormalizada <= QDateTime(QDate(2019, 10, 27), QTime(2, 0, 0)))
    {
        mMapUfHorarioVerao["LD"] = 1;
    }
    else
    {
        mMapUfHorarioVerao["LD"] = 0;
    }


}

}



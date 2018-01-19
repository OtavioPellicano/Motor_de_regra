#include "NormalizacaoDeDados.h"

namespace opmm {

NormalizacaoDeDados::NormalizacaoDeDados(const string &linhaArqCsv, const layout &tipoLayout, const indicador &ind)
{

    if(tipoLayout == ABR)
    {

        setDateTimeStr(StringCsv(linhaArqCsv).getStrItemStringSplitted(1));
        setDateTimeQt(dateTimeStr(), tipoLayout);
        setSpeedDown(StringCsv(linhaArqCsv).getStrItemStringSplitted(29));
        setSpeedUp(StringCsv(linhaArqCsv).getStrItemStringSplitted(32));
        setJitter(StringCsv(linhaArqCsv).getStrItemStringSplitted(36));
        setAvgRtt(StringCsv(linhaArqCsv).getStrItemStringSplitted(35));
    }
    else if(tipoLayout == HDM)
    {
        //geral
        setDateTimeStr(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(0));
        setDateTimeQt(dateTimeStr(), tipoLayout);
        setDeciceID(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(6));
        setSourcerIPv4(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(10));
        setMacAddress(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(9));
        setManufacture(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(12));
        setSoftwareVersion(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(11));

        switch (ind) {
        case SCM_4:
        case SCM_5:
            //scm4_5
            setTestPoint(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(23));
            setSpeedDown(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(46));
            setSpeedUp(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(47));

            break;
        case SCM_6:
            //scm6_7
            setAvgRtt(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(23));
            setTestPoint(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(19));

            break;
        case SCM_7:
            //scm6_7
            setJitter(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(26));
            setTestPoint(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(19));

            break;
        case SCM_8:
            //scm8
            setPacketLossFailure(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(22));
            setPacketLossSuccesses(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(23));
            setTestPoint(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(19));

            break;

        case SCM_9:
            //scm4_5
            setAvailSuccesses(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(29));
            setTestPoint(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(23));

            break;
        default:
            qDebug() << "Indicador Invalido!";
            break;
        }

    }
    else if(tipoLayout == TGR)
    {

        double perdaTotalRtt;
        double packetLoss;
        double packetSuccesses;
        string temp;

        //geral
        setDateTimeStr(StringCsv(linhaArqCsv).getStrItemStringSplitted(0));
        setDateTimeQt(dateTimeStr(), tipoLayout);
        setDeciceID(StringCsv(linhaArqCsv).getStrItemStringSplitted(5));
        setSourcerIPv4(StringCsv(linhaArqCsv).getStrItemStringSplitted(4));
        setMacAddress(StringCsv(linhaArqCsv).getStrItemStringSplitted(5));
        setTestPoint(StringCsv(linhaArqCsv).getStrItemStringSplitted(2));
        setSoftwareVersion(StringCsv(linhaArqCsv).getStrItemStringSplitted(1));

        switch (ind) {
        case SCM_4:
        case SCM_5:
            setSpeedDown(StringCsv(linhaArqCsv).getStrItemStringSplitted(25));
            setSpeedUp(StringCsv(linhaArqCsv).getStrItemStringSplitted(35));

            break;
        case SCM_6:
            setAvgRtt(StringCsv(linhaArqCsv).getStrItemStringSplitted(15));

            break;
        case SCM_7:
            //scm6_7
            setJitter(StringCsv(linhaArqCsv).getStrItemStringSplitted(20));

            break;
        case SCM_8:
            //scm8

            try {
                temp = retirarAspas(StringCsv(linhaArqCsv).getStrItemStringSplitted(45));
                replace(temp.begin(),temp.end(),',','.');
                perdaTotalRtt = stod(temp);
                packetLoss = perdaTotalRtt*100;
                packetSuccesses = 100 - (perdaTotalRtt*100);

                setPacketLossFailure(to_string(packetLoss));
                setPacketLossSuccesses(to_string(packetSuccesses));

            } catch (...) {
                setPacketLossFailure("$PI$");
                setPacketLossSuccesses("$PI$");
            }

            break;
        case SCM_9:
            setAvailSuccesses(StringCsv(linhaArqCsv).getStrItemStringSplitted(71));
            break;

        case ASSINANTE:
            setManufacture(StringCsv(linhaArqCsv).getStrItemStringSplitted(22));
            break;

        default:
            qDebug() << "Indicador Invalido!";
            break;
        }

    }
    else
    {

    }



}

std::string NormalizacaoDeDados::dateTimeStr() const
{
    return mDateTimeStr;
}

void NormalizacaoDeDados::setDateTimeStr(const std::string &dataHora)
{
    mDateTimeStr = retirarAspas(dataHora);
}

std::string NormalizacaoDeDados::speedDown() const
{
    return mSpeedDown;
}

void NormalizacaoDeDados::setSpeedDown(const std::string &medidaDown)
{
    mSpeedDown = retirarAspas(medidaDown);
    replace(mSpeedDown.begin(), mSpeedDown.end(), ',', '.');
}

std::string NormalizacaoDeDados::speedUp() const
{
    return mSpeedUp;
}

void NormalizacaoDeDados::setSpeedUp(const std::string &medidaUp)
{
    mSpeedUp = retirarAspas(medidaUp);
    replace(mSpeedUp.begin(), mSpeedUp.end(), ',', '.');
}


string NormalizacaoDeDados::deciceID() const
{
    return mDeciceID;
}

void NormalizacaoDeDados::setDeciceID(const string &deciceID)
{
    mDeciceID = retirarAspas(deciceID);
}

string NormalizacaoDeDados::sourcerIPv4() const
{
    return mSourcerIPv4;
}

void NormalizacaoDeDados::setSourcerIPv4(const string &sourcerIPv4)
{
    mSourcerIPv4 = retirarAspas(sourcerIPv4);
}

string NormalizacaoDeDados::macAddress() const
{
    return mMacAddress;
}

void NormalizacaoDeDados::setMacAddress(const string &macAddress)
{
    mMacAddress = retirarAspas(macAddress);
}

string NormalizacaoDeDados::manufacture() const
{
    return mManufacture;
}

void NormalizacaoDeDados::setManufacture(const string &manufacture)
{
    mManufacture = retirarAspas(manufacture);
}

string NormalizacaoDeDados::softwareVersion() const
{
    return mSoftwareVersion;
}

void NormalizacaoDeDados::setSoftwareVersion(const string &softwareVersion)
{
    mSoftwareVersion = retirarAspas(softwareVersion);
}

string NormalizacaoDeDados::availSuccesses() const
{
    return mAvailSuccesses;
}

void NormalizacaoDeDados::setAvailSuccesses(const string &availSuccesses)
{
    mAvailSuccesses = retirarAspas(availSuccesses);
}



string NormalizacaoDeDados::avgRtt() const
{
    return mAvgRtt;
}

void NormalizacaoDeDados::setAvgRtt(const string &avgRtt)
{
    mAvgRtt = retirarAspas(avgRtt);
    replace(mAvgRtt.begin(), mAvgRtt.end(), ',', '.');
}

string NormalizacaoDeDados::jitter() const
{
    return mJitter;
}

void NormalizacaoDeDados::setJitter(const string &jitter)
{
    mJitter = retirarAspas(jitter);
    replace(mJitter.begin(), mJitter.end(), ',', '.');
}

string NormalizacaoDeDados::packetLossSuccesses() const
{
    return mPacketLossSuccesses;
}

void NormalizacaoDeDados::setPacketLossSuccesses(const string &packetLossSuccesses)
{
    mPacketLossSuccesses = retirarAspas(packetLossSuccesses);
}

string NormalizacaoDeDados::packetLossFailure() const
{
    return mPacketLossFailure;
}

void NormalizacaoDeDados::setPacketLossFailure(const string &packetLossFailure)
{
    mPacketLossFailure = retirarAspas(packetLossFailure);
}

string NormalizacaoDeDados::testPoint() const
{
    return mTestPoint;
}

void NormalizacaoDeDados::setTestPoint(const string &testPoint)
{
    mTestPoint = retirarAspas(testPoint);
}

string NormalizacaoDeDados::retirarAspas(const string &strIn)
{
    string strOut = strIn;
    strOut.erase(remove(strOut.begin(), strOut.end(), '\"'), strOut.end());

    return strOut;
}

QDateTime NormalizacaoDeDados::dateTimeQt() const
{
    return mDateTimeQt;
}

void NormalizacaoDeDados::setDateTimeQt(const string &dateTimeStr, const layout &tipoLayout)
{

    int dia, mes, ano, hora, minuto, segundo;

    switch (tipoLayout) {
    case ABR:   //AAAA-MM-DD HH:MM:SS.SSSSSS

        if(dateTimeStr.size() != 26)
        {
            cout << "Data fora do formato!" << endl;
            mDateTimeQt = QDateTime(QDate(1900, 1, 1),QTime(12, 0, 0));
        }
        else
        {

            try
            {
                ano = stoi(string(dateTimeStr,0,4));
                mes = stoi(string(dateTimeStr,5,2));
                dia = stoi(string(dateTimeStr,8,2));

                hora = stoi(string(dateTimeStr,11,2));
                minuto = stoi(string(dateTimeStr,14,2));
                segundo = stoi(string(dateTimeStr,17,2));
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

            mDateTimeQt = QDateTime(QDate(ano, mes, dia),QTime(hora, minuto, segundo));

        }

        break;
    case TGR:   //AAAA-MM-DD HH:MM:SS
    case HDM:
        if(dateTimeStr.size() != 19)
        {
            cout << "Data fora do formato!" << endl;
            mDateTimeQt = QDateTime(QDate(1900, 1, 1),QTime(12, 0, 0));
        }
        else
        {

            try
            {
                ano = stoi(string(dateTimeStr,0,4));
                mes = stoi(string(dateTimeStr,5,2));
                dia = stoi(string(dateTimeStr,8,2));

                hora = stoi(string(dateTimeStr,11,2));
                minuto = stoi(string(dateTimeStr,14,2));
                segundo = stoi(string(dateTimeStr,17,2));
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

            mDateTimeQt = QDateTime(QDate(ano, mes, dia),QTime(hora, minuto, segundo));

        }

        break;
    case NETMETRICS: //DD/MM/AAAA HH:MM:SS


        if(dateTimeStr.size() != 19)
        {
            cout << "Data fora do formato!" << endl;
            mDateTimeQt = QDateTime(QDate(1900, 1, 1),QTime(12, 0, 0));
        }
        else
        {
            try
            {
                ano = stoi(string(dateTimeStr,6,4));
                mes = stoi(string(dateTimeStr,3,2));
                dia = stoi(string(dateTimeStr,0,2));

                hora = stoi(string(dateTimeStr,11,2));
                minuto = stoi(string(dateTimeStr,14,2));
                segundo = stoi(string(dateTimeStr,17,2));
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

            mDateTimeQt = QDateTime(QDate(ano, mes, dia),QTime(hora, minuto, segundo));


        }

        break;
    case SEMIGLOBE: //MM/DD/AAAA HH:MM SEMIGLOBE

        if(dateTimeStr.size() != 16)
        {
            cout << "Data fora do formato!" << endl;
            mDateTimeQt = QDateTime(QDate(1900, 1, 1),QTime(12, 0, 0));
        }
        else
        {

            try
            {
                ano = stoi(string(dateTimeStr,6,4));
                mes = stoi(string(dateTimeStr,0,2));
                dia = stoi(string(dateTimeStr,3,2));

                hora = stoi(string(dateTimeStr,11,2));
                minuto = stoi(string(dateTimeStr,14,2));
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

            mDateTimeQt = QDateTime(QDate(ano, mes, dia),QTime(hora, minuto, segundo));

        }

        break;
    default:
        mDateTimeQt = QDateTime(QDate(1900, 1, 1),QTime(12, 0, 0));
        cout << "ERRO NO LAYOUT!!!" << endl;
        break;
    }


}




}

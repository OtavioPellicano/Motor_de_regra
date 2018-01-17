#include "NormalizacaoDeDados.h"

namespace opmm {

NormalizacaoDeDados::NormalizacaoDeDados(const string &linhaArqCsv, const layout &tipoLayout, const indicador &ind)
{



    if(tipoLayout == ABR)
    {

        setDateTime(StringCsv(linhaArqCsv).getStrItemStringSplitted(1));
        setSpeedDown(StringCsv(linhaArqCsv).getStrItemStringSplitted(29));
        setSpeedUp(StringCsv(linhaArqCsv).getStrItemStringSplitted(32));
        setJitter(StringCsv(linhaArqCsv).getStrItemStringSplitted(36));
        setAvgRtt(StringCsv(linhaArqCsv).getStrItemStringSplitted(35));
    }
    else if(tipoLayout == HDM)
    {
        //geral
        setDateTime(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(0));
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

            break;
        case SCM_7:
            //scm6_7
            setJitter(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(26));

            break;
        case SCM_8:
            //scm8
            setPacketLossFailure(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(22));
            setPacketLossSuccesses(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(23));

        case SCM_9:
            //scm4_5
            setAvailSuccesses(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(29));

            break;
        default:
            qDebug() << "Indicador Invalido!";
            break;
        }

    }
    else if(tipoLayout == TGR)
    {

    }
    else
    {

    }



}

std::string NormalizacaoDeDados::dateTime() const
{
    return mDateTime;
}

void NormalizacaoDeDados::setDateTime(const std::string &dataHora)
{
    mDateTime = dataHora;
}

std::string NormalizacaoDeDados::speedDown() const
{
    return mSpeedDown;
}

void NormalizacaoDeDados::setSpeedDown(const std::string &medidaDown)
{
    mSpeedDown = medidaDown;
    replace(mSpeedDown.begin(), mSpeedDown.end(), ',', '.');
}

std::string NormalizacaoDeDados::speedUp() const
{
    return mSpeedUp;
}

void NormalizacaoDeDados::setSpeedUp(const std::string &medidaUp)
{
    mSpeedUp = medidaUp;
    replace(mSpeedUp.begin(), mSpeedUp.end(), ',', '.');
}


string NormalizacaoDeDados::deciceID() const
{
    return mDeciceID;
}

void NormalizacaoDeDados::setDeciceID(const string &deciceID)
{
    mDeciceID = deciceID;
}

string NormalizacaoDeDados::sourcerIPv4() const
{
    return mSourcerIPv4;
}

void NormalizacaoDeDados::setSourcerIPv4(const string &sourcerIPv4)
{
    mSourcerIPv4 = sourcerIPv4;
}

string NormalizacaoDeDados::macAddress() const
{
    return mMacAddress;
}

void NormalizacaoDeDados::setMacAddress(const string &macAddress)
{
    mMacAddress = macAddress;
}

string NormalizacaoDeDados::manufacture() const
{
    return mManufacture;
}

void NormalizacaoDeDados::setManufacture(const string &manufacture)
{
    mManufacture = manufacture;
}

string NormalizacaoDeDados::softwareVersion() const
{
    return mSoftwareVersion;
}

void NormalizacaoDeDados::setSoftwareVersion(const string &softwareVersion)
{
    mSoftwareVersion = softwareVersion;
}

string NormalizacaoDeDados::availSuccesses() const
{
    return mAvailSuccesses;
}

void NormalizacaoDeDados::setAvailSuccesses(const string &availSuccesses)
{
    mAvailSuccesses = availSuccesses;
}



string NormalizacaoDeDados::avgRtt() const
{
    return mAvgRtt;
}

void NormalizacaoDeDados::setAvgRtt(const string &avgRtt)
{
    mAvgRtt = avgRtt;
    replace(mAvgRtt.begin(), mAvgRtt.end(), ',', '.');
}

string NormalizacaoDeDados::jitter() const
{
    return mJitter;
}

void NormalizacaoDeDados::setJitter(const string &jitter)
{
    mJitter = jitter;
    replace(mJitter.begin(), mJitter.end(), ',', '.');
}

string NormalizacaoDeDados::packetLossSuccesses() const
{
    return mPacketLossSuccesses;
}

void NormalizacaoDeDados::setPacketLossSuccesses(const string &packetLossSuccesses)
{
    mPacketLossSuccesses = packetLossSuccesses;
}

string NormalizacaoDeDados::packetLossFailure() const
{
    return mPacketLossFailure;
}

void NormalizacaoDeDados::setPacketLossFailure(const string &packetLossFailure)
{
    mPacketLossFailure = packetLossFailure;
}

string NormalizacaoDeDados::testPoint() const
{
    return mTestPoint;
}

void NormalizacaoDeDados::setTestPoint(const string &testPoint)
{
    mTestPoint = testPoint;
}




}

#include "regrasscm.h"

namespace opmm {

RegrasSCM::RegrasSCM(const string &linhaArqCsv, const layout &tipoLayout, const indicador &ind)
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

std::string RegrasSCM::dateTime() const
{
    return mDateTime;
}

void RegrasSCM::setDateTime(const std::string &dataHora)
{
    mDateTime = dataHora;
}

std::string RegrasSCM::speedDown() const
{
    return mSpeedDown;
}

void RegrasSCM::setSpeedDown(const std::string &medidaDown)
{
    mSpeedDown = medidaDown;
    replace(mSpeedDown.begin(), mSpeedDown.end(), ',', '.');
}

std::string RegrasSCM::speedUp() const
{
    return mSpeedUp;
}

void RegrasSCM::setSpeedUp(const std::string &medidaUp)
{
    mSpeedUp = medidaUp;
    replace(mSpeedUp.begin(), mSpeedUp.end(), ',', '.');
}


string RegrasSCM::deciceID() const
{
    return mDeciceID;
}

void RegrasSCM::setDeciceID(const string &deciceID)
{
    mDeciceID = deciceID;
}

string RegrasSCM::sourcerIPv4() const
{
    return mSourcerIPv4;
}

void RegrasSCM::setSourcerIPv4(const string &sourcerIPv4)
{
    mSourcerIPv4 = sourcerIPv4;
}

string RegrasSCM::macAddress() const
{
    return mMacAddress;
}

void RegrasSCM::setMacAddress(const string &macAddress)
{
    mMacAddress = macAddress;
}

string RegrasSCM::manufacture() const
{
    return mManufacture;
}

void RegrasSCM::setManufacture(const string &manufacture)
{
    mManufacture = manufacture;
}

string RegrasSCM::softwareVersion() const
{
    return mSoftwareVersion;
}

void RegrasSCM::setSoftwareVersion(const string &softwareVersion)
{
    mSoftwareVersion = softwareVersion;
}

string RegrasSCM::availSuccesses() const
{
    return mAvailSuccesses;
}

void RegrasSCM::setAvailSuccesses(const string &availSuccesses)
{
    mAvailSuccesses = availSuccesses;
}



string RegrasSCM::avgRtt() const
{
    return mAvgRtt;
}

void RegrasSCM::setAvgRtt(const string &avgRtt)
{
    mAvgRtt = avgRtt;
    replace(mAvgRtt.begin(), mAvgRtt.end(), ',', '.');
}

string RegrasSCM::jitter() const
{
    return mJitter;
}

void RegrasSCM::setJitter(const string &jitter)
{
    mJitter = jitter;
    replace(mJitter.begin(), mJitter.end(), ',', '.');
}

string RegrasSCM::packetLossSuccesses() const
{
    return mPacketLossSuccesses;
}

void RegrasSCM::setPacketLossSuccesses(const string &packetLossSuccesses)
{
    mPacketLossSuccesses = packetLossSuccesses;
}

string RegrasSCM::packetLossFailure() const
{
    return mPacketLossFailure;
}

void RegrasSCM::setPacketLossFailure(const string &packetLossFailure)
{
    mPacketLossFailure = packetLossFailure;
}

string RegrasSCM::testPoint() const
{
    return mTestPoint;
}

void RegrasSCM::setTestPoint(const string &testPoint)
{
    mTestPoint = testPoint;
}




}

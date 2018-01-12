#include "regrasscm.h"

namespace opmm {

RegrasSCM::RegrasSCM(const string &linhaArqCsv, const layout &tipoLayout)
{

    if(tipoLayout == ABR)
    {
        setDataHora(StringCsv(linhaArqCsv).getStrItemStringSplitted(1));
        setMedidaDown(StringCsv(linhaArqCsv).getStrItemStringSplitted(29));
        setMedidaUp(StringCsv(linhaArqCsv).getStrItemStringSplitted(32));
        setMedidaJitter(StringCsv(linhaArqCsv).getStrItemStringSplitted(36));
        setMedidaLatencia(StringCsv(linhaArqCsv).getStrItemStringSplitted(35));
    }


}

std::string RegrasSCM::dataHora() const
{
    return mDataHora;
}

void RegrasSCM::setDataHora(const std::string &dataHora)
{
    mDataHora = dataHora;
}

std::string RegrasSCM::medidaDown() const
{
    return mMedidaDown;
}

void RegrasSCM::setMedidaDown(const std::string &medidaDown)
{
    mMedidaDown = medidaDown;
}

std::string RegrasSCM::medidaUp() const
{
    return mMedidaUp;
}

void RegrasSCM::setMedidaUp(const std::string &medidaUp)
{
    mMedidaUp = medidaUp;
}

std::string RegrasSCM::medidaJitter() const
{
    return mMedidaJitter;
}

void RegrasSCM::setMedidaJitter(const std::string &medidaJitter)
{
    mMedidaJitter = medidaJitter;
}

std::string RegrasSCM::medidaLatencia() const
{
    return mMedidaLatencia;
}

void RegrasSCM::setMedidaLatencia(const std::string &medidaLatencia)
{
    mMedidaLatencia = medidaLatencia;
}


}

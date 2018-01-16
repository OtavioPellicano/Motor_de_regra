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
    else if(tipoLayout == HDM)
    {
        setDataHora(StringCsv(linhaArqCsv,",").getStrItemStringSplitted(0));
    }
    else
    {

    }


    //Ordem de validação
    if (!ParidadeDownUp(medidaDown(), medidaUp()).medicaoValida())
    {
        RegrasSCM::setMedicaoValida(false);
        return;
    }

    RegrasSCM::setMedicaoValida(true);


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
    replace(mMedidaDown.begin(), mMedidaDown.end(), ',', '.');
}

std::string RegrasSCM::medidaUp() const
{
    return mMedidaUp;
}

void RegrasSCM::setMedidaUp(const std::string &medidaUp)
{
    mMedidaUp = medidaUp;
    replace(mMedidaUp.begin(), mMedidaUp.end(), ',', '.');
}

std::string RegrasSCM::medidaJitter() const
{
    return mMedidaJitter;
}

void RegrasSCM::setMedidaJitter(const std::string &medidaJitter)
{
    mMedidaJitter = medidaJitter;
    replace(mMedidaJitter.begin(), mMedidaJitter.end(), ',', '.');
}

std::string RegrasSCM::medidaLatencia() const
{
    return mMedidaLatencia;
}

void RegrasSCM::setMedidaLatencia(const std::string &medidaLatencia)
{
    mMedidaLatencia = medidaLatencia;
    replace(mMedidaLatencia.begin(), mMedidaLatencia.end(), ',', '.');
}

vecStr RegrasSCM::pttsCadastrados() const
{
    return mPttsCadastrados;
}

void RegrasSCM::setPttsCadastrados(const vecStr &pttsCadastrados)
{
    mPttsCadastrados = pttsCadastrados;
}


}

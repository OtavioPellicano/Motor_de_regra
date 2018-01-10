#include "pingbackdivergente.h"

namespace opmm {

PingBackDivergente::PingBackDivergente(const std::string &ipColetor, const std::vector<std::string> &ipsPrestadora)
{

    if(std::find(ipsPrestadora.begin(), ipsPrestadora.end(), ipColetor) != ipsPrestadora.end())
    {
        setMedidaValida(true);
    }
    else
    {
        setMedidaValida(false);
    }

}

bool PingBackDivergente::medidaValida() const
{
    return mMedidaValida;
}

void PingBackDivergente::setMedidaValida(const bool &medidaValida)
{
    mMedidaValida = medidaValida;
}


}


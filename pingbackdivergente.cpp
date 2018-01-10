#include "pingbackdivergente.h"

namespace opmm {

PingBackDivergente::PingBackDivergente(const std::string &ipColetor, const std::vector<std::string> &ipsPrestadora)
{
    for(std::vector<std::string>::const_iterator itVec = ipsPrestadora.begin(); itVec != ipsPrestadora.end(); ++itVec)
    {
        if((*itVec) == ipColetor)
        {
            setMedidaValida(true);
            return;
        }
    }

    setMedidaValida(false);
}

bool PingBackDivergente::medidaValida() const
{
    return mMedidaValida;
}

void PingBackDivergente::setMedidaValida(bool medidaValida)
{
    mMedidaValida = medidaValida;
}


}


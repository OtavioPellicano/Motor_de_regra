#include "pingbackdivergente.h"

namespace opmm {

PingBackDivergente::PingBackDivergente(const std::string &ipColetor, const std::vector<std::string> &ipsPrestadora)
{

    if(std::find(ipsPrestadora.begin(), ipsPrestadora.end(), ipColetor) != ipsPrestadora.end())
    {
        setMedicaoValida(true);
    }
    else
    {
        setMedicaoValida(false);
    }

}

}


#include "tabeladeassinantes.h"

namespace opmm {

TabelaDeAssinantes::TabelaDeAssinantes(const std::string &macCliente, const std::vector<std::string> &listaAssinantes)
{

    if(std::find(listaAssinantes.begin(), listaAssinantes.end(), macCliente)
            != listaAssinantes.end())
    {
        setMedicaoValida(true);
    }
    else
    {
        setMedicaoValida(false);
    }

}


}


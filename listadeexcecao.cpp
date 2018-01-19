#include "listadeexcecao.h"

namespace opmm {


ListaDeExcecao::ListaDeExcecao(const std::string &coletor,
                               const std::vector<std::string> &listaExcecaoMac)
{
    if(std::find(listaExcecaoMac.begin(), listaExcecaoMac.end(), coletor) != listaExcecaoMac.end())
    {
        setMedicaoValida(false);
    }
    else
    {
        setMedicaoValida(true);
    }
}


}


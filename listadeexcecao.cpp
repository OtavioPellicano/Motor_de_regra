#include "listadeexcecao.h"

namespace opmm {


ListaDeExcecao::ListaDeExcecao(const std::string &coletor, const std::vector<std::string> &listaExcecao)
{
    if(std::find(listaExcecao.begin(), listaExcecao.end(), coletor) != listaExcecao.end())
    {
        setMedicaoValida(false);
    }
    else
    {
        setMedicaoValida(true);
    }
}


}


#include "pttnaocadastrado.h"

namespace opmm {


PttNaoCadastrado::PttNaoCadastrado(const std::string &medicao, const std::vector<std::string> &pttsCadastados)
{
    if(std::find(pttsCadastados.begin(), pttsCadastados.end(), medicao) != pttsCadastados.end())
    {
        setMedicaoValida(true);
    }
    else
    {
        setMedicaoValida(false);
    }

}


}

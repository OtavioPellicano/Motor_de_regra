#include "avaliacaodasfalhas.h"

namespace opmm {

AvaliacaoDasFalhas::AvaliacaoDasFalhas(const std::string &sucesso, const std::string &falha)
{

    try {
        mSucesso = std::stod(sucesso);
        mFalha = std::stod(falha);
    } catch (...) {
        setMedicaoValida(false);
        return;
    }

    if(mSucesso <= 0 && mFalha <= 0)
    {
        setMedicaoValida(false);
        return;
    }

    if(mFalha < 0)
    {
        setMedicaoValida(false);
        return;
    }

    setMedicaoValida(true);

}



}


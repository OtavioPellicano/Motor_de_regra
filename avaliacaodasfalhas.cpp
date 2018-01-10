#include "avaliacaodasfalhas.h"

namespace opmm {

AvaliacaoDasFalhas::AvaliacaoDasFalhas(std::string sucesso, std::string falha)
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

bool AvaliacaoDasFalhas::medicaoValida() const
{
    return mMedicaoValida;
}

void AvaliacaoDasFalhas::setMedicaoValida(const bool &medicaoValida)
{
    mMedicaoValida = medicaoValida;
}


}


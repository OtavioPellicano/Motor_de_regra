#include "avaliacaodacpu.h"

namespace opmm {

AvaliacaoDaCpu::AvaliacaoDaCpu(const std::string &medicao, const bool &percentual)
{

    try {
        mMedicao = std::stod(medicao);
    } catch (...) {
        setMedicaoValida(false);
    }

    if (percentual)
    {
        if(mMedicao <= 80)
        {
            setMedicaoValida(true);
        }
        else
        {
            setMedicaoValida(false);
        }
    }
    else
    {
        if(mMedicao <= 0.8)
        {
            setMedicaoValida(true);
        }
        else
        {
            setMedicaoValida(false);
        }
    }

}


}


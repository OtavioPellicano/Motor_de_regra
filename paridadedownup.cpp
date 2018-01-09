#include "paridadedownup.h"

namespace opmm {

ParidadeDownUp::ParidadeDownUp(std::string medidaDown, std::string medidaUp)
{
    try {
        mDown = std::stod(medidaDown);
        mUp = std::stod(medidaUp);
    } catch (...) {
        setMedicaoValida(false);
        return;
    }
    setMedicaoValida(true);

}

bool ParidadeDownUp::medicaoValida()
{
    return mMedicaoValida;
}

void ParidadeDownUp::setMedicaoValida(const bool &medicaoValida)
{
    mMedicaoValida = medicaoValida;
}

}


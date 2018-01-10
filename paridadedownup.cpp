#include "paridadedownup.h"

namespace opmm {

ParidadeDownUp::ParidadeDownUp(const std::string &medidaDown, const std::string &medidaUp)
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


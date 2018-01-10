#include "medicaocomfalha.h"

namespace opmm {


MedicaoComFalha::MedicaoComFalha(std::string medicao)
{
    try {
        mMedicao = std::stod(medicao);
    } catch (...) {
        setMedicaoValida(false);
        return;
    }
    setMedicaoValida(true);
}

bool MedicaoComFalha::medicaoValida() const
{
    return mMedicaoValida;
}

void MedicaoComFalha::setMedicaoValida(const bool &medicaoValida)
{
    mMedicaoValida = medicaoValida;
}



}

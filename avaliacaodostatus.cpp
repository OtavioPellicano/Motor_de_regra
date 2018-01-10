#include "avaliacaodostatus.h"

namespace opmm {

AvaliacaoDoStatus::AvaliacaoDoStatus(const std::string &serviceStatus)
{
    if(serviceStatus == "Franchise" ||
            serviceStatus == "Suspended" ||
            serviceStatus == "Cancelled")
    {
        setMedicaoValida(false);
    }
    else
    {
        setMedicaoValida(true);
    }
}

bool AvaliacaoDoStatus::medicaoValida() const
{
    return mMedicaoValida;
}

void AvaliacaoDoStatus::setMedicaoValida(const bool &medicaoValida)
{
    mMedicaoValida = medicaoValida;
}


}

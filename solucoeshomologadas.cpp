#include "solucoeshomologadas.h"


namespace opmm {

SolucoesHomologadas::SolucoesHomologadas(const std::string &versaoSoftware, const std::vector<std::string> &listaSoftwareHomologados)
{

    if(std::find(listaSoftwareHomologados.begin(), listaSoftwareHomologados.end(), versaoSoftware)
            != listaSoftwareHomologados.end())
    {
        setMedicaoValida(true);
    }
    else
    {
        setMedicaoValida(false);
    }

}

bool SolucoesHomologadas::medicaoValida() const
{
    return mMedicaoValida;
}

void SolucoesHomologadas::setMedicaoValida(const bool &medicaoValida)
{
    mMedicaoValida = medicaoValida;
}


}


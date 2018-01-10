#ifndef SOLUCOESHOMOLOGADAS_H
#define SOLUCOESHOMOLOGADAS_H

#include <string>
#include <vector>
#include <algorithm>


namespace opmm {

/**
 * @brief The SolucoesHomologadas class
 * As medições pertencentes aos softwares
 * não homologados serão excluídas da medição dos índices.
 */
class SolucoesHomologadas
{
public:
    SolucoesHomologadas(const std::string &versaoSoftware, const std::vector<std::string> &listaSoftwareHomologados);


    bool medicaoValida() const;

private:

    void setMedicaoValida(const bool &medicaoValida);

private:
    bool mMedicaoValida;
};


}



#endif // SOLUCOESHOMOLOGADAS_H

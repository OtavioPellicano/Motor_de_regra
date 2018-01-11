#ifndef SOLUCOESHOMOLOGADAS_H
#define SOLUCOESHOMOLOGADAS_H

#include <string>
#include <vector>
#include <algorithm>
#include "validade.h"

namespace opmm {

/**
 * @brief The SolucoesHomologadas class
 * As medições pertencentes aos softwares
 * não homologados serão excluídas da medição dos índices.
 */
class SolucoesHomologadas: public Validade
{
public:
    SolucoesHomologadas(const std::string &versaoSoftware, const std::vector<std::string> &listaSoftwareHomologados);

};


}



#endif // SOLUCOESHOMOLOGADAS_H

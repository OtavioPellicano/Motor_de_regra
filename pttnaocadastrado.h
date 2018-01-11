#ifndef PTTNAOCADASTRADO_H
#define PTTNAOCADASTRADO_H

#include <string>
#include <vector>
#include <algorithm>
#include "validade.h"

namespace opmm {

/**
 * @brief The PttNaoCadastrado class
 * Serão excluídas as medições que o campo referente ao PTT
 * usado para o teste não esteja previamente cadastrado no sistema.
 */
class PttNaoCadastrado  : public Validade
{
public:
    PttNaoCadastrado(const std::string &medicao, const std::vector<std::string> &pttsCadastados);

};


}

#endif // PTTNAOCADASTRADO_H

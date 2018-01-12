#ifndef LISTADEEXCECAO_H
#define LISTADEEXCECAO_H

#include "validade.h"
#include <string>
#include <vector>
#include <algorithm>

namespace opmm {

/**
 * @brief The ListaDeExcecao class
 * As medições referentes aos coletores da
 * lista de exceção são descartadas
 */

class ListaDeExcecao : public Validade
{
public:
    ListaDeExcecao(const std::string &coletor, const std::vector<std::string> &listaExcecao);
};


}

#endif // LISTADEEXCECAO_H

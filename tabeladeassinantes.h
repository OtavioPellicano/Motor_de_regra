#ifndef TABELADEASSINANTES_H
#define TABELADEASSINANTES_H

#include <string>
#include <vector>
#include <algorithm>
#include "validade.h"

namespace opmm {

/**
 * @brief The TabelaDeAssinantes class
 * As medições recebidas para voluntários/assinantes não
 * encontrados ou não validos através do processo de verificação
 * pelas prestadoras serão descartadas da geração do índice.
 */

class TabelaDeAssinantes : public Validade
{
public:
    TabelaDeAssinantes(const std::string &macCliente, const std::vector<std::string> &listaAssinantes);
};

}


#endif // TABELADEASSINANTES_H

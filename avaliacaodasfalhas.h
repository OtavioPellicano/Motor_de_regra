#ifndef AVALIACAODASFALHAS_H
#define AVALIACAODASFALHAS_H

#include <string>
#include "validade.h"

namespace opmm {

/**
 * @brief The AvaliacaoDasFalhas class
 * Nos arquivos de download, upload, disponibilidade, jitter
 * e latência a medição deve ser excluída quando os campos (falha e sucesso)
 * forem menores ou iguais a 0 ou quando o campo falha for menor que 0
 */

class AvaliacaoDasFalhas : public Validade
{
public:
    AvaliacaoDasFalhas(const std::string &sucesso, const std::string &falha);

private:

    double mSucesso;
    double mFalha;
};

}



#endif // AVALIACAODASFALHAS_H

#ifndef AVALIACAODACPU_H
#define AVALIACAODACPU_H

#include "validade.h"
#include <string>

namespace opmm {

/**
 * @brief The AvaliacaoDaCpu class
 * Descartar medições com utilização de CPU maior que 80%;
 */

class AvaliacaoDaCpu : public Validade
{
public:
    AvaliacaoDaCpu(const std::string &medicao, const bool &percentual);

private:
    double mMedicao;
};


}


#endif // AVALIACAODACPU_H

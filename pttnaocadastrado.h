#ifndef PTTNAOCADASTRADO_H
#define PTTNAOCADASTRADO_H

#include <string>
#include <vector>
#include <algorithm>

namespace opmm {

/**
 * @brief The PttNaoCadastrado class
 * Serão excluídas as medições que o campo referente ao PTT
 * usado para o teste não esteja previamente cadastrado no sistema.
 */
class PttNaoCadastrado
{
public:
    PttNaoCadastrado(const std::string &medicao, const std::vector<std::string> &pttsCadastados);

    bool medicaoValida() const;

private:
    void setMedicaoValida(const bool &medicaoValida);

private:
    bool mMedicaoValida;


};


}

#endif // PTTNAOCADASTRADO_H

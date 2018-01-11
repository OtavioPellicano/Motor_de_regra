#ifndef PINGBACKDIVERGENTE_H
#define PINGBACKDIVERGENTE_H

#include <string>
#include <vector>
#include <algorithm>
#include "validade.h"

namespace opmm {

/**
 * @brief The PingBackDivergente class
 * Para toda medição deve ser verificado se o IP do coletor corresponde
 * a prestadora. Caso seja identificada que a medição é de prestadora
 * diferente, a mesma é descartada do índice.
 */
class PingBackDivergente: public Validade
{
public:
    PingBackDivergente(const std::string &ipColetor, const std::vector<std::string> &ipsPrestadora);


private:

    std::string mIpColetor;
    std::string mIpPrestadora;

};

}



#endif // PINGBACKDIVERGENTE_H

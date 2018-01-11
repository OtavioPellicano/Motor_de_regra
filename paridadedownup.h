#ifndef PARIDADEDOWNUP_H
#define PARIDADEDOWNUP_H

#include <string>
#include "validade.h"

namespace opmm {

/**
 * @brief The ParidadeDownUp class
 * Classe destinada a verificação de paridade down e up
 * se qualquer um dos dois (down, up) tiver a medidade invalida
 * o retorno do metodo medicaoValida retorna falso
 */

class ParidadeDownUp : public Validade
{
public:
    ParidadeDownUp(const std::string &medidaDown, const std::string &medidaUp);

    double mDown;
    double mUp;

};

}


#endif // PARIDADEDOWNUP_H

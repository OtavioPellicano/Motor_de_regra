#ifndef PARIDADEDOWNUP_H
#define PARIDADEDOWNUP_H

#include <string>

namespace opmm {

/**
 * @brief The ParidadeDownUp class
 * Classe destinada a verificação de paridade down e up
 * se qualquer um dos dois (down, up) tiver a medidade invalida
 * o retorno do metodo medicaoValida retorna falso
 */

class ParidadeDownUp
{
public:
    ParidadeDownUp(std::string medidaDown, std::string medidaUp);

    bool medicaoValida();


private:

    void setMedicaoValida(const bool &medicaoValida);

    bool mMedicaoValida;
    double mDown;
    double mUp;


};

}


#endif // PARIDADEDOWNUP_H

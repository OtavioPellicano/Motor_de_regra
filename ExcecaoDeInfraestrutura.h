#ifndef EXCECAODEINFRAESTRUTURA_H
#define EXCECAODEINFRAESTRUTURA_H

#include "validade.h"
#include <string>
#include <vector>
#include <algorithm>
#include <QDateTime>

namespace opmm {

/**
 * @brief The ExcecaoDeInfraestrutura class
 * As medições referentes aos períodos e servidor de teste PPT
 * referentes a prestadora são descartadas conforme cadastro
 * realizado em tela.
 */

class ExcecaoDeInfraestrutura : public Validade
{
public:
    ExcecaoDeInfraestrutura(const std::string &testPoint, const QDateTime &dateTime,
                            const QDateTime &dateTimeInicio, const QDateTime &dateTimeFim,
                            const std::vector<std::string> &listaDeExcecaoPtts);
};

}


#endif // EXCECAODEINFRAESTRUTURA_H

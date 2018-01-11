#ifndef AVALIACAODOSTATUS_H
#define AVALIACAODOSTATUS_H

#include <string>
#include "validade.h"

namespace opmm {

/**
 * @brief The AvaliacaoDoStatus class
 * Descartar quando o campo serviceStatus do rawdata de estiver
 * preenchido com "Franchise", "Suspended" ou "Cancelled";
 */
class AvaliacaoDoStatus : public Validade
{
public:
    AvaliacaoDoStatus(const std::string &serviceStatus);

};


}


#endif // AVALIACAODOSTATUS_H

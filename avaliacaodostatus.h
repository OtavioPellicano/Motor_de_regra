#ifndef AVALIACAODOSTATUS_H
#define AVALIACAODOSTATUS_H

#include <string>

namespace opmm {

/**
 * @brief The AvaliacaoDoStatus class
 * Descartar quando o campo serviceStatus do rawdata de estiver
 * preenchido com "Franchise", "Suspended" ou "Cancelled";
 */
class AvaliacaoDoStatus
{
public:
    AvaliacaoDoStatus(const std::string &serviceStatus);

    bool medicaoValida() const;

private:
    void setMedicaoValida(const bool &medicaoValida);

private:
    bool mMedicaoValida;
};


}


#endif // AVALIACAODOSTATUS_H

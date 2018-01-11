#ifndef MEDICAOCOMFALHA_H
#define MEDICAOCOMFALHA_H
#include <string>

#include "validade.h"

namespace opmm {

/**
 * @brief The MedicaoComFalha class
 * Nos arquivos com as medições de Download,
 * Upload, Jitter, Latência e Disponibilidade,
 * os registros que apresentarem medição com
 * falha deve ser descartada
 */
class MedicaoComFalha: public Validade
{
public:
    MedicaoComFalha(const std::string &medicao);

private:

    double mMedicao;

};

}


#endif // MEDICAOCOMFALHA_H

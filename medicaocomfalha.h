#ifndef MEDICAOCOMFALHA_H
#define MEDICAOCOMFALHA_H
#include <string>



namespace opmm {

/**
 * @brief The MedicaoComFalha class
 * Nos arquivos com as medições de Download,
 * Upload, Jitter, Latência e Disponibilidade,
 * os registros que apresentarem medição com
 * falha deve ser descartada
 */
class MedicaoComFalha
{
public:
    MedicaoComFalha(std::string medicao);

    bool medicaoValida() const;

private:

    void setMedicaoValida(const bool &medicaoValida);


private:

    bool mMedicaoValida;

    double mMedicao;

};

}


#endif // MEDICAOCOMFALHA_H

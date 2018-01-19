#ifndef MODELOHARDWARENAOCOMPATIVEL_H
#define MODELOHARDWARENAOCOMPATIVEL_H

#include "validade.h"
#include <string>
#include <vector>
#include <algorithm>

namespace opmm {

/**
 * @brief The ModeloHardwareNaoCompativel class
 * Medições com modelo de hardware não compatível
 * com o software serão descartadas.
 */

class ModeloHardwareNaoCompativel :  public Validade
{
public:
    ModeloHardwareNaoCompativel(const std::string &hardware, const std::vector<std::string> &listaHardwareCompativel);
};

}


#endif // MODELOHARDWARENAOCOMPATIVEL_H

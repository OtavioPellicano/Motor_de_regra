#include "ModeloHardwareNaoCompativel.h"

namespace opmm {

ModeloHardwareNaoCompativel::ModeloHardwareNaoCompativel(const std::string &hardware, const std::vector<std::string> &listaHardwareCompativel)
{
    if(std::find(listaHardwareCompativel.begin(), listaHardwareCompativel.end(), hardware)
            != listaHardwareCompativel.end())
    {
        setMedicaoValida(true);
    }
    else
    {
        setMedicaoValida(false);
    }
}


}

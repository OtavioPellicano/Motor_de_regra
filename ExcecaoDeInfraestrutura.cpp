#include "ExcecaoDeInfraestrutura.h"

namespace opmm {


ExcecaoDeInfraestrutura::ExcecaoDeInfraestrutura(const std::string &testPoint, const QDateTime &dateTime,
                                                 const QDateTime &dateTimeInicio, const QDateTime &dateTimeFim,
                                                 const std::vector<std::string> &listaDeExcecaoPtts)
{
    //Critério para descartar todos os servidores no periodo
    if(listaDeExcecaoPtts.size() != 0)
    {
        if(dateTime >= dateTimeInicio && dateTime <= dateTimeFim)
        {
            if(std::find(listaDeExcecaoPtts.begin(), listaDeExcecaoPtts.end(), testPoint)
                    != listaDeExcecaoPtts.end())
            {
                setMedicaoValida(false);
            }
            else
            {
                setMedicaoValida(true);
            }
        }
        else
        {
            setMedicaoValida(true);
        }

    }
    else
    {
        if(dateTime >= dateTimeInicio && dateTime <= dateTimeFim)
        {
            setMedicaoValida(false);
        }
        else
        {
            setMedicaoValida(true);
        }
    }
}

}


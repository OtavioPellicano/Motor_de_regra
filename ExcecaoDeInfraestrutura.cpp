#include "ExcecaoDeInfraestrutura.h"

namespace opmm {


ExcecaoDeInfraestrutura::ExcecaoDeInfraestrutura(const std::string &testPoint, const QDateTime &dateTime,
                                                 const QDateTime &dateTimeInicio, const QDateTime &dateTimeFim,
                                                 const std::vector<std::string> &listaDeExcecaoPtt)
{
    /**
     * Critério para descartar todos os servidores no periodo
     * Caso a listaDeExcecaoPtt esteja vazia, descarta todos os Ptts
     * */
    if(listaDeExcecaoPtt.size() != 0)
    {
        if(dateTime >= dateTimeInicio && dateTime <= dateTimeFim)
        {
            if(std::find(listaDeExcecaoPtt.begin(), listaDeExcecaoPtt.end(), testPoint)
                    != listaDeExcecaoPtt.end())
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


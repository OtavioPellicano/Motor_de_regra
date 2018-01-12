#ifndef REGRASSCM_H
#define REGRASSCM_H


#include "medicaocomfalha.h"        //#3* SCM SMP
#include "avaliacaodasfalhas.h"     //#4 SCM
#include "paridadedownup.h"         //#6 SCM SMP
#include "pmt.h"                    //#7 SCM SMP
#include "pingbackdivergente.h"     //#8 SCM SMP
#include "solucoeshomologadas.h"    //#9 SCM
#include "tabeladeassinantes.h"     //#20 SCM
#include "listadeexcecao.h"         //#21 SCM SMP
#include "pttnaocadastrado.h"       //#26 SCM SMP

#include <string>

namespace opmm {
/**
 * @brief The RegrasSCM class
 * Classe que agrupa todas as regras de SCM
 */
class RegrasSCM
{
public:
    RegrasSCM();

};


}


#endif // REGRASSCM_H

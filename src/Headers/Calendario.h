/*
 * Calendario.h
 *
 *  Created on: 01/11/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_CALENDARIO_H_
#define HEADERS_CALENDARIO_H_

#include "Local.h"
#include "Palestra.h"
#include "Palestrante.h"
#include "Disponibilidade.h"

typedef struct Calendario Calendario;
/**
 * Retorno do local a partir de um Calendario.
 * 
 * @param c Referencia a struct Calendario.
 * @return retorna a referencia ao strcut Local.
 */
Local* Calendario_Get_Local(Calendario* c);
/**
 * Retorno da struct Palestra.
 * @param c Referencia a struct Calendario.
 */
Palestra* Calendario_Get_Palestra(Calendario* c);
/**
 * Retorno da referencia a struct Disponibilidade.
 * @param c Referencia a struct Calendario.
 */
Disponibilidade* Calendario_Get_Disponibilidade(Calendario* c);
/**
 * Retorna um ponteiro para o novo calendario inicializado.
 */
Calendario* Calendario_New(Local* l, Palestra* p, Disponibilidade* disp, Palestrante* palestrante);

#endif /* HEADERS_CALENDARIO_H_ */

/*
 * Calendario_Manager.h
 *
 *  Created on: 02/11/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_CALENDARIO_MANAGER_H_
#define HEADERS_CALENDARIO_MANAGER_H_

#include "Calendario.h"

static Calendario** calendario;
static int Calendario_Vector_Size;
/**
 * Inicializa a estrutura de calendario.
 */
void Calendario_Manager_Initialize();
/**
 * Adiciona um Calendario* a estrutura.
 * @param cal estrutura a ser adicionada.
 */
void Calendario_Manager_Add(Calendario* cal);
/**
 * Escreve um arquivo feito os devidos processamentos.
 */
void Calendario_Manager_Print();

#endif /* HEADERS_CALENDARIO_MANAGER_H_ */

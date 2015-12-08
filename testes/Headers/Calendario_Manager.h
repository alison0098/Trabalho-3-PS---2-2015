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

void Calendario_Manager_Delete();

/**
 * Escreve uma lista de palestras dado um dia.
 */
void Calendario_Manager_Search_By_Day(int dia);

/**
 * Escreve uma lista de palestras dado um mes.
 */
void Calendario_Manager_Search_By_Month(int mes);

/**
 * Escreve uma lista de palestras dado um ano.
 */
void Calendario_Manager_Search_By_Year(int ano);
#endif /* HEADERS_CALENDARIO_MANAGER_H_ */

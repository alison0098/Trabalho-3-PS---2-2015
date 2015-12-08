/*
 * Local.h
 *
 *  Created on: 31/10/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_LOCAL_H_
#define HEADERS_LOCAL_H_

#include "Disponibilidade.h"
typedef struct Local Local;

/**
 * Retorna uma estrutura instanciada.
 */
Local* Local_New(char* nome, char* endereco);
/**
 * Adiciona uma disponibilidade.
 * Adiciona uma disponibilidade ao vetor de disponibilidades.
 */
void Local_Add_Disp(Local* l, Disponibilidade* disp);
/**
 * Retorna o nome.
 */
char* Local_Get_Nome(Local* l);
/**
 * Retorna endereco.
 */
char* Local_Get_Endereco(Local* l);
/**
 * Retorna o tamanho do vetor de disponibilidades.
 */
int Local_Get_Disp_Size(Local *l);
/**
 * Retorna o vetor de disponibilidades.
 */
Disponibilidade** Local_Get_Disp(Local* l);
/**
 * Retorna a posicao do vetor de disponibilidades.
 * @param l local a ser consultado.
 * @param disp disponibilidade que servira como chave.
 */
int Local_Get_Disp_Pos(Local*l , Disponibilidade* disp);

#endif /* HEADERS_LOCAL_H_ */

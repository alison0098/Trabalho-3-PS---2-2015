/*
 * Palestrante.h
 *
 *  Created on: 01/11/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_PALESTRANTE_H_
#define HEADERS_PALESTRANTE_H_

#include "Disponibilidade.h"

typedef struct Palestrante Palestrante;
/**
 * Retorna o nome.
 */
char* Palestrante_Get_Nome(Palestrante* p);
/**
 * Retorna o vetor de disponibilidades.
 */
Disponibilidade** Palestrante_Get_Disp(Palestrante* p);
/**
 * Retorna um palestrante inicializado.
 * @param nome nome do palestrante para ser adicionado.
 */
Palestrante* Palestrante_New(char* nome);
/**
 * Adiciona uma disponibilidade ao vetor.
 */
void Palestrante_Add_Disp(Palestrante* p, Disponibilidade* disp);
/**
 * Retorna o tamanho do vetor de disponibilidades.
 */
int Palestrante_Get_Disp_Size(Palestrante* p);


#endif /* HEADERS_PALESTRANTE_H_ */

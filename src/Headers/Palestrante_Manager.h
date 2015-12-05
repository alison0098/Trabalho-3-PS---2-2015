/*
 * Palestrante_Manager.h
 *
 *  Created on: 01/11/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_PALESTRANTE_MANAGER_H_
#define HEADERS_PALESTRANTE_MANAGER_H_

#include "Fila_Palestrante.h"

static FilaPalestrante* filaPalestrante;
/**
 * Le o arquivo e arruma a fila.
 */
void PalestranteManager_Read(char* filename);
/**
 * Destroi a fila.
 */
int PalestranteManager_PopFila();
/**
 * Escreve na tela os valores importantes da fila.
 */
void PalestranteManager_Print();
/**
 * Retorna o ponteiro da fila.
 */
FilaPalestrante* PalestranteManager_GetPalestrante();


#endif /* HEADERS_PALESTRANTE_MANAGER_H_ */

/*
 * Palestra_Manager.h
 *
 *  Created on: 31/10/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_PALESTRA_MANAGER_H_
#define HEADERS_PALESTRA_MANAGER_H_

#include "Fila_Palestra.h"
#include <stdlib.h>

static FilaPalestra* filaPalestra;

/**
 * Le o arquivo e adiciona nodos a fila.
 *
 * @param filename    nome do arquivo a ser lido.
 */
int PalestraManager_Read(char* filename);
/**
 * Destroi a fila de palestras.
 *
 * @return retorna 1 se bem sucedido.
 */
int PalestraManager_PopFila();
/**
 * Imprime a fila.
 */
void PalestraManager_Print();

FilaPalestra* PalestraManager_Get();
#endif /* HEADERS_PALESTRA_MANAGER_H_ */

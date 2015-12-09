/*
 * Local_Manager.h
 *
 *  Created on: 31/10/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_LOCAL_MANAGER_H_
#define HEADERS_LOCAL_MANAGER_H_

#include "Fila_Local.h"

static FilaLocal* filaLocal;
/**
 * Le arquivo e cria a lista de locais.
 */
int LocalManager_Read(char* filename);
/**
 * Destroi fila.
 */
int LocalManager_PopFila();
/**
 * Escreve as informacoes importantes da lista.
 */
void LocalManager_Print();
/**
 * Retorna a variavel estatica.
 */
FilaLocal* LocalManager_GetLocal();

#endif /* HEADERS_LOCAL_MANAGER_H_ */

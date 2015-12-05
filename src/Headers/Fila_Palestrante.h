/*
 * Fila_Palestrante.h
 *
 *  Created on: 01/11/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_FILA_PALESTRANTE_H_
#define HEADERS_FILA_PALESTRANTE_H_

#include "Nodo_Palestrante.h"
#include "Disponibilidade.h"

typedef struct FilaPalestrante FilaPalestrante;
/**
 * Retorna uma instancia da fila.
 */
FilaPalestrante* FilaPalestrante_New();
/**
 * Adiciona um nodo a fila.
 * @param node nodo a ser adicionado.
 * @param fila fila  a qual sera adicionado o nodo
 */
void FilaPalestrante_Add(NodePalestrante* node, FilaPalestrante* fila);
/**
 * Checa se a fila esta vazia.
 */
int FilaPalestrante_Is_Empty(FilaPalestrante* fila);
/**
 * Deleta a fila.
 */
FilaPalestrante* FilaPalestrante_Pop(FilaPalestrante* fp);
/**
 * Retorna um nodo dado uma chave.
 */
NodePalestrante* FilaPalestrante_Get(FilaPalestrante* fp, char* nome);
/**
 * Escreve na tela as informacoes de cada nodo.
 */
void FilaPalestrante_Print(FilaPalestrante* f);
/**
 * Retorna o primeiro nodo da fila.
 */
NodePalestrante* FilaPalestrante_Get_First(FilaPalestrante* f);
/**
 * Retorna o ultimo nodo da fila.
 */
NodePalestrante* FilaPalestrante_Get_Last(FilaPalestrante* f);
/**
 * Retorna um vetor com os nodos da fila.
 */
NodePalestranteVector* FilaPalestrante_To_Vector(FilaPalestrante* f);


#endif /* HEADERS_FILA_PALESTRANTE_H_ */

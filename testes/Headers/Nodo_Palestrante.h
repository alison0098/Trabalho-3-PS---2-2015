/*
 * Nodo_Palestrante.h
 *
 *  Created on: 01/11/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_NODO_PALESTRANTE_H_
#define HEADERS_NODO_PALESTRANTE_H_

#include "Palestrante.h"

typedef struct NodePalestrante NodePalestrante;
typedef struct NodePalestranteVector NodePalestranteVector;
/**
 * Instancia um nodo e atrela o palestrante.
 *
 * @param p    e um ponteiro para a palestrante a ser adicionada.
 * @return retorna o ponteiro do nodo inicializado.
 */
NodePalestrante* NodePalestrante_New(Palestrante* p);
/**
 * Retorna o ponteiro para o proximo.
 */
NodePalestrante* NodePalestrante_Get_Prox(NodePalestrante* np);
/**
 * Retorna o ponteiro para palestrante dado um nodo.
 */
Palestrante* NodePalestrante_Get(NodePalestrante* np);
/**
 * Estabelece o proximo nodo.
 */
void NodePalestrante_Set_Prox(NodePalestrante* np, NodePalestrante* prox);
/**
 * Retorna um Vetor de nodos.
 */
NodePalestranteVector* NodePalestrante_Vector_New();
/**
 * Adiciona um nodo ao vetor.
 */
void NodePalestrante_Vector_Add(NodePalestrante* np, NodePalestranteVector* nv);
/**
 * Deleta o vetor.
 */
NodePalestranteVector* NodePalestrante_Vector_Del(NodePalestranteVector* npv);
/**
 * Retorna o tamanho do vetor.
 */
int NodePalestrante_Vector_Get_Size(NodePalestranteVector* nv);
/**
 * Retorna o nodo de um vetor.
 * Retorna o nodo de um vetor dado a posicao.
 */
NodePalestrante* NodePalestrante_Vector_Get(NodePalestranteVector* nv, int i);


#endif /* HEADERS_NODO_PALESTRANTE_H_ */

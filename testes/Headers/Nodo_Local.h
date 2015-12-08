/*
 * Nodo_Local.h
 *
 *  Created on: 31/10/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_NODO_LOCAL_H_
#define HEADERS_NODO_LOCAL_H_

#include "Local.h"

typedef struct NodeLocal NodeLocal;
typedef struct NodeLocalVector NodeLocalVector;

/**
 * Retorna um Nodo instanciado.
 */
NodeLocal* NodeLocal_New(Local* l);
/**
 * Retorna o campo prox do nodo.
 */
NodeLocal* NodeLocal_Get_Prox(NodeLocal* nl);
/**
 * Retorna um local dado um nodo.
 */
Local* NodeLocal_Get(NodeLocal* nl);
/**
 * Atribui um nodo ao campo proximo de nl.
 * @param nl nodo a ser atribuido o proximo.
 * @param prox nodo que sera o proximo.
 */
void NodeLocal_Set_Prox(NodeLocal* nl, NodeLocal* prox);
/**
 * Retorna um vetor de locais instanciado.
 */
NodeLocalVector* NodeLocal_Vector_New();
/**
 * Adiciona um nodo ao vetor nv.
 */
void NodeLocal_Vector_Add(NodeLocal* nl, NodeLocalVector* nv);
/**
 * Deleta o vetor de nodos.
 */
NodeLocalVector* NodeLocal_Vector_Del(NodeLocalVector* nlv);
/**
 * Retorna o tamanho do vetor.
 */
int NodeLocal_Vector_Get_Size(NodeLocalVector* nv);
/**
 * Retorna um Nodo dado o vetor e a posicao.
 */
NodeLocal* NodeLocal_Vector_Get(NodeLocalVector* nv, int i);

#endif /* HEADERS_NODO_LOCAL_H_ */

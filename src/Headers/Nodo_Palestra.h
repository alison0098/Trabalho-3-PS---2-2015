#ifndef HEADERS_NODE_PALESTRA_H_
#define HEADERS_NODE_PALESTRA_H_

#include "Palestra.h"

typedef struct NodePalestra NodePalestra;

/**
 * Instancia um nodo e atrela a palestra.
 *
 * @param p    e um ponteiro para a palestra a ser adicionada.
 * @return retorna o ponteiro do nodo inicializado.
 */
NodePalestra* NodePalestra_New(Palestra *p);
/**
 * Estabelece o proximo nodo.
 *
 * @param np   nodo a qual sera adicionado o campo prox.
 * @param prox nodo que sera o proximo.
 */
void NodePalestra_Set_Prox(NodePalestra* np, NodePalestra* prox);
/**
 * Retorna o ponteiro para o proximo nodo.
 *
 * @param np   nodo a ser consultado.
 */
NodePalestra* NodePalestra_Get_Prox(NodePalestra* np);
/**
 * Pega o ponteiro para palestra que esta atrelado ao nodo.
 *
 * @param np  nodo a ser consultado.
 * @return ponteiro para palestra atrelada ao nodo.
 */
Palestra* NodePalestra_Get(NodePalestra* np);

#endif

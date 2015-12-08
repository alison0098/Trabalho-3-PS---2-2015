/*
 * Nodo_Palestrante.c
 *
 *  Created on: 01/11/2015
 *      Author: Guilherme
 */
#include "../Headers/Nodo_Palestrante.h"
#include <stdlib.h>

struct NodePalestrante{
	Palestrante* Palestrante;
	struct NodePalestrante* prox;
};

struct NodePalestranteVector{
	NodePalestrante** vetor;
	int size;
};

NodePalestranteVector* NodePalestrante_Vector_New(){
	NodePalestranteVector* aux = (NodePalestranteVector*)malloc(sizeof(NodePalestranteVector));
	if(aux == NULL)
		return NULL;

	aux->vetor = NULL;
	aux->size = 0;

	return aux;
}

void NodePalestrante_Vector_Add(NodePalestrante* np, NodePalestranteVector* nv){
	if(np == NULL)
		return;

	if(nv == NULL)
		nv = NodePalestrante_Vector_New();

	if(nv->vetor == NULL){
		nv->vetor = (NodePalestrante**)malloc(sizeof(NodePalestrante*));
		nv->vetor[nv->size] = np;
		nv->size++;
	}else{
		nv->vetor = (NodePalestrante**)realloc(nv->vetor, (nv->size + 1)*sizeof(NodePalestrante*));
		nv->vetor[nv->size] = np;
		nv->size++;
	}
}

NodePalestranteVector* NodePalestrante_Vector_Del(NodePalestranteVector* npv){
	if(npv == NULL)
		return NULL;

	free(npv);

	return NULL;
}

int NodePalestrante_Vector_Get_Size(NodePalestranteVector* nv){
	return nv->size;
}

NodePalestrante* NodePalestrante_Vector_Get(NodePalestranteVector* nv, int i){
	return nv->vetor[i];
}

NodePalestrante* NodePalestrante_New(Palestrante* p){
	NodePalestrante* aux = (NodePalestrante*)malloc(sizeof(NodePalestrante));

	if(aux == NULL)
		return NULL;

	aux->Palestrante = p;
	aux->prox = NULL;

	return aux;
}

NodePalestrante* NodePalestrante_Get_Prox(NodePalestrante* np){
	return np->prox;
}

Palestrante* NodePalestrante_Get(NodePalestrante* np){
	//printf("In NodePalestrante_Get\n");
	return np->Palestrante;
}

void NodePalestrante_Set_Prox(NodePalestrante* np, NodePalestrante* prox){
	np->prox= prox;
}


/*
 * Node_Local.c
 *
 *  Created on: 31/10/2015
 *      Author: Guilherme
 */
#include "../Headers/Local.h"
#include "../Headers/Nodo_Local.h"
#include <stdlib.h>

typedef struct NodeLocal{
	Local* local;
	struct NodeLocal* prox;
}NodeLocal;

struct NodeLocalVector{
	NodeLocal** vetor;
	int size;
};

NodeLocalVector* NodeLocal_Vector_New(){
	NodeLocalVector* aux = (NodeLocalVector*)malloc(sizeof(NodeLocalVector));
	if(aux == NULL)
		return NULL;

	aux->vetor = NULL;
	aux->size = 0;

	return aux;
}

void NodeLocal_Vector_Add(NodeLocal* nl, NodeLocalVector* nv){
	if(nl == NULL)
		return;

	if(nv == NULL)
		nv = NodeLocal_Vector_New();

	if(nv->vetor == NULL){
		nv->vetor = (NodeLocal**)malloc(sizeof(NodeLocal*));
		nv->vetor[nv->size] = nl;
		nv->size++;
	}else{
		nv->vetor = (NodeLocal**)realloc(nv->vetor, (nv->size + 1)*sizeof(NodeLocal*));
		nv->vetor[nv->size] = nl;
		nv->size++;
	}
}

NodeLocalVector* NodeLocal_Vector_Del(NodeLocalVector* nlv){
	if(nlv == NULL)
		return NULL;

	free(nlv);

	return NULL;
}

int NodeLocal_Vector_Get_Size(NodeLocalVector* nv){
	return nv->size;
}

NodeLocal* NodeLocal_Vector_Get(NodeLocalVector* nv, int i){
	return nv->vetor[i];
}

NodeLocal* NodeLocal_New(Local* l){
	NodeLocal* aux = (NodeLocal*)malloc(sizeof(NodeLocal));

	if(aux == NULL)
		return NULL;

	aux->local = l;
	aux->prox = NULL;

	return aux;
}

NodeLocal* NodeLocal_Get_Prox(NodeLocal* nl){
	return nl->prox;
}

Local* NodeLocal_Get(NodeLocal* nl){
	//printf("In NodeLocal_Get()\n");
	if(nl != NULL)
	    return nl->local;
	return NULL;
}

void NodeLocal_Set_Prox(NodeLocal* nl, NodeLocal* prox){
	nl->prox= prox;
}

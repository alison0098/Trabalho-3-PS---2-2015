#include "../Headers/Nodo_Palestra.h"
#include "../Headers/Palestra.h"

#include <stdlib.h>

typedef struct NodePalestra{
	struct NodePalestra* prox;
	Palestra* palestra;
}NodePalestra;

NodePalestra* NodePalestra_New(Palestra *p){

	NodePalestra* np = (NodePalestra*)malloc(sizeof(NodePalestra));
	np->prox = NULL;
	np->palestra = p;

	return np;
}

void NodePalestra_Set_Prox(NodePalestra* np, NodePalestra* prox){
	np->prox = prox;
}

NodePalestra* NodePalestra_Get_Prox(NodePalestra* np){
	return np->prox;
}

Palestra* NodePalestra_Get(NodePalestra* np){
	//printf("%dIn NodePalestra_Get()\n", np);
	return np->palestra;
}

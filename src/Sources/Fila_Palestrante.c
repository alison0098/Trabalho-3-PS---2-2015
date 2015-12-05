/*
 * FilaPalestrante.c
 *
 *  Created on: 01/11/2015
 *      Author: Guilherme
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/Fila_Palestrante.h"

struct FilaPalestrante{
	NodePalestrante* first, *last;
};

FilaPalestrante* FilaPalestrante_New(){
	FilaPalestrante* aux = (FilaPalestrante*)malloc(sizeof(FilaPalestrante));
	if(aux == NULL)
		return NULL;

	aux->first = NULL;
	aux->last = NULL;

	return aux;
}

void FilaPalestrante_Add(NodePalestrante* node, FilaPalestrante* fila){
	if(FilaPalestrante_Is_Empty(fila))
		fila->first = node;
	else
		NodePalestrante_Set_Prox(fila->last, node);
	fila->last = node;
}

int FilaPalestrante_Is_Empty(FilaPalestrante* fila){
	return fila->first == NULL;
}

FilaPalestrante* FilaPalestrante_Pop(FilaPalestrante* fp){
	NodePalestrante* aux, *temp;

	if(fp == NULL)
		return (FilaPalestrante*)NULL;

	if(FilaPalestrante_Is_Empty(fp)){
		free(fp);
		return (FilaPalestrante*)NULL;
	}

	aux = fp->first;

	while(aux != NULL){
		//free(Palestrante_Get_Disp(NodePalestrante_Get(aux)));
		temp = NodePalestrante_Get_Prox(aux);
		free(aux);
		aux = temp;
	}

	free(fp);

	return (FilaPalestrante*)NULL;
}

NodePalestrante* FilaPalestrante_Get(FilaPalestrante* fp, char* nome){
	int check = 0;
	NodePalestrante* aux;

	if(fp == NULL)
		return NULL;
	if(FilaPalestrante_Is_Empty(fp))
		return NULL;

	aux = fp->first;

	while(aux != NULL && check == 0){
		if(strcmp(Palestrante_Get_Nome(NodePalestrante_Get(aux)), nome) == 0)
			check = 1;
		if(!check)
			aux = NodePalestrante_Get_Prox(aux);
	}

	return aux;
}

NodePalestrante* FilaPalestrante_Get_With_Disp(FilaPalestrante* fp, Disponibilidade* disp){
	int check = 0;
	NodePalestrante* aux;
	int i = 0;

	if(fp == NULL)
		return NULL;
	if(FilaPalestrante_Is_Empty(fp))
		return NULL;

	aux = fp->first;

	while(aux != NULL && check == 0){
		for(i = 0; i < Palestrante_Get_Disp_Size(NodePalestrante_Get(aux)) && check == 0; i++){
			if(strcmp(Disponibilidade_Get_Data(Palestrante_Get_Disp(NodePalestrante_Get(aux))[i]), Disponibilidade_Get_Data(disp)) == 0)
				check = 1;
		}
		if(!check)
		    aux = NodePalestrante_Get_Prox(aux);
	}
	if(check)
		return aux;

	return NULL;
}

NodePalestrante* FilaPalestrante_Get_First(FilaPalestrante* f){
	return f->first;
}

NodePalestrante* FilaPalestrante_Get_Last(FilaPalestrante* f){
	return f->last;
}

void FilaPalestrante_Print(FilaPalestrante* f){
	NodePalestrante* aux;

	int i;

	if(f == NULL){
			printf("Fila nao inicializada");
			return;
	}
	if(FilaPalestrante_Is_Empty(f)){
		printf("Fila vazia.");
		return;
	}

	aux = f->first;

	while(aux != NULL){
	    printf("%s\n", Palestrante_Get_Nome(NodePalestrante_Get(aux)));
	    for(i = 0; i < Palestrante_Get_Disp_Size(NodePalestrante_Get(aux)); i++){
	    	printf("%s - %i:%i\n", Disponibilidade_Get_Data(Palestrante_Get_Disp(NodePalestrante_Get(aux))[i]),
	    			Disponibilidade_Get_Hora(Palestrante_Get_Disp(NodePalestrante_Get(aux))[i]),
	    			Disponibilidade_Get_Minuto(Palestrante_Get_Disp(NodePalestrante_Get(aux))[i]));
	    }
	    aux = NodePalestrante_Get_Prox(aux);
	}
	return;
}

NodePalestranteVector* FilaPalestrante_To_Vector(FilaPalestrante* f){
	NodePalestranteVector* aux = NodePalestrante_Vector_New();
	NodePalestrante* nlaux;

	if(aux == NULL)
		return NULL;

	if(f == NULL)
		return NULL;

	nlaux = f->first;

	while(nlaux != NULL){
		NodePalestrante_Vector_Add(nlaux, aux);
		nlaux = NodePalestrante_Get_Prox(nlaux);
	}

	return aux;
}


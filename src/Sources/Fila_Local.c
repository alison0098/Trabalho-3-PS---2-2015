/*
 * Fila_Local.c
 *
 *  Created on: 31/10/2015
 *      Author: Guilherme
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/Fila_Local.h"

struct FilaLocal{
	NodeLocal* first, *last;
};

FilaLocal* FilaLocal_New(){
	FilaLocal* aux = (FilaLocal*)malloc(sizeof(FilaLocal));
	if(aux == NULL)
		return NULL;

	aux->first = NULL;
	aux->last = NULL;

	return aux;
}

void FilaLocal_Add(NodeLocal* node, FilaLocal* fila){
	if(FilaLocal_Is_Empty(fila))
		fila->first = node;
	else
		NodeLocal_Set_Prox(fila->last, node);
	fila->last = node;
}

int FilaLocal_Is_Empty(FilaLocal* fila){
	return fila->first == NULL;
}

FilaLocal* FilaLocal_Pop(FilaLocal* fp){
	NodeLocal* aux, *temp;

	if(fp == NULL)
		return (FilaLocal*)NULL;

	if(FilaLocal_Is_Empty(fp)){
		free(fp);
		return (FilaLocal*)NULL;
	}

	aux = fp->first;

	while(aux != NULL){
		free(Local_Get_Disp(NodeLocal_Get(aux)));
		temp = NodeLocal_Get_Prox(aux);
		free(aux);
		aux = temp;
	}

	free(fp);

	return (FilaLocal*)NULL;
}

NodeLocal* FilaLocal_Get(FilaLocal* fp, char* nome){
	int check = 0;
	NodeLocal* aux;

	if(fp == NULL)
		return NULL;
	if(FilaLocal_Is_Empty(fp))
		return NULL;

	aux = fp->first;

	while(aux != NULL && check == 0){
		if(strcmp(Local_Get_Nome(NodeLocal_Get(aux)), nome) == 0)
			check = 1;
		if(!check)
			aux = NodeLocal_Get_Prox(aux);
	}

	return aux;
}

NodeLocal* FilaLocal_Get_With_Disp(FilaLocal* fp, Disponibilidade* disp){
	int check = 0;
	NodeLocal* aux;
	int i = 0;

	if(fp == NULL)
		return NULL;
	if(FilaLocal_Is_Empty(fp))
		return NULL;

	aux = fp->first;

	while(aux != NULL && check == 0){
		for(i = 0; i < Local_Get_Disp_Size(NodeLocal_Get(aux)) && check == 0; i++){
			if(strcmp(Disponibilidade_Get_Data(Local_Get_Disp(NodeLocal_Get(aux))[i]), Disponibilidade_Get_Data(disp)) == 0)
				check = 1;
		}
		if(!check)
		    aux = NodeLocal_Get_Prox(aux);
	}
	if(check)
		return aux;

	return NULL;
}

NodeLocal* FilaLocal_Get_First(FilaLocal* f){
	return f->first;
}

NodeLocal* FilaLocal_Get_Last(FilaLocal* f){
	return f->last;
}

void FilaLocal_Print(FilaLocal* f){
	NodeLocal* aux;

	int i;

	if(f == NULL){
			printf("Fila nao inicializada");
			return;
	}
	if(FilaLocal_Is_Empty(f)){
		printf("Fila vazia.");
		return;
	}

	aux = f->first;

	while(aux != NULL){
	    printf("%s\n", Local_Get_Nome(NodeLocal_Get(aux)));
	    printf("%s\n", Local_Get_Endereco(NodeLocal_Get(aux)));
	    for(i = 0; i < Local_Get_Disp_Size(NodeLocal_Get(aux)); i++){
	    	printf("%s - %i:%i\n", Disponibilidade_Get_Data(Local_Get_Disp(NodeLocal_Get(aux))[i]), Disponibilidade_Get_Hora(Local_Get_Disp(NodeLocal_Get(aux))[i]),
	    			Disponibilidade_Get_Minuto(Local_Get_Disp(NodeLocal_Get(aux))[i]));
	    }
	    aux = NodeLocal_Get_Prox(aux);
	}
	return;
}

NodeLocalVector* FilaLocal_To_Vector(FilaLocal* f){
	NodeLocalVector* aux = NodeLocal_Vector_New();
	NodeLocal* nlaux;

	if(aux == NULL)
		return NULL;

	if(f == NULL)
		return NULL;

	nlaux = f->first;

	while(nlaux != NULL){
		NodeLocal_Vector_Add(nlaux, aux);
		nlaux = NodeLocal_Get_Prox(nlaux);
	}

	return aux;
}



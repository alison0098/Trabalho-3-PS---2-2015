/*
 * Fila_Palestra.c
 *
 *  Created on: 30/10/2015
 *      Author: Guilherme
 */

#include "../Headers/Fila_Palestra.h"
#include "../Headers/Nodo_Palestra.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct FilaPalestra{
	NodePalestra* first, *last;
} FilaPalestra;

void FilaPalestra_Add(NodePalestra* np, FilaPalestra* fp){
	if(FilaPalestra_Is_Empty(fp))
		fp->first = np;
	else
		NodePalestra_Set_Prox(fp->last, np);
	fp->last = np;
}

FilaPalestra* Fila_Palestra_New(){

	FilaPalestra* fp = (FilaPalestra*)malloc(sizeof(FilaPalestra));
	if(fp == NULL)
		return NULL;

	fp->first = NULL;
	fp->last = NULL;

	return fp;
}

int FilaPalestra_Is_Empty(FilaPalestra* fp){
	return fp->first == NULL;
}

FilaPalestra* FilaPalestra_Pop(FilaPalestra* fp){
	NodePalestra* aux, *temp;

	if(fp == NULL)
		return (FilaPalestra*)NULL;

	if(FilaPalestra_Is_Empty(fp)){
		free(fp);
		return (FilaPalestra*)NULL;
	}

	aux = fp->first;

	while(aux != NULL){
		temp = NodePalestra_Get_Prox(aux);
		
		free(aux);
		aux = temp;
	}

	free(fp);

	return (FilaPalestra*)NULL;
}

NodePalestra* FilaPalestra_Get(FilaPalestra* fp, char* nome){
	int check = 0;
	NodePalestra* aux;

	if(fp == NULL)
		return NULL;
	if(FilaPalestra_Is_Empty(fp))
		return NULL;

	aux = fp->first;

	while(aux != NULL && check == 0){
		if(strcmp(Palestra_Get_Nome(NodePalestra_Get(aux)), nome) == 0)
			check = 1;
		if(!check)
			aux = NodePalestra_Get_Prox(aux);
	}

	return aux;
}

NodePalestra* FilaPalestra_Get_With_Palestrante(FilaPalestra* fp, char* nome){
	int check = 0;
	NodePalestra* aux;

	if(fp == NULL)
		return NULL;
	if(FilaPalestra_Is_Empty(fp))
		return NULL;

	aux = fp->first;

	while(aux != NULL && check == 0){
		if(strcmp(Palestra_Get_Nome_Palestrante(NodePalestra_Get(aux)), nome) == 0)
			check = 1;
		if(!check)
			aux = NodePalestra_Get_Prox(aux);
	}

	return aux;
}

void FilaPalestra_Print(FilaPalestra* fp){
	NodePalestra* aux;
	if(fp == NULL){
		printf("Fila nao inicializada");
		return;
	}
	if(FilaPalestra_Is_Empty(fp)){
		printf("Fila vazia.");
		return;
	}

	aux = fp->first;

	while(aux != NULL){
		printf("%s\n", Palestra_Get_Nome(NodePalestra_Get(aux)));
		printf("%s\n", Palestra_Get_Nome_Palestrante(NodePalestra_Get(aux)));
		printf("%s\n", Palestra_Get_Tema(NodePalestra_Get(aux)));
		printf("%s\n", Palestra_Get_Local(NodePalestra_Get(aux)));
		printf("%d\n\n", Palestra_Get_Dur(NodePalestra_Get(aux)));
		aux = NodePalestra_Get_Prox(aux);
	}
	printf("Fila End\n\n");
	return;
}

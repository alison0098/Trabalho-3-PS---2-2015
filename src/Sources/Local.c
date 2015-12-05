/*
 * Local.c
 *
 *  Created on: 31/10/2015
 *      Author: Guilherme
 */
#include "../Headers/Local.h"
#include "../Headers/Disponibilidade.h"
#include <stdlib.h>
#include <string.h>

typedef struct Local{
	char nome[30];
	char endereco[30];
	Disponibilidade* disp[7];
	int disp_size;
}Local;

Local* Local_New(char* nome, char* endereco){
	Local* aux = (Local*)malloc(sizeof(Local));

	if(aux == NULL)
		return NULL;

	strcpy(aux->nome, nome);
	strcpy(aux->endereco, endereco);
	aux->disp_size = 0;

	return aux;
}

int Local_Get_Disp_Pos(Local*l , Disponibilidade* disp){
	int i, check = 0;
	for(i = 0; i < l->disp_size && check == 0; i++){
		if(strcmp(Disponibilidade_Get_Data(l->disp[i]), Disponibilidade_Get_Data(disp)))
			check = i;
	}
	return check;
}

void Local_Add_Disp(Local* l, Disponibilidade* disp){
	l->disp[l->disp_size] = disp;
	l->disp_size = l->disp_size + 1;
}

char* Local_Get_Nome(Local* l){
	return l->nome;
}

char* Local_Get_Endereco(Local* l){
	return l->endereco;
}

int Local_Get_Disp_Size(Local *l){
	return l->disp_size;
}

Disponibilidade** Local_Get_Disp(Local* l){
	return l->disp;
}

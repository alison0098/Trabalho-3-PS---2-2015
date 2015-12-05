/*
 * Palestrante.c
 *
 *  Created on: 01/11/2015
 *      Author: Guilherme
 */
#include "../Headers/Palestrante.h"
#include <stdlib.h>
#include <string.h>

struct Palestrante{
	char nome[50];
	Disponibilidade* disp[7];
	int disp_size;
};

char* Palestrante_Get_Nome(Palestrante* p){
	return p->nome;
}

Disponibilidade** Palestrante_Get_Disp(Palestrante* p){
	return p->disp;
}

Palestrante* Palestrante_New(char* nome){
	Palestrante* aux = (Palestrante*)malloc(sizeof(Palestrante));

	if(aux == NULL)
		return NULL;

	aux->disp_size = 0;
	strcpy(aux->nome, nome);

	return aux;
}

void Palestrante_Add_Disp(Palestrante* p, Disponibilidade* disp){
	p->disp[p->disp_size] = disp;
	p->disp_size++;
}

int Palestrante_Get_Disp_Size(Palestrante* p){
	return p->disp_size;
}



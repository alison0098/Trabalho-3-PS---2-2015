/*
 * Palestra.c
 *
 *  Created on: 29/10/2015
 *      Author: Okita
 */
#include "../Headers/Palestra.h"
#include <stdlib.h>
#include <string.h>

typedef struct Palestra{
	char nome[50];
	char palestrante[50];
	char local[25];
	char tema[75];
	int dur_min;
} Palestra;

char* Palestra_Get_Nome(Palestra* p){
	return p->nome;
}

int Palestra_Get_Dur(Palestra*p){
	return p->dur_min;
}

char* Palestra_Get_Nome_Palestrante(Palestra* p){
	return p->palestrante;
}

char* Palestra_Get_Local(Palestra* p){
	return p->local;
}

char* Palestra_Get_Tema(Palestra* p){
	return p->tema;
}

Palestra* Palestra_New(char* nome, char* palestrante, char* local, char* tema, int dur){
	Palestra* aux;

	aux = (Palestra*)malloc(sizeof(Palestra));

	strcpy(aux->nome, nome);
	strcpy(aux->palestrante, palestrante);
	strcpy(aux->local, local);
	strcpy(aux->tema, tema);
	aux->dur_min = dur;

	return aux;
}


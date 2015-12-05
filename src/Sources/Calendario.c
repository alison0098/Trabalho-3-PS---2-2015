/*
 * Calendario.c
 *
 *  Created on: 01/11/2015
 *      Author: Guilherme
 */

#include "../Headers/Calendario.h"
#include <stdlib.h>

struct Calendario{
	Palestrante *palestrante;
	Local* local;
	Palestra* palestra;
	Disponibilidade* disp;
};

Local* Calendario_Get_Local(Calendario* c){
    return c->local;
}

Palestra* Calendario_Get_Palestra(Calendario* c){
	return c->palestra;
}

Disponibilidade* Calendario_Get_Disponibilidade(Calendario* c){
	return c->disp;
}
Palestrante* Calendario_Get_Palestrante(Calendario* c){
	return c->palestrante;
}

Calendario* Calendario_New(Local* l, Palestra* p, Disponibilidade* disp, Palestrante* palestrante){
	Calendario* aux = (Calendario*)malloc(sizeof(Calendario));
	if(aux == NULL)
		return NULL;

	aux->local = l;
	aux->palestra = p;
	aux->disp = disp;
	aux->palestrante = palestrante;

	return aux;
}

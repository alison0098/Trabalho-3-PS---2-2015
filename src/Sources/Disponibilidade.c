/*
 * Disponibilidade.c
 *
 *  Created on: 31/10/2015
 *      Author: Guilherme
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct Disponibilidade{
	char data[14];
	char ds[6];
	int dia_sem;
	char hora, minuto;
	char hora_fim, minuto_fim;
} Disponibilidade;

int Disp_Comp(Disponibilidade* a, Disponibilidade* b){
	char aux[30], aux2[30];
	sprintf(aux, "%s%d%d",a->data, a->hora, a->minuto);
	sprintf(aux2, "%s%d%d",b->data, b->hora,b->minuto);
	return strcmp(aux, aux2);
}

char* Disponibilidade_Get_Data(Disponibilidade* disp){
	return disp->data;
}

char* Disponibilidade_Get_Dia_Semana(Disponibilidade* disp){
	return disp->ds;
}

int Disponibilidade_Get_Dia_Semana_Int(Disponibilidade* disp){
	return disp->dia_sem;
}

int Disponibilidade_Get_HM_Value(Disponibilidade* disp){
	return (disp->hora*60) + (disp->minuto);
}

int Disponibilidade_Get_HMF_Value(Disponibilidade* disp){
	return (disp->hora_fim*60) + (disp->minuto_fim);
}

char Disponibilidade_Get_Hora(Disponibilidade* disp){
	return disp->hora;
}

char Disponibilidade_Get_Minuto(Disponibilidade* disp){
	return disp->minuto;
}

char Disponibilidade_Get_HoraFim(Disponibilidade* disp){
	return disp->hora_fim;
}

char Disponibilidade_Get_MinutoFim(Disponibilidade* disp){
	return disp->minuto_fim;
}

int Disponibilidade_Get_Dur(Disponibilidade* disp){
	return (disp->hora_fim*60 + disp->minuto_fim) - (disp->hora*60 + disp->minuto);
}

int GetWeekDay(int y, int m, int d){
	int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

Disponibilidade* Disponibilidade_New(char* data, char* ds, char hora, char minuto, char horaf, char minf){
	Disponibilidade* aux = (Disponibilidade*)malloc(sizeof(Disponibilidade));
	int d,m,a;
	if(aux == NULL)
		return NULL;

	strcpy(aux->data, data);
	strcpy(aux->ds, ds);

	d = atoi(&data[0]);
	m = atoi(&data[3]);
	a = atoi(&data[6]);

	aux->dia_sem = GetWeekDay(a,m,d);


//dom seg ter qua qui sex sab
	 switch(ds[2]){
	 case 'm':
		 aux->dia_sem = 0;
		 break;
	 case 'g':
		 aux->dia_sem = 1;
		 break;
	 case 'r':
		 aux->dia_sem = 2;
		 break;
	 case 'a':
		 aux->dia_sem = 3;
		 break;
	 case 'i':
		 aux->dia_sem = 4;
		 break;
	 case 'x':
		 aux->dia_sem = 5;
		 break;
	 case 'b':
		 aux->dia_sem = 6;
		 break;
	 }

	 aux->hora = hora;
	 aux->minuto = minuto;
	 aux->hora_fim = horaf;
	 aux->minuto_fim = minf;

	 return aux;
}

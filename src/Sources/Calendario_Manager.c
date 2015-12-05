/*
 * Calendario_Manager.c
 *
 *  Created on: 01/11/2015
 *      Author: Guilherme
 */
#include <stdlib.h>
#include <stdio.h>

#include "../Headers/Calendario_Manager.h"

static FILE* arquivo_bom = NULL;
static int controle_vetor = 0;
static Calendario* vetor_acertado[20];

typedef struct Tree{
	Calendario* nodo;
	struct Tree* dir, *esq;
}Tree;

Tree* Tree_New(Calendario* nodo){
	Tree* aux = (Tree*)malloc(sizeof(Tree));
	aux->nodo = nodo;
	aux->dir = NULL;
	aux->esq = NULL;

	return aux;
}

void Tree_Add(Tree* arv, Calendario* nodo){
	if(arv != NULL){
		printf("%d",Disp_Comp(Calendario_Get_Disponibilidade(arv->nodo), Calendario_Get_Disponibilidade(nodo)));
		if(Disp_Comp(Calendario_Get_Disponibilidade(arv->nodo), Calendario_Get_Disponibilidade(nodo)) > 0){
			if(arv->esq != NULL)
				Tree_Add(arv->esq, nodo);
			else{
				arv->esq = (Tree*)malloc(sizeof(Tree));
				arv->esq->nodo = nodo;
				arv->esq->esq = NULL;
				arv->esq->dir = NULL;
			}
		}else if(Disp_Comp(Calendario_Get_Disponibilidade(arv->nodo), Calendario_Get_Disponibilidade(nodo)) < 0){
			if(arv->dir != NULL)
				Tree_Add(arv->dir, nodo);
			else{
				arv->dir = (Tree*)malloc(sizeof(Tree));
				arv->dir->nodo = nodo;
				arv->dir->esq = NULL;
				arv->dir->dir = NULL;
			}
		}
	}
}

void Tree_Fix_Vector(Tree* arv){
	if(arv->esq != NULL)
		Tree_Fix_Vector(arv->esq);
	vetor_acertado[controle_vetor] = arv->nodo;
	controle_vetor++;
	if(arv->dir != NULL)
		Tree_Fix_Vector(arv->dir);
}

void Tree_Del(Tree* arv){
	if(arv->esq != NULL)
	    Tree_Del(arv->esq);
	if(arv->dir != NULL)
	    Tree_Del(arv->dir);
	free(arv);
}

void Calendario_Manager_Initialize(){
	calendario = NULL;
	Calendario_Vector_Size = 0;
}

void Calendario_Manager_Add(Calendario* cal){
	if(cal == NULL)
		return;
	if(calendario == NULL){
		calendario = (Calendario**)malloc(sizeof(Calendario*));
		calendario[Calendario_Vector_Size] = cal;
		Calendario_Vector_Size++;
	}else{
		calendario = (Calendario**)realloc(calendario, (Calendario_Vector_Size + 1)*sizeof(Calendario*));
		calendario[Calendario_Vector_Size] = cal;
		Calendario_Vector_Size++;
	}
}

void Calendario_Manager_Print(){
	Tree* arvore;
	int size = 0, i, dia, check = 0, mes, checkm = 0, ano;
	Disponibilidade* disp;
	char data[15];
	Palestra* p;
	Local* l;
	Palestrante* p2;

	arquivo_bom = fopen("CalendarioPalestras.txt", "w");
	arvore = Tree_New(calendario[0]);
	for(i = 1; i < Calendario_Vector_Size; i++){
		Tree_Add(arvore, calendario[i]);
	}

	Tree_Fix_Vector(arvore);

	printf("%d", atoi(&Disponibilidade_Get_Data(Calendario_Get_Disponibilidade(vetor_acertado[0]))[2]));
	fprintf(arquivo_bom, "Calendario de Palestras (%d/%d - %d/%d)\n",
			atoi(&Disponibilidade_Get_Data(Calendario_Get_Disponibilidade(vetor_acertado[0]))[2]),
			atoi(&Disponibilidade_Get_Data(Calendario_Get_Disponibilidade(vetor_acertado[0]))[6]),
			atoi(&Disponibilidade_Get_Data(Calendario_Get_Disponibilidade(vetor_acertado[Calendario_Vector_Size - 1]))[2]),
		    atoi(&Disponibilidade_Get_Data(Calendario_Get_Disponibilidade(vetor_acertado[Calendario_Vector_Size - 1]))[6]));

	for(i = 0; i < Calendario_Vector_Size; i++){
	    	mes = atoi(&Disponibilidade_Get_Data(Calendario_Get_Disponibilidade(vetor_acertado[i]))[3]);
	    	ano = atoi(&Disponibilidade_Get_Data(Calendario_Get_Disponibilidade(vetor_acertado[i]))[6]);
	    	dia = atoi(&Disponibilidade_Get_Data(Calendario_Get_Disponibilidade(vetor_acertado[i]))[0]);
	    	p = Calendario_Get_Palestra(vetor_acertado[i]);
	    	l = Calendario_Get_Local(vetor_acertado[i]);
	    	p2 = Calendario_Get_Palestrante(vetor_acertado[i]);
	    	disp = Calendario_Get_Disponibilidade(vetor_acertado[i]);
	    	if(mes != checkm){
	    		fprintf(arquivo_bom, "Mes %d//%d\n", mes);
	    		checkm = mes;
	    	}
	    	if(dia != check){
	    		fprintf(arquivo_bom, "Dia %d\n", dia);
	    		check = dia;
	    	}
	    	fprintf(arquivo_bom, "%s(%s): %2d:%2d - %2d:%2d.\nLocal: %s\nEndereco: %s\n", Palestra_Get_Tema(p), Palestrante_Get_Nome(p2),
	    			Disponibilidade_Get_Hora(disp), Disponibilidade_Get_Minuto(disp),
					Disponibilidade_Get_Hora(disp) + Palestra_Get_Dur(p)/60, Disponibilidade_Get_Minuto(disp) + Palestra_Get_Dur(p)%60,
					Local_Get_Nome(l), Local_Get_Endereco(l));
	}
	Tree_Del(arvore);
	//free(arvore);
	fclose(arquivo_bom);
        free(calendario);
}

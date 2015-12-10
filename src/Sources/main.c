/*
 * main.c
 *
 *  Created on: 30/10/2015
 *      Author: Guilherme
 */

#include "../Headers/Palestra_Manager.h"
#include "../Headers/Palestrante_Manager.h"
#include "../Headers/Local_Manager.h"
#include "../Headers/Organizer.h"
#include "../Headers/Calendario_Manager.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	int escolha = 0;
	int valor = 0;

    if(PalestraManager_Read("palestras.txt") == 0){
		if(LocalManager_Read("local.txt") == 0){
			if(PalestranteManager_Read("palestrante.txt") == 0){
				Calendario_Manager_Initialize();

				Organizer_Organize_Filas(LocalManager_GetLocal(), PalestraManager_Get(), PalestranteManager_GetPalestrante());

				PalestraManager_Print();
				LocalManager_Print();
				PalestranteManager_Print();
				Calendario_Manager_Print();

				while(escolha != -1){
					printf("Menu:\n1 - Procurar por dia\n2 - Procurar por mes\n3 - Procurar por ano\n-1 - Sair\nEscolha: ");
					scanf("%d", &escolha);
					switch(escolha){
					case 1:
						printf("Dia a ser procurado: ");
						scanf("%d", &valor);
						Calendario_Manager_Search_By_Day(valor);
						break;
					case 2:
						printf("Mes a ser procurado: ");
						scanf("%d", &valor);
						Calendario_Manager_Search_By_Month(valor);
						break;
					case 3:
						printf("Ano a ser procurado: ");
						scanf("%d", &valor);
						Calendario_Manager_Search_By_Year(valor);
						break;
					}//switch
				}//while
			}//if palestrante
		  Calendario_Manager_Delete();
		 PalestranteManager_PopFila();
		}//if local
		LocalManager_PopFila();
    }//if palestra
    PalestraManager_PopFila();

    printf("Pressione qualquer tecla para finalizar\n");
    getchar();

	return 0;
}

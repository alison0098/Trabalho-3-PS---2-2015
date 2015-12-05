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
    PalestraManager_Read("palestras.txt");
    PalestraManager_Print();

    LocalManager_Read("local.txt");
    LocalManager_Print();

    PalestranteManager_Read("palestrante.txt");
    PalestranteManager_Print();

    Calendario_Manager_Initialize();

    Organizer_Organize_Filas(LocalManager_GetLocal(), PalestraManager_Get(), PalestranteManager_GetPalestrante());
    Calendario_Manager_Print();

    PalestraManager_PopFila();
    PalestranteManager_PopFila();
    LocalManager_PopFila();

	return 0;
}

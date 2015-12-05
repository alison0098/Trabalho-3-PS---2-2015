/*
 * Palestra_Manager.c
 *
 *  Created on: 30/10/2015
 *      Author: Guilherme
 */

#include "../Headers/Palestra_Manager.h"
#include "../Headers/Fila_Palestra.h"
#include <stdlib.h>
#include <stdio.h>


void PalestraManager_Initialize(){
	filaPalestra = Fila_Palestra_New();
}

FilaPalestra* PalestraManager_Get(){
	return filaPalestra;
}

void PalestraManager_Read(char* filename){
	char nome[50];
	char palestrante[50];
	char local[25];
	char tema[75];
	char dur[10];
	char c;
	int dur_min = 0, i;
	FILE *file;

	file = fopen(filename, "r");
	if(file == NULL)
		return;

	PalestraManager_Initialize();

	while(!feof(file)){
		for (i = 0; i < 6; i++)
			fscanf(file, "%c", &c);

		c = fgetc(file);
		i = 0;

		while(c != '.'){
 			if(c != ' '){
				nome[i] = c;
				i++;
			}
			c = fgetc(file);
		}
		nome[i] = 0;

		for(i = 0; i < 14; i++)
			fscanf(file, "%c", &c);

		i = 0;
		c = fgetc(file);
		while(c != '.'){

 			if(c != ' '){
				palestrante[i] = c;
				i++;
			}
		    
		    c = fgetc(file);
		}
		palestrante[i] = 0;

		for(i = 0; i < 7; i++)
			fscanf(file, "%c", &c);

		i = 0;
		c = fgetc(file);
		while(c != '.'){
			tema[i] = c;
			c = fgetc(file);
			i++;
		}
		tema[i] = 0;

		for(i = 0; i < 8; i++)
			fscanf(file, "%c", &c);

		i = 0;
		c = fgetc(file);
		while(c != '.'){
			local[i] = c;
			c = fgetc(file);
			i++;
		}

		local[i] = 0;

		for(i = 0; i < 9; i++)
			fscanf(file, "%c", &c);
		fgets(dur, 25, file);
		fscanf(file, "%c", &c);

		dur_min = (60*atoi(&dur[1])) + atoi(&dur[4]);

		FilaPalestra_Add(NodePalestra_New(Palestra_New(nome, palestrante, local, tema, dur_min)), filaPalestra);
	}

	fclose(file);
}



int PalestraManager_PopFila(){
	filaPalestra = FilaPalestra_Pop(filaPalestra);

	return filaPalestra == NULL;
}

void PalestraManager_Print(){
	FilaPalestra_Print(filaPalestra);
}

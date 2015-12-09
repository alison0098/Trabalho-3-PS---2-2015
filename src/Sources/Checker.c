/*
 * Checker.c
 *
 *  Created on: 09/12/2015
 *      Author: Okita
 */

#include "../Headers/Checker.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int Check_char(char c, char* filename){
	char file[100] = "Log_";
	FILE *arq;

	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 45 && c <= 63) || (c == ' '))
		return 1;

	strcat(file, filename);

	printf("Caracter invalido encontrado!\n");
	arq = fopen(file, "a");

	fprintf(arq, "Caracter invalido encontrado! %c\n", c);

	fclose(arq);
	return 0;
}

int Check_File(char* filename){
	char file[100] = "Log_";
	FILE *arq;

	arq = fopen(filename, "r+");

	if(arq == NULL){
		printf("Arquivo %s nao existe!\n", filename);
		return 0;
	}

	if(!feof(arq)){
		fclose(arq);
		return 1;
	}
	fclose(arq);

	strcat(file, filename);
	arq = fopen(file, "w");
	fprintf(arq, "Arquivo %s esta vazio!\n", filename);
	fclose(arq);

	return 0;
}

int Check_Date(char c, char* filename){
	char file[100] = "Log_";
	FILE *arq;

	if((c >= 47 &&c <= 58) || c == ' ' || c == ';' || c == '.')
		return 1;
	strcat(file, filename);

	printf("Caracter invalido encontrado!\n");
	arq = fopen(file, "a");

	fprintf(arq, "Caracter invalido encontrado! %c\n", c);
	fclose(arq);
    return 0;
}

int Check_Time(char c, char *filename){
	char file[100] = "Log_";
	FILE *arq;

	if((c >= 48 && c <= 58)|| c == ' ')
		return 1;

	strcat(file, filename);
	printf("Caracter invalido encontrado!\n");
	arq = fopen(file, "a");

	fprintf(arq, "Caracter invalido encontrado! %c\n", c);
	fclose(arq);
	return 0;
}

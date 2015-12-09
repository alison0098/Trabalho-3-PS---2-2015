/*
 * Local_Manager.c
 *
 *  Created on: 31/10/2015
 *      Author: Guilherme
 */

#include <stdlib.h>
#include <stdio.h>
#include "../Headers/Local_Manager.h"
#include "../Headers/Checker.h"

void LocalManager_Initialize(){
	if(filaLocal == NULL)
	    filaLocal = FilaLocal_New();
}

int LocalManager_Read(char* filename){
	char nome[30];
	char endereco[50];
	char data[13];
	char d_sem[6];
	char hinicio[9], hfim[9];
	char c;
	int i, hora, minuto, horafim, minutofim, diaS;

	FILE *file;
	if(Check_File(filename))
	    file = fopen(filename, "r");
	else
		return 1;

	LocalManager_Initialize();

	while(!feof(file)){
		for(i = 0; i < 6; i++)
			fscanf(file, "%c", &c);

		c = fgetc(file);
		i = 0;
		while(c != '.'){
			if(c != ' ' && Check_char(c, filename)){
			    nome[i] = c;
			    i++;
			}/*else if (c != ' ' && !Check_char(c, filename))
				return 2;*/

			c = fgetc(file);
		}
		nome[i] = 0;

		for(i = 0; i < 11; i++)
			fscanf(file, "%c", &c);

		i = 0;
		c = fgetc(file);
		while(c != '.'){
			if(c != ' ' && Check_char(c, filename)){
			    endereco[i] = c;
			    i++;
			}/*else if (c != ' ' && !Check_char(c, filename))
				return 3;
*/
			c = fgetc(file);
		}
		endereco[i] = 0;

		FilaLocal_Add(NodeLocal_New(Local_New(nome, endereco)), filaLocal);

		for(i = 0; i < 17; i++)
			fscanf(file, "%c", &c);

        c = 'a';

        while(c != '.'){
        	c = 'a';
        	c = fgetc(file);
        	while(c != ';' && c != '.'){
        		i = 0;
        		c = fgetc(file);
        		while(c != ','){
        			if(c != ' ' && Check_char(c, filename)){
        			    d_sem[i] = c;
        			    i++;
        			}/*else if (c != ' ' && !Check_char(c, filename))
        				return 4;*/
        			c = fgetc(file);
        		}
        		d_sem[i] = 0;
        		switch(d_sem[2]){
        		        		 case 'm':
        		        			 diaS = 0;
        		        			 break;
        		        		 case 'g':
        		        			 diaS = 1;
        		        			 break;
        		        		 case 'r':
        		        			 diaS = 2;
        		        			 break;
        		        		 case 'a':
        		        			 diaS = 3;
        		        			 break;
        		        		 case 'i':
        		        			 diaS = 4;
        		        			 break;
        		        		 case 'x':
        		        			 diaS = 5;
        		        			 break;
        		        		 case 'b':
        		        			 diaS = 6;
        		        			 break;
        		        		 }
        		i = 0;
        		c = fgetc(file);
        		while(c != ','){
        			if(c != ' ' && Check_Date(c, filename)){
        			    data[i] = c;
        			    i++;
        			}/*else if (c != ' ' && !Check_char(c, filename))
        				return 5;
*/
        			c = fgetc(file);
        		}
        		data[i] = 0;
        		i = 0;
        		c = fgetc(file);
        		while(c != '-'){
        			if(Check_Time(c, filename)){
        			    hinicio[i] = c;
						i++;
					}
        			/*else if(!Check_Time(c, filename))
        				return 6;*/
        			c = fgetc(file);
        			
        		}
        		hinicio[i] = 0;

        		i = 0;
        		do{
        			c = fgetc(file);
        			if(Check_Date(c, filename) || c == ';' || c == '.'){
        			    hfim[i] = c;
        			    i++;
        			}/*else if(!Check_Date(c, filename) && (c != ';' || c != '.'))
        				return 7;*/
        		}while(c != ';' && c != '.');

        		hfim[i] = 0;

        		hora = atoi(&hinicio[0]);
        		minuto = atoi(&hinicio[3]);
        		horafim = atoi(&hfim[0]);
        		minutofim = atoi(&hfim[3]);
        		Local_Add_Disp(NodeLocal_Get(FilaLocal_Get_Last(filaLocal)), Disponibilidade_New(data, d_sem, hora, minuto, horafim, minutofim));
        	}
        }
        c = fgetc(file);
	}
	fclose(file);
	return 0;
}

int LocalManager_PopFila(){
	if(filaLocal != NULL)
	    filaLocal = FilaLocal_Pop(filaLocal);

	return filaLocal == NULL;
}

void LocalManager_Print(){
	FilaLocal_Print(filaLocal);
}

FilaLocal* LocalManager_GetLocal(){
	return filaLocal;
}

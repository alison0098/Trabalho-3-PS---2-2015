/*
 * Organizer.c
 *
 *  Created on: 01/11/2015
 *      Author: Guilherme
 */

#include "../Headers/Organizer.h"
#include "../Headers/Disponibilidade.h"
#include "../Headers/Calendario_Manager.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void Organizer_Organize_Filas(FilaLocal* flocal, FilaPalestra* fpalestra, FilaPalestrante* fpalestrante){
	int i, j, check;
	char ds[6];
	Disponibilidade** disp;
	Disponibilidade** ldisp;
	NodeLocalVector* nlv;
	NodePalestranteVector* npv;
	NodePalestra* npa;
	Palestra* pa;
	int dia, mes, ano, hora, minuto, horaf, minutof, pos;
	NodeLocal* nl;
	NodePalestrante* np;
	Palestrante* p;
	Local* l;
	char data[15];

	nlv = FilaLocal_To_Vector(flocal);
	npv = FilaPalestrante_To_Vector(fpalestrante);

	for(i = 0; i < NodePalestrante_Vector_Get_Size(npv); i++){
		np = NodePalestrante_Vector_Get(npv, i);
		p = NodePalestrante_Get(np);

		npa = FilaPalestra_Get_With_Palestrante(fpalestra, Palestrante_Get_Nome(p));

		check = 0;
		disp = Palestrante_Get_Disp(p);
		for(j = 0; j < Palestrante_Get_Disp_Size(p) && check == 0; j++){
			nl = FilaLocal_Get_With_Disp(flocal, disp[j]);
			l = NodeLocal_Get(nl);

			if(nl != NULL){
				ldisp = Local_Get_Disp(l);
				pos = Local_Get_Disp_Pos(l, disp[j]);

				pa = NodePalestra_Get(npa);

				dia = atoi(&Disponibilidade_Get_Data(disp[j])[0]);
				mes = atoi(&Disponibilidade_Get_Data(disp[j])[3]);
				ano = atoi(&Disponibilidade_Get_Data(disp[j])[6]);

				if(dia == 0){
					printf("Arrumando o dia \n\n");
					while(GetWeekDay(ano, mes, dia) != Disponibilidade_Get_Dia_Semana_Int(disp[j])){
						dia++;
					}
				}
				if(Disponibilidade_Get_HM_Value(disp[j]) >= Disponibilidade_Get_HM_Value(ldisp[pos - 1])
				    && (Disponibilidade_Get_HM_Value(disp[j]) + Palestra_Get_Dur(pa)) <= Disponibilidade_Get_HMF_Value(ldisp[pos - 1])){
					check = 1;
				}
			}
		}
		if(check){
			if(dia < 10 && mes < 10)
			    sprintf(data, "0%d/0%d/%d", dia, mes, ano);
			if(dia < 10 && mes >= 10)
				sprintf(data, "0%d/%d/%d", dia, mes, ano);
			if(dia >= 10 && mes < 10)
				sprintf(data, "%d/0%d/%d", dia, mes, ano);
			if(dia >= 10 && mes >= 10)
				sprintf(data, "%d/%d/%d", dia, mes, ano);

			hora = Disponibilidade_Get_Hora(disp[j]);
			minuto = Disponibilidade_Get_Minuto(disp[j]);
			horaf = Disponibilidade_Get_HoraFim(disp[j]);
			minutof = Disponibilidade_Get_MinutoFim(disp[j]);
			strcpy(ds, Disponibilidade_Get_Dia_Semana(disp[j]));
			Calendario_Manager_Add(Calendario_New(l, pa, Disponibilidade_New(data, ds, hora, minuto, horaf, minutof), p));
		}
	}

	nlv = NodeLocal_Vector_Del(nlv);
	npv = NodePalestrante_Vector_Del(npv);
}


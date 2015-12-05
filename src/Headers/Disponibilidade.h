/*
 * Disponibilidade.h
 *
 *  Created on: 31/10/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_DISPONIBILIDADE_H_
#define HEADERS_DISPONIBILIDADE_H_

typedef struct Disponibilidade Disponibilidade;

char* Disponibilidade_Get_Data(Disponibilidade* disp);
char* Disponibilidade_Get_Dia_Semana(Disponibilidade* disp);
char Disponibilidade_Get_Hora(Disponibilidade* disp);
char Disponibilidade_Get_Minuto(Disponibilidade* disp);
char Disponibilidade_Get_HoraFim(Disponibilidade* disp);
char Disponibilidade_Get_MinutoFim(Disponibilidade* disp);
/**
 * Retorna uma instancia de Disponibilidade* inicializada.
 */
Disponibilidade* Disponibilidade_New(char* data, char* ds, char hora, char minuto, char horaf, char minf);
/**
 * Funcao que retorna o dia da semana. 
 * Funcao criada por Tomihiko Sakamoto.
 * @param y ano.
 * @param m mes.
 * @param d dia.
 */
int GetWeekDay(int y, int m, int d);

/**
 * Retorna um valor absoluto das horas e minutos.
 */
int Disponibilidade_Get_HMF_Value(Disponibilidade* disp);
/**
 * Retorna um valor absoluto das horas e minutos.
 */
int Disponibilidade_Get_HM_Value(Disponibilidade* disp);
/**
 * Retorna o valor inteiro do dia da semana.
 */
int Disponibilidade_Get_Dia_Semana_Int(Disponibilidade* disp);
/**
 * Compara duas Disponibilidades.
 */
int Disp_Comp(Disponibilidade* a, Disponibilidade* b);

#endif /* HEADERS_DISPONIBILIDADE_H_ */

/*
 * Organizer.h
 *
 *  Created on: 02/11/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_ORGANIZER_H_
#define HEADERS_ORGANIZER_H_
#include "Fila_Local.h"
#include "Fila_Palestra.h"
#include "Fila_Palestrante.h"
/**
 * Organiza as filas.
 * Organiza as filas fazendo consultas em cada uma e adicionando valores ao Calendario.
 */
void Organizer_Organize_Filas(FilaLocal* local, FilaPalestra* palestra, FilaPalestrante* palestrante);

#endif /* HEADERS_ORGANIZER_H_ */

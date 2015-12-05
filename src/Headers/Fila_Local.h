/*
 * Fila_Local.h
 *
 *  Created on: 31/10/2015
 *      Author: Guilherme
 */

#ifndef HEADERS_FILA_LOCAL_H_
#define HEADERS_FILA_LOCAL_H_

#include "Nodo_Local.h"
#include "Disponibilidade.h"

typedef struct FilaLocal FilaLocal;
/**
 * Retorna uma instancia da estrutura.
 */
FilaLocal* FilaLocal_New();
/**
 * Adiciona nodo.
 * @param node nodo a ser adicionado.
 * @param fila fila a qual sera adicionada o nodo.
 */
void FilaLocal_Add(NodeLocal* node, FilaLocal* fila);
/**
 * Checa se a fila esta vazia.
 */
int FilaLocal_Is_Empty(FilaLocal* fila);
/**
 * Deleta a fila.
 * @return NULL se bem sucedido.
 */
FilaLocal* FilaLocal_Pop(FilaLocal* fp);
/**
 * Pega um nodo.
 * a partir de um nome.
 * @param nome identificador.
 * @param fp fila a qual sera procurado o nome.
 * @return NULL se nao for encontrado, referencia ao nodo caso contrario.
 */
NodeLocal* FilaLocal_Get(FilaLocal* fp, char* nome);
/**
 * Escreve valores importantes na tela.
 * Percorre a fila escrevendo na dela os valores importantes.
 */
void FilaLocal_Print(FilaLocal* f);
/**
 * Retorna o primeiro valor da fila.
 */
NodeLocal* FilaLocal_Get_First(FilaLocal* f);
/**
 * Retorna o ultimo valor da fila.
 */
NodeLocal* FilaLocal_Get_Last(FilaLocal* f);
/**
 * Transforma a fila em um vetor.
 */
NodeLocalVector* FilaLocal_To_Vector(FilaLocal* f);

#endif /* HEADERS_FILA_LOCAL_H_ */

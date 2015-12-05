#ifndef HEADERS_FILA_PALESTRA_H_
#define HEADERS_FILA_PALESTRA_H_

#include "Nodo_Palestra.h"

typedef struct FilaPalestra FilaPalestra;

/**
 * Adiciona um nodo a fila.
 *
 * @param np    nodo a ser adicionado.
 * @param fp    fila a qual sera adicionado o nodo.
 */
void FilaPalestra_Add(NodePalestra* np, FilaPalestra* fp);
/**
 * Instancia a fila.
 *
 * @return retorna um ponteiro para a fila instanciada.
 */
FilaPalestra* Fila_Palestra_New();
/**
 * Checa se a lista esta vazia.
 *
 * @param fp    fila a qual sera verificada a existencia de valores.
 */
int FilaPalestra_Is_Empty(FilaPalestra* fp);
/**
 * Deleta todos os valores da fila.
 *
 * @param fp   fila a qual sera deletados todos os nodos.
 * @return retorna NULL.
 */
FilaPalestra* FilaPalestra_Pop(FilaPalestra* fp);
/**
 * Retorna um ponteiro para o nodo que contem a chave.
 *
 * @param fp    fila a qual sera procurado a chave.
 * @param nome  chave que servira para procurar o nodo.
 * @return retorna um ponteiro para o nodo que contem a chave ou se nao retorna null.
 */
NodePalestra* FilaPalestra_Get(FilaPalestra* fp, char* nome);
/**
 * Imprime os valores contidos em palestra.
 */
void FilaPalestra_Print(FilaPalestra* fp);

NodePalestra* FilaPalestra_Get_With_Palestrante(FilaPalestra* fp, char* nome);

#endif

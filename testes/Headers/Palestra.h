#ifndef HEADERS_PALESTRA_H_
#define HEADERS_PALESTRA_H_

typedef struct Palestra Palestra;

/**
 * Retorna o nome.
 */
char* Palestra_Get_Nome(Palestra* p);
/**
 * Retorna a duracao em minutos.
 */
int Palestra_Get_Dur(Palestra*p);
/**
 * Retorna o nome do palestrante.
 */
char* Palestra_Get_Nome_Palestrante(Palestra* p);
/**
 * Retorna o local.
 */
char* Palestra_Get_Local(Palestra* p);
/**
 * Retorna o tema.
 */
char* Palestra_Get_Tema(Palestra* p);
/**
 * Retorna uma Palestra instanciada.
 */
Palestra* Palestra_New(char* nome, char* palestrante, char* local, char* tema, int dur);

#endif /* HEADERS_PALESTRA_H_ */

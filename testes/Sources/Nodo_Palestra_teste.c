#include "../Headers/Local.h"
#include "../Headers/Disponibilidade.h"
#include <stdlib.h>
#include <string.h>
#include "Nodo_Palestra.c"

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

void adicionar_testes_Nodo_Palestra(void);

/*Abaixo esta a funçao que efetua os testes para a função NodePalestra_New*/
void teste_DT_NodePalestra_New_NULL(void);

/*Abaixo esta a funçao que efetua os testes para a função NodePalestra_Get_Prox*/
void teste_DT_NodePalestra_Get_Prox_NULL(void);

void adicionar_testes_Nodo_Palestra(void){
	CU_pSuite suite;

	/*Cria uma suite que conterá todos os testes*/
	suite = CU_add_suite("Testes do Nodo_Palestra.c",NULL,NULL);


	/*Adiciona os testes para a função DT_data_valida*/
	CU_ADD_TEST(suite, teste_DT_NodePalestra_New_NULL);
	CU_ADD_TEST(suite, teste_DT_NodePalestra_Get_Prox_NULL);

}

int main(void){
	/*Inicializa o registro de suítes e testes do CUnit*/
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();

    /*Adiciona os testes ao registro*/
   	adicionar_testes_Nodo_Palestra();
	/*Muda o modo do CUnit para o modo VERBOSE
	 O modo VERBOSE mostra algumas informacoes a
	 mais na hora da execucao*/
	CU_basic_set_mode(CU_BRM_VERBOSE);
	/*Roda os testes e mostra na tela os resultados*/
	CU_basic_run_tests();
	/*Limpa o registro*/
	CU_cleanup_registry();
	return CU_get_error();
}

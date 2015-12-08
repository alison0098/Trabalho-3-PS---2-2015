#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/Fila_Local.h"
#include "Fila_Local.c"

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

void adicionar_testes_Fila_Local(void);

/*Abaixo esta a funçao que efetua os testes para a função FilaLocal_New*/
void teste_DT_FilaLocal_New_NULL(void);

/*Abaixo esta a funçao que efetua os testes para a função FilaLocal_Pop*/
void teste_DT_FilaLocal_Pop_NULL(void);

/*Abaixo esta a funçao que efetua os testes para a função FilaLocal_To_Vector*/
void teste_DT_FilaLocal_To_Vector_NULL(void);

/*Testes FilaLocal*/

void teste_DT_FilaLocal_New_NULL(void){
  FilaLocal* aux;
  aux = FilaLocal_New();
  CU_ASSERT_PTR_NOT_NULL(aux);
}

void teste_DT_FilaLocal_Pop_NULL(void){
  FilaLocal* aux = (FilaLocal*)malloc(sizeof(FilaLocal));
  aux = FilaLocal_Pop(aux);
  CU_ASSERT_PTR_NULL(aux);
}

void teste_DT_FilaLocal_To_Vector_NULL(void){
  FilaLocal* aux = (FilaLocal*)malloc(sizeof(FilaLocal));
  NodeLocalVector* aux2;
  aux2 = FilaLocal_To_Vector(aux);
  CU_ASSERT_PTR_NOT_NULL(aux2);
}

void adicionar_testes_Fila_Local(void){
	CU_pSuite suite;

	/*Cria uma suite que conterá todos os testes*/
	suite = CU_add_suite("Testes do Fila_Local.c",NULL,NULL);


	/*Adiciona os testes para a função DT_data_valida*/
	CU_ADD_TEST(suite, teste_DT_FilaLocal_New_NULL);
	CU_ADD_TEST(suite, teste_DT_FilaLocal_Pop_NULL);
  CU_ADD_TEST(suite, teste_DT_FilaLocal_To_Vector_NULL);

}

int main(void){
	/*Inicializa o registro de suítes e testes do CUnit*/
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();

    /*Adiciona os testes ao registro*/
   	adicionar_testes_Fila_Local();
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

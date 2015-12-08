#include "../Headers/Local.h"
#include "../Headers/Disponibilidade.h"
#include <stdlib.h>
#include <string.h>
#include "Nodo_Local.c"

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

void adicionar_testes_Nodo_Local(void);

/*Abaixo esta a funçao que efetua os testes para a função NodeLocal_Vector_New*/
void teste_DT_NodeLocal_Vector_New_NULL(void);

/*Abaixo esta a funçao que efetua os testes para a função NodeLocal_New*/
void teste_DT_NodeLocal_New_NULL(void);

/*Abaixo esta a funçao que efetua os testes para a função NodeLocal_Vector_Get_Size*/
void teste_DT_NodeLocal_Vector_Get_Size_0(void);

/*Teste ponteiro NULL*/
void teste_DT_NodeLocal_Vector_New_NULL(void){
    NodeLocalVector* aux;
    aux = NodeLocal_Vector_New();
    CU_ASSERT_PTR_NOT_NULL(aux);
}

void teste_DT_NodeLocal_New_NULL(void){
    NodeLocal* aux;
    aux = NodeLocal_New(aux);
    CU_ASSERT_PTR_NOT_NULL(aux);
}

/*Teste tamanho 0*/
void teste_DT_NodeLocal_Vector_Get_Size_0(void){
    NodeLocalVector* aux = (NodeLocalVector*)malloc(sizeof(NodeLocalVector));
    aux->size = 0;
    int nv;
    nv = NodeLocal_Vector_Get_Size(aux);
    CU_ASSERT_TRUE(!nv);
}

void  adicionar_testes_Nodo_Local(void){
	CU_pSuite suite;

	/*Cria uma suite que conterá todos os testes*/
	suite = CU_add_suite("Testes do Nodo_Local.c",NULL,NULL);


	/*Adiciona os testes para a função DT_data_valida*/
	CU_ADD_TEST(suite, teste_DT_NodeLocal_Vector_New_NULL);
    CU_ADD_TEST(suite, NodeLocal_New_NULL);
    CU_ADD_TEST(suite, teste_DT_NodeLocal_Vector_Get_Size_0);
}

int main(void){
	/*Inicializa o registro de suítes e testes do CUnit*/
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();

    /*Adiciona os testes ao registro*/
   	adicionar_testes_Nodo_Local();
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

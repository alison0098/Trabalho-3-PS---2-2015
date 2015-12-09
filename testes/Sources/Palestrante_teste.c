#include "../Headers/Local.h"
#include "../Headers/Disponibilidade.h"
#include <stdlib.h>
#include <string.h>
#include "Palestrante.c"

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

void adicionar_testes_Palestrante(void);

/*Abaixo esta a funçao que efetua os testes para a função Palestrante_New*/
void teste_DT_Palestrante_New_NULL(void);

/*Abaixo esta a funçao que efetua os testes para a função Palestrante_Get_Nome*/
void teste_DT_Palestrante_Get_Nome_TRUE(void);

/*Teste ptr NULL*/
void teste_DT_Palestrante_New_NULL{
  Palestrante* aux;
  aux = Palestante_New('nome');
  CU_ASSERT_PTR_NOT_NULL(aux);
  free(aux);
}

/*Teste string TRUE*/
void teste_DT_Palestrante_Get_Nome_TRUE{
  Palestrante* aux;
  aux = Palestante_New('nome');
  CU_ASSERT_STRING_EQUAL(Palestrante_Get_Nome(aux), 'nome');
  free(aux);
}

void adicionar_testes_Palestrante(void){
	CU_pSuite suite;

	/*Cria uma suite que conterá todos os testes*/
	suite = CU_add_suite("Testes do Palestrante.c",NULL,NULL);


	/*Adiciona os testes para a função DT_data_valida*/
	CU_ADD_TEST(suite, teste_DT_Palestrante_New_NULL);
	CU_ADD_TEST(suite, teste_DT_Palestrante_Get_Nome_TRUE);

}

int main(void){
	/*Inicializa o registro de suítes e testes do CUnit*/
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();

    /*Adiciona os testes ao registro*/
   	adicionar_testes_Palestrante();
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

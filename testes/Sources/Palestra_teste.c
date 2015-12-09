#include "../Headers/Local.h"
#include "../Headers/Disponibilidade.h"
#include <stdlib.h>
#include <string.h>
#include "Palestra.c"

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

void adicionar_testes_Palestra(void);

/*Abaixo estao as funçoes que efetuam os testes para a função Palestra_Get*/
void teste_DT_Palestra_Get_Nome_TRUE(void);
void teste_DT_Palestra_Get_Dur_TRUE(void);
void teste_DT_Palestra_Get_Nome_Palestrante_TRUE(void);
void teste_DT_Palestra_Get_Local_TRUE(void);
void teste_DT_Palestra_Get_Tema_TRUE(void);

/*Abaixo esta a funçao que efetua os testes para a função Palestra_New*/
void teste_DT_Palestra_New_NULL(void);

/*Teste ponteiro NULL*/
void teste_DT_Palestra_New_NULL(void){
  Palestra* aux;
  aux = Palestra_New('nome', 'palestrante', 'local', 'tema', 10);
  CU_ASSERT_PTR_NOT_NULL(aux);
}

/*Teste Get*/
void teste_DT_Palestra_Get_Nome_TRUE{
  Palestra* aux;
  aux = Palestra_New('nome', 'palestrante', 'local', 'tema', 10);
  CU_ASSERT_STRING_EQUAL(Palestra_Get_Nome(aux), 'nome');
  free(aux);
}

void teste_DT_Palestra_Get_Dur_TRUE{
  Palestra* aux;
  aux = Palestra_New('nome', 'palestrante', 'local', 'tema', 10);
  CU_ASSERT_TRUE(Palestra_Get_Dur(aux);
  free(aux);
}

void teste_DT_Palestra_Get_Nome_Palestrante_TRUE{
  Palestra* aux;
  aux = Palestra_New('nome', 'palestrante', 'local', 'tema', 10);
  CU_ASSERT_STRING_EQUAL(Palestra_Get_Nome_Palestrante(aux), 'palestrante');
  free(aux);
}

void teste_DT_Palestra_Get_Local_TRUE{
  Palestra* aux;
  aux = Palestra_New('nome', 'palestrante', 'local', 'tema', 10);
  CU_ASSERT_STRING_EQUAL(Palestra_Get_Local(aux), 'local');
  free(aux);
}

void teste_DT_Palestra_Get_Tema_TRUE{
  Palestra* aux;
  aux = Palestra_New('nome', 'palestrante', 'local', 'tema', 10);
  CU_ASSERT_STRING_EQUAL(Palestra_Get_Tema(aux), 'tema');
  free(aux);
}

void adicionar_testes_Palestra(void){
	CU_pSuite suite;

	/*Cria uma suite que conterá todos os testes*/
	suite = CU_add_suite("Testes de Palestra.c",NULL,NULL);


	/*Adiciona os testes para a função DT_data_valida*/
	CU_ADD_TEST(suite, teste_DT_Palestra_Get_Nome_TRUE);
	CU_ADD_TEST(suite, teste_DT_Palestra_Get_Dur_TRUE);
	CU_ADD_TEST(suite, teste_DT_Palestra_Get_Nome_Palestrante_TRUE);
	CU_ADD_TEST(suite, teste_DT_Palestra_Get_Local_TRUE);
	CU_ADD_TEST(suite, teste_DT_Palestra_Get_Tema_TRUE);
	CU_ADD_TEST(suite, teste_DT_Palestra_New_NULL);
	

}

int main(void){
	/*Inicializa o registro de suítes e testes do CUnit*/
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();

    /*Adiciona os testes ao registro*/
   	adicionar_testes_Palestra();
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

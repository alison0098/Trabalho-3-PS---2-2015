#include "../Headers/Local.h"
#include "../Headers/Disponibilidade.h"
#include <stdlib.h>
#include <string.h>
#include "Calendario.c"

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

void adicionar_testes_Calendario(void);

/*Abaixo esta a funçao que efetua os testes para a função Calendario_New*/
void teste_DT_Calendario_New_NULL(void);

/*Teste ptr NULL*/
void teste_DT_Calendario_New_NULL(void){
  Calendario* aux;
  Local* l = (Local*)malloc(sizeof(Local));
  Palestra* p = (Palestra*)malloc(sizeof(Palestra));
  Disponibilidade* disp = (Disponibilidade*)malloc(sizeof(Disponibilidade));
  Palestrante* palestrante = (Palestrante*)malloc(sizeof(Palestrante));
  aux = Calendario_New(l, p, disp, palestrante);
  CU_ASSERT_PTR_NOT_NULL(aux);
  free(aux);
  free(l);
  free(p);
  free(disp);
  free(palestrante);
}

void adicionar_testes_Calendario(void){
	CU_pSuite suite;

	/*Cria uma suite que conterá todos os testes*/
	suite = CU_add_suite("Testes do Calendario.c",NULL,NULL);


	/*Adiciona os testes para a função DT_data_valida*/
	CU_ADD_TEST(suite, teste_DT_Calendario_New_NULL);

}

int main(void){
	/*Inicializa o registro de suítes e testes do CUnit*/
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();

    /*Adiciona os testes ao registro*/
   	adicionar_testes_Calendario();
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

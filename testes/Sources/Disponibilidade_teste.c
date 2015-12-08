#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "Disponibilidade.c"

void adicionar_testes_Disponibilidade(void);

/*Abaixo estão as funções que efetuam os testes para a função Disp_Comp*/
void teste_DT_Disp_Comp_Menor(void);
void teste_DT_Disp_Comp_Maior(void);
void teste_DT_Disp_Comp_Igual(void);

/*Abaixo estão as funções que efetuam os testes para a função Disponibilidade_New*/
void teste_DT_Disponibilidade_New_NULL(void);


/*Teste funções Disp_comp*/
void teste_DT_Disp_Comp_Menor(void){
  int aux;
  Disponibilidade* a = (Disponibilidade*)malloc(sizeof(Disponibilidade));
  Disponibilidade* b = (Disponibilidade*)malloc(sizeof(Disponibilidade));
  a->data = '2015';
  a->hora = '10';
  a->minuto = '05';
  b->data = '2015';
  b->hora = '21';
  b->minuto = '15';
  aux = Disp_Comp(a, b);
  CU_ASSERT_EQUAL(aux, -1);
}

void teste_DT_Disp_Comp_Maior(void){
  int aux;
  Disponibilidade* a = (Disponibilidade*)malloc(sizeof(Disponibilidade));
  Disponibilidade* b = (Disponibilidade*)malloc(sizeof(Disponibilidade));
  a->data = '2015';
  a->hora = '21';
  a->minuto = '15';
  b->data = '2015';
  b->hora = '10';
  b->minuto = '05';
  aux = Disp_Comp(a, b);
  CU_ASSERT_EQUAL(aux, 1);
}

/*Teste ponteiro NULL*/
void teste_DT_Disponibilidade_New_NULL(void){
  Disponibilidade* aux;
  aux = Disponibilidade_New('2015', 'Ter', '21', '10', '22', '20');
  CU_ASSERT_PTR_NOT_NULL(aux);
}


void teste_DT_Disp_Comp_Igual(void){
  int aux;
  Disponibilidade* a = (Disponibilidade*)malloc(sizeof(Disponibilidade));
  Disponibilidade* b = (Disponibilidade*)malloc(sizeof(Disponibilidade));
  a->data = '2015';
  a->hora = '21';
  a->minuto = '15';
  b->data = '2015';
  b->hora = '21';
  b->minuto = '15';
  aux = Disp_Comp(a, b);
  CU_ASSERT_EQUAL(aux, 0);
}


void  adicionar_testes_Disponibilidade(void){
	CU_pSuite suite;

	/*Cria uma suite que conterá todos os testes*/
	suite = CU_add_suite("Testes da Disponibilidade",NULL,NULL);


	/*Adiciona os testes para a função DT_data_valida*/
	CU_ADD_TEST(suite, teste_DT_Disp_Comp_Menor);
    CU_ADD_TEST(suite, teste_DT_Disp_Comp_Maior);
    CU_ADD_TEST(suite, teste_DT_Disp_Comp_Igual);
    CU_ADD_TEST(suite, teste_DT_Disponibilidade_New_NULL);
}

int main(void){
	/*Inicializa o registro de suítes e testes do CUnit*/
	if (CUE_SUCCESS != CU_initialize_registry())
    	return CU_get_error();

    /*Adiciona os testes ao registro*/
   	adicionar_testes_Disponibilidade();
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

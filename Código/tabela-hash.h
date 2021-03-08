#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

typedef struct elemento{
	int num;
	struct elemento *proximo;
} Elemento;

typedef struct lista{
	Elemento *comeco;
} Lista;

Lista* criar_lista();
int Vazia(Lista* l);
int descobrir_indice(int tam, int y);
int inserir_num(Lista* l,int pos,int y);
int remover_num(Lista* l,int pos,int z);
void pesquisa_num(Lista* l,int pos,int y);
void excluir_lista(Lista* l);

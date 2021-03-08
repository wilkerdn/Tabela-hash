#include "tabela-hash.h"

Lista *criar_lista(){
	Lista* l;
	l = malloc(sizeof(Lista));

	l->comeco = NULL;

	return l;
}

int Vazia(Lista* l){
	if(l->comeco==NULL){
		return 1;
	}else
		return 0;
}

int descobrir_indice(int tam,int y){
	return (y%tam);
}

int inserir_num(Lista* l,int pos,int y){
	Elemento *novo = malloc(sizeof(Elemento));
	Elemento *temp;
	int i;
	novo->num = y;

	if(Vazia(l)==1){
		novo->proximo = l->comeco;
		l->comeco = novo;
	}else if(Vazia(l)!=1){
		temp = l->comeco;
		for(i=1;i<pos;i++){
			if(temp->proximo==NULL){
				break;
			}else
				temp = temp->proximo;
		}
	}
	novo->proximo = temp->proximo;
	temp->proximo = novo;

	return 1;
}

int remover_num(Lista* l,int pos,int z){
	Elemento *temp;
	Elemento *excluir;
	int i=0,verif=0;

	if(Vazia(l)!=1){
		temp = l->comeco;
		if(pos==1){
			excluir = temp;
			temp = NULL;
			printf("O valor %d foi excluido\n",excluir->num);
			free(excluir);
			return 1;
		}else if(temp->num == z){
			excluir = temp;
			l->comeco = temp->proximo;
			printf("O valor %d foi excluido\n",excluir->num);
			free(excluir);
			return 1;
		}else
		for(i=0;i<pos;i++){
				if(temp->proximo==NULL){
				break;
				}else if(temp->proximo->num==z){
				verif = 2;
				break;
				}
			}
		}
		if(verif == 2){
			excluir = temp->proximo;
			temp->proximo = excluir->proximo;
			printf("O valor %d foi excluido\n",excluir->num);
			free(excluir);
			return 1;
		}else
		printf("O valor %d nao esta presente na tabela\n",z);
		return 0;
}

void pesquisa_num(Lista* l,int pos, int y){
	Elemento *aux;
	int i=0,not=1;
		aux = l->comeco;
		for(i=0;i<pos;i++){
			if(aux->num==y){
			printf("Elemento %d encontrado\n",aux->num);
			not = 0;
			break;
			}else if(aux->proximo==NULL){
				break;
			}else
			aux = aux->proximo;
		}
		if(not==1){
			printf("Elemento %d nao encontrado\n",y);
		}
}

void excluir_lista(Lista* l){
	free(l);
	l->comeco = NULL;
}


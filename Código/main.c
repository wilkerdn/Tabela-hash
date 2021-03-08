#include "tabela-hash.h"

int main(int argc, char** argv){
	int tam=0,i=0,repeat=1,opcao=0,x=0,ind=0;
	printf("Digite o tamanho da tabela = ");
	scanf("%d",&tam);
	
	Lista* tabela[tam];
	int posicao[tam];

	for(i=0;i<tam;i++){
		tabela[i] = criar_lista();
		posicao[i] = 0;
	}

	while(repeat == 1){

		printf("Inserir numero = 1\n");
		printf("Remover numero = 2\n");
		printf("Buscar numero = 3\n");
		printf("Deletar tabela = 4\n");
		printf("\nDigite a opcao = ");
		scanf("%d",&opcao);

		if(opcao == 1){
			printf("\nDigite o valor para ser inserido = ");
			scanf("%d",&x);
			ind = descobrir_indice(tam,x);
			inserir_num(tabela[ind],posicao[ind],x);
			posicao[ind] ++;
			printf("\n");
			repeat = 1;		
		}else if(opcao == 2){
			printf("\nDigite o valor para ser removido = ");
			scanf("%d",&x);
			ind = descobrir_indice(tam,x);
			if(remover_num(tabela[ind],posicao[ind],x)==1){
			posicao[ind]--;
			}
			printf("\n");
			repeat = 1;
		}else if(opcao == 3){
			printf("\nDigite o valor para ser pesquisado = ");
			scanf("%d",&x);
			ind = descobrir_indice(tam,x);
			pesquisa_num(tabela[ind],posicao[ind],x);
			printf("\n");
			repeat = 1;
		}else if(opcao == 4){
			for(i=0;i<tam;i++){
				excluir_lista(tabela[i]);
			}
			printf("\nTabela deletada\n");
			repeat = 0;
		}else{
			printf("\nOpcao invalida, digite novamente\n\n");
			repeat = 1;
		}
	}
	return 0;
}	

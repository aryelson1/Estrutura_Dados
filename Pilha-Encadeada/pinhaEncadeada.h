#include <stdio.h>
#include <stdlib.h>

typedef struct nopilha {
	int dado;	
	struct nopilha *prox; 
}no;
typedef no* TPilhaEnc;



/* Criar uma pilha vazia */
void criarPilha( TPilhaEnc *pilha );

/* Verificar se a pilha estÃ¡ vazia ou nÃ£o */
int pilhaVazia( TPilhaEnc pilha );

/* Tamanho da pilha */
int tamanhoPilha( TPilhaEnc pilha );

/* Empilhar um elemento */
int empilhar( TPilhaEnc *pilha, int dado );

/* Desempilhar um elemento */
int desempilhar( TPilhaEnc *pilha, int *dado );

/* Consultar o topo pilha */
int elementoTopo( TPilhaEnc pilha, int *dado );
/*Faz a união entre duas pinhas */
int mergePilhas(TPilhaEnc *pilha1, TPilhaEnc *pilha2 );
/* Exibir todos os elementos da pilha */
int imprimir ( TPilhaEnc pilha, int valor );
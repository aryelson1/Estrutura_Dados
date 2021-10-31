#include "pinhaEncadeada.h"


void criarPilha( TPilhaEnc *pilha )
{
	*pilha = NULL;
}

/* Verificar se a pilha estÃ¡ vazia ou nÃ£o */
int pilhaVazia( TPilhaEnc pilha )
{
	return pilha == NULL;
}

/* Tamanho da pilha */
int tamanhoPilha( TPilhaEnc pilha )
{
	int tamanho = 0;
	while( pilha != NULL ) {
		pilha = pilha->prox;
		tamanho++;
	}
	return tamanho;
}

/* Empilhar um elemento */
int empilhar( TPilhaEnc *pilha, int dado )
{
	TPilhaEnc novo;

	// aloca o no e testa pra ver se o SO alocou mesmo
	if( (novo = (no*) malloc(sizeof(no))) == NULL ) return 0;

	novo->dado = dado;
	novo->prox = *pilha;
	*pilha = novo;
	return 1;
}

/* Desempilhar um elemento */
int desempilhar( TPilhaEnc *pilha, int *dado )
{
	// se pilha estÃ¡ vazia
   	if ( pilhaVazia( *pilha ) ) return 0;

	TPilhaEnc aux;

	aux = *pilha;
	*dado = aux->dado;
	*pilha = (*pilha)->prox;
	
	// libera memÃ³ria do nÃ³ desempilhado
	free( aux );

    return 1;
}
/* Junta duas pinhas*/
int mergePilhas( TPilhaEnc* pilha1 , TPilhaEnc* pilha2){
  	if ( pilhaVazia( *pilha1 ) && pilhaVazia(*pilha2)) return 0;
    TPilhaEnc aux;
	  aux = *pilha1;
    if( aux == NULL ) return 0;
	  while( aux != NULL ) {
      if (pilha1 != NULL) empilhar(pilha2, aux->dado);
		  aux = aux->prox;  	
	}
  return 1;
  free(aux);
}

/* Consultar o topo pilha */
int elementoTopo( TPilhaEnc pilha, int *dado )
{
	if( pilhaVazia( pilha ) ) return 0;

	*dado = pilha->dado; // jÃ¡ que topo Ã© igual ao primeiro no
	return 1;
}

/* Exibir todos os elementos da pilha */
int imprimir ( TPilhaEnc pilha , int valor)
{
	// se pilha estÃ¡ vazia
   	if ( pilhaVazia( pilha ) ) return 0;

    printf("\n Pilha %d =[ ",valor);

	// varrendo todos os elementos
	while( !pilhaVazia(pilha) ){
		printf("%d ", pilha->dado);
		pilha = pilha->prox;
	}

    printf("]\n");
     return 1;
}
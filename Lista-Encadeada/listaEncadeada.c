#include "listaEncadeada.h"

listaEncadeada aloca();

void construtor( listaEncadeada *lista ){ *lista = NULL; }

int listaVazia( listaEncadeada lista ){ return lista == NULL; }

int tamanhoLista( listaEncadeada lista ){
	int tamanho = 0;
    while( lista != NULL ) {
    	lista = lista->prox;
        tamanho++;
    }
    return tamanho;
}
void NumeroDeOcorrencia( listaEncadeada lista, int elemento ){
    int ocorrencias = 0;

    while ( lista != NULL ) {
   		if ( elemento == lista->dado ) {
         ocorrencias++;
       }
	    
    	lista = lista->prox;
    }

    if(ocorrencias == 0){
      printf("Zero Ocorrencias do elemento %d na lista !\n",elemento);
    }else{
      printf("%d Ocorrencias do Elemento %d na lista !\n",ocorrencias,elemento);
    }
}

int addInicio( listaEncadeada* lista, int elemento ){
    listaEncadeada novo = NULL;
    
    if( listaVazia( *lista ) ) {
		// alocar o no e testar pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;
        novo->dado = elemento;
        novo->prox = NULL;
        novo->ant = NULL;
        *lista = novo;
        return 1;
    }
   
    	// alocar o no e testar pra ver se tudo correu bem
        if( ( novo = aloca() ) == NULL ) return 0;

        novo->dado = elemento;
        novo->prox = *lista; 
        novo->ant = NULL;
        (*lista)->ant = novo;
        *lista = novo;
        return 1;
    
}
int addFim( listaEncadeada* lista, int elemento ){
	listaEncadeada novo = NULL, aux = NULL;
  int tam = tamanhoLista(*lista);
    int contador = 1;

    if( tam == 0 ){
        addInicio(lista,elemento);
        return 1;
   	}

    
    aux = *lista;
    while( ( contador < tam  ) && ( aux != NULL ) ) {
    	aux = aux->prox;
      contador++;
    }

    if( aux == NULL ) return 0;
    if( ( novo = aloca() ) == NULL ) return 0;
    novo->dado = elemento;
    novo->prox = NULL;
    novo->ant = aux;

    aux->prox = novo;
    return 1;
}

int removerInicio( listaEncadeada* lista, int *dado ){
	  
    listaEncadeada aux = NULL;
    if ( listaVazia( *lista ) ) return 0;
    aux = *lista;

    if ( aux == NULL ) return 0;
    *dado = aux->dado;
    *lista = aux->prox;
    if( aux->prox != NULL )	aux->prox->ant = NULL;// SE TEM MAIS DE 1 ELEMENTO NA LISTA
    
    free(aux);

    return 1;
}

int removerFim( listaEncadeada* lista, int *dado ){
	  listaEncadeada aux = NULL;
    
    int tam = tamanhoLista(*lista);
    int contador = 1;

    if ( listaVazia( *lista ) ) return 0;
    aux = *lista;

    while( ( contador < tam  ) && ( aux != NULL ) ){
        aux = aux->prox;
        contador++;
    } 

    if ( aux == NULL ) return 0;
    *dado = aux->dado;
    if( tam == 1 ){
    	*lista = NULL;
    } else {
        if( aux->prox != NULL ) aux->prox->ant = NULL;
        aux->ant->prox = NULL;
    }
    free(aux);

    return 1;
}

listaEncadeada* merge(listaEncadeada* lista1, listaEncadeada* lista2){
  listaEncadeada *lista3 = malloc (sizeof (listaEncadeada)*tamanhoLista(*lista1));

  listaEncadeada aux1 = NULL,aux2 = NULL;
  int posicao = 1;

  aux1 = *lista1;
  aux2 = *lista2;
  int tam = 0;
  if (tamanhoLista(*lista1) >= tamanhoLista(*lista2) ) tam = tamanhoLista(*lista1);
  else{
    tam = tamanhoLista(*lista2);
  }
  while (posicao <= tam){
    if(aux1 != NULL) {
      addFim(lista3,aux1->dado);
      aux1 = aux1 -> prox;
    }
    if(aux2 != NULL) {
      addFim(lista3,aux2->dado);
      aux2 = aux2 -> prox;
    }
    
    posicao++;
  }
  return lista3;
  free(lista3);
  free(aux1);
  free(aux2);
}


void toString ( listaEncadeada lista ){
	printf( "\nLista: ( ");

	for( ;!listaVazia( lista ); lista = lista->prox )
	    printf("%d ", lista->dado );

	printf( ")\n" );
}

listaEncadeada aloca(){ return (no*) malloc( sizeof( no ) ); }
#include "pinhaEncadeada.h"

int main(void) {
    // cria uma pilha sequencial diretamente na memÃ³ria
	  TPilhaEnc pilha, pilha2;

    // coloca a pilha num estado vÃ¡lido (e consistente)
    criarPilha( &pilha );
    criarPilha( &pilha2 );

    if( pilhaVazia( pilha ) ) printf( "Esta vazia!" );

  	// empilhando elementos
	  empilhar( &pilha, 6 );
    empilhar( &pilha, 7 );
    empilhar( &pilha, 8 );
    // empilhando elementos
	  empilhar( &pilha2, 1 );
    empilhar( &pilha2, 2 );
    empilhar( &pilha2, 3 );
    
    imprimir( pilha,1 );
    imprimir( pilha2,2 );
    
    printf( "\n%s", mergePilhas(&pilha, &pilha2) ? 
                  " Sucesso na Clonagem\n" : "Erro na Clonagem!\n" );
      imprimir(pilha2,2);
      imprimir(pilha,1);
  return 0;
}
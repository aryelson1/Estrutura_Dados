#include "listaEncadeada.h"



int main(void) {
    listaEncadeada l,l2;
    listaEncadeada *l3;
    int retirado = 0;
    //Iniciando a lista
    construtor(&l);
    construtor(&l2);
   
    if( listaVazia( l ) ) printf( "Lista Iniciada vazia!\n" );

    //Criando Lista 1
    printf("_____________________________\n");
    //Adicionando No Inicio
    printf( "\n%s", addInicio( &l,5) ? 
                  "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", addInicio( &l,3) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", addInicio( &l,1) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    //Adicionando No Final
    printf( "\n%s", addFim( &l,7) ?
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", addFim( &l,9) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", addFim( &l,11) ? 
	                "Sucesso na Inserção\n" : "Erro na Inserçao!\n" );
    

    //Criando lista 2 
    printf("_____________________________\n");
    //Adicionando No Inicio
    printf( "\n%s", addInicio( &l,6) ? 
                  "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", addInicio( &l2,4) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", addInicio( &l2,2) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
                 
    //Adicionando No Final
    printf( "\n%s", addFim( &l2,8) ?
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );
    printf( "\n%s", addFim( &l2,10) ? 
	                "Sucesso na Inserção" : "Erro na Inserçao!\n" );

    printf("_____________________________\n");
    //Imprimindo Conteudo da lista
    printf("Lista 1: \n");
    toString(l);
    printf("_____________________________\n");
    //Imprimindo Conteudo da lista
    printf("Lista 2: \n");
    toString(l2);


    printf("_____________________________\n");
    //Fazendo merge das duas listas
    l3 = merge(&l,&l2);
    printf("Lista 1 e 2 Concatenadas: \n");
    //Verificando Quantidade de elementos
    printf( "\nQtd elementos na Lista Merge: %d\n", tamanhoLista( *l3 ) );
    toString(*l3); 
     printf("_____________________________\n");
   

    
    //Buscando Quantidade de ocorrencia do numero 2  
    NumeroDeOcorrencia(*l3,2);
    printf("_____________________________\n");
    //Buscando Quantidade de ocorrencia do numero 7  
    NumeroDeOcorrencia(*l3,13);
    printf("_____________________________\n");  

    //Removendo do Inicio
    removerInicio( l3, &retirado );
    printf( "\n%d é o primeiro elemento da lista e foi removido !", retirado );
    printf( "\nQtd elementos na memoria: %d", tamanhoLista( *l3 ) );
    toString( *l3 );

    printf("_____________________________");

    //Removendo do Final 
	  removerFim( l3, &retirado );
    printf( "\n%d é o ultimo elemento da lista e foi removido !", retirado );
    printf( "\nQtd elementos na memoria: %d", tamanhoLista( *l3 ) );

    //Imprimindo a lista
    toString(*l3);

    free(l3);
   
  return 0;
}
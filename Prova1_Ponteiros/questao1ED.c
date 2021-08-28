#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct // Cria uma STRUCT para armazenar os dados de um ponto
{
    float x;   // define o campo x
    float y;    // define o campo y

} Ponto;

typedef struct // Cria uma STRUCT para armazenar os dados de um Circulo
{
    char *nome;   // define o campo nome
    Ponto centro;    // define o campo centro
    float raio; // define o campo raio 
    
} Circulo;


Circulo *criaCirculo(char *nome,float x,float y, float centro ){
 
  Circulo  *circulo  = (Circulo*) malloc(sizeof(Circulo));;
  circulo->nome = nome;
  circulo->centro.x = x;
  circulo->centro.y = y;
  circulo->raio = centro;
    
  
  return circulo;
}

int contem(Circulo *c1, Circulo *c2){
  float d = sqrt( pow(c2->centro.x - c1->centro.x,2) + pow(c2->centro.y - c1->centro.y,2)  );
  if( d + c2->raio <= c1->raio){
    return 1;
  } 
  return 0;
}

int main(void) {
  Circulo *c1,*c2,*c3;
  
  c1 = criaCirculo("Circulo01",3.0,4.0,2.0);
  c2 = criaCirculo("Circulo02",3,3,1);
  c3 = criaCirculo("Circulo03",1,5,1);

  
  printf("%d\n", contem( c1,  c2));
  printf("%d\n", contem(c1, c3));
  
  free(c1);
  free(c2);
  free(c3);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* uniao(int v1[], int n1, int v2[], int n2){

  int x;
 

  int *v3 = (int*) malloc(sizeof(int)*(n1+n2));
  v3[0] = n1 + n2;// Adicionando o tamanho total do array v3 na primeira posição
  for (x = 1; x <= n1; x++){v3[x] = v1[x-1];}
  for (x = 1; x <= n2; x++){v3[x+n1] = v2[x-1];}
  

  return v3;
}

int main(void) {
  
int v1[] = {1,2,3,4,5,6},v2[] = {1,2,3,4,5,4},*v3;

v3 = uniao( v1,  sizeof(v1)/4,  v2,  sizeof(v2)/4);// divindo por 4 pois o sizeof retorna numero de bits 
int x;
for (x = 1; x <= v3[0] ; x++){printf("%d ", v3[x]);}//utilizando o v3[0] q foi retornado na função uniao, sendo o tamanho da lista alocado no v3[0]
printf("\n");


free(v3);

return 0;
}

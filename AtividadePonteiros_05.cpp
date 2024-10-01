/* 5. Crie uma função que receba por parâmetro um vetor de números inteiros, o tamanho do vetor e os endereços de duas variáveis inteiras (que podemos chamar de min e max). Ao passar essas variáveis para a função seu programa deverá analisar qual é o maior e o menor elemento do vetor e depositar esses elementos nas variáveis do parâmetro.*/
#include <stdio.h>
#define TAM 5
void encontrar(int v[TAM], int *maior, int *menor){
      for(int i = 0;i < TAM;i++){
            if(i == 0){
                  *maior = v[i];
                  *menor = v[i];
            } else{
                  if(v[i] > *maior){
                        *maior = v[i];
                  } else if(v[i] < *menor){
                        *menor = v[i];
                  }
            }
      }
}
int main(){
      int v[TAM], maior, menor;

      for(int i = 0;i < TAM;i++){
            scanf("%d", &v[i]);
      }

      encontrar(v, &maior, &menor);

      printf("MAIOR: %d\nMENOR: %d\n", maior, menor);

      return 0; 
}
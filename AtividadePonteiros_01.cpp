/*1. Escreva um programa que contenha duas variaveis inteiras. Leia essas variáveis do teclado. Em seguida, compare seus endereços e exiba o conteudo do maior endereço.*/

#include <stdio.h>
void compara(int *a, int *b){
      printf("Variavel %d, endereco %d\nVariavel %d, endereco %d.\n",*a, a, *b, b);
      if(a > b){  
          printf("O maior endereco e %d, da variavel %d", a, *a);    
      } else if(a < b){
          printf("O maior endereco e %d, da variavel %d", b, *b);  
      }

      
}
int main(){
    int a, b;

    scanf("%d %d", &a, &b);
    compara(&a, &b);
    
  return 0;
}
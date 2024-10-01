/* 3. Escreva uma função que dado um número real passado como parâmetro, retorne a parte inteira e a parte fracionária deste número. Escreva um programa que chama esta função.*/

#include <stdio.h>

void separar(double n, int *inteiro, double *fracao){
      *inteiro = (int)n;
      *fracao = n - *inteiro;
}
int main(){
      double n=0, fracao=0;
      int inteiro;
      
      scanf("%lf", &n);

      separar(n, &inteiro, &fracao);

      printf("Parte Inteira: %d\nParte Fracionaria: %.2lf\n", inteiro, fracao);

      
      
      return 0;
}
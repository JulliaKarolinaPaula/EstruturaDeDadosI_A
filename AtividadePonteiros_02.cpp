/*2. Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de cada posição do array.*/

#include <stdio.h>

int main(){
      float v[10];

      for(int i = 0;i<10;i++){
            printf("%d\n", &v[i]);
      }
      
      return 0;
}
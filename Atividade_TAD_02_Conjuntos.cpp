#include <stdio.h>
#define MAX 20

struct Conjunto{
      char nome[100];
      int c[MAX], x=0;
      int iguais[MAX], diferentes[MAX], e, d;

      void ler(){
            printf("Digite o nome do conjunto: ");
            scanf("%s[^\n]%*c", nome);
            printf("Digite a quantidade de elementos no conjunto: ");
            scanf("%d%*c", &x);
            if(x > 0){
                  printf("Digite os elementos do conjunto: ");
                  if(x > MAX){
                        printf("Limite atingido.");
                  } else{
                        for(int i=0;i<x;i++){
                              scanf("%d%*c", &c[i]);
                        }
                  }
            }
      }

      void imprimir(){
            printf("\nConjunto %s = [", nome);
              for(int i=0;i<x;i++){
                  printf(" %d ", c[i]);
              }
            printf("]");
      }

};
int main(){
      Conjunto a, b;

      a.ler();
      b.ler();

      a.imprimir();
      b.imprimir();
      
      

      return 0;
}
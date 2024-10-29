#include <stdio.h>
#define MAX 10

struct No{
      int valor;
      No *proximo;

      No(){
            valor = 0;
            proximo = NULL;
      }

      No(int _valor){
          valor = _valor;
          proximo = NULL;
      }
};
struct Lista{
      No *primeiro;
      No *ultimo;
      int contador;

      Lista(){
            primeiro = NULL;
            ultimo = NULL;
            contador = 0;
      }

      bool vazio(){
            return primeiro == NULL;
      }

      void empurrarPraTras(int valor){
          No *n = new No(valor);
          contador++;

          if(vazio()){
            primeiro = n;
            ultimo = n;
            return;
          }

          ultimo -> proximo = n;
          ultimo = n;
      }

      int size(){
            return contador;
      }

      void imprimir(){
            int x = 0;
            No *aux = primeiro;
            printf("\n");
               while(aux != NULL){
                  printf("\nX[%d] = %d", x, aux -> valor);
                  x++;
                  aux = aux -> proximo;
               }
      }

      void percorrerLista(){
            No *aux = new No();
            aux = primeiro;

              while(aux != NULL){
                  if(aux -> valor <= 0){
                        aux -> valor = 1;
                  }

                  aux = aux -> proximo;
              }
      }
};

int main(){
      Lista a;
      int n;
      for(int i = 0;i < MAX;i++){
            scanf("%d", &n);
            a.empurrarPraTras(n);
            
      }
      a.imprimir();
      a.percorrerLista();
      a.imprimir();
      
      return 0;
}
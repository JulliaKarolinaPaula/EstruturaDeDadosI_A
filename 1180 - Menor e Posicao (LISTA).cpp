#include <stdio.h>

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

      void inserirFim(int valor){
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
            No *aux = primeiro;
            while(aux != NULL){
                  printf("%d -> ", aux -> valor);
                  aux = aux -> proximo;
            }
      }

      void encontrarMenor(int cont){
            No *aux = primeiro;
            int menor = aux -> valor, posicao;

            for(int i = 0;i<cont;i++, aux = aux -> proximo){
                  if(aux -> valor < menor){
                        menor = aux -> valor;
                        posicao = i;
                  }
            }

            printf("\nMenor valor: %d\nPosicao: %d", menor, posicao);
      }
};

int main(){
     Lista a;
     int x, n;

     scanf("%d", &x);

     for(int i = 0;i<x;i++){
         scanf("%d", &n);
         a.inserirFim(n);
     }
     a.imprimir();
     a.encontrarMenor(x);
      return 0;
}
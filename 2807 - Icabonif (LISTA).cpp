#include <stdio.h>
#include <math.h>
struct No{
      int valor;
      No *proximo;
      No *anterior;

      No(){
            valor = 0;
            proximo = NULL;
            anterior = NULL;
      }

      No(int _valor){
          valor = _valor;
          proximo = NULL;
          anterior = NULL;
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

      void inserirInicio(int valor){
            No *n = new No(valor);
            contador++;

            if(vazio()){
                  primeiro = n;
                  ultimo = n;
                  return;
            }

            n ->proximo = primeiro;
            primeiro = n;
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
      void formulaIccanobif(int n){
            for(int i = n;i>=1;i--){
                  double fibo, nacci, o;
                  unsigned long long seq;
                  o = (1 + (sqrt(5))) / 2;
                  fibo = (pow(o,i) - pow(1-o,i));
                  nacci = sqrt(5);
                  seq = round(fibo/nacci);

                  inserirFim(seq);
            }
      }

      void imprimir(){
            No *aux = new No();
            aux = primeiro;
            
            while(aux != NULL){
                  printf("%d ", aux -> valor);
                  aux = aux -> proximo;
            }
            
      }
};

int main(){
    int n;
    Lista a;
    scanf("%d", &n);
    a.formulaIccanobif(n);
    a.imprimir();
      return 0;
} 
/* Criar um método que recebe um número N e remove os N últimos elementos da lista. Caso o tamanho da lista seja menor que N, esvaziar a lista.*/

#include <stdio.h>

struct No{
      int valor;
      No *proximo;

      No(){
        proximo = NULL;
        valor = 0;
      }

      No(int _valor){
        valor = _valor;
        proximo = NULL;
        
      }

};
struct Lista{
    No *primeiro;
    No *ultimo;
    int c;

    Lista(){
      primeiro = NULL;
      ultimo = NULL;
      c = 0;
    }

    bool vazio(){
      return primeiro == NULL;
    }

    void adicionarInicio(int valor){
        No *n = new No(valor);
        c++;
        if(vazio()){
          primeiro = n;
          ultimo = n;
          return;
        }

        n -> proximo = primeiro;
        primeiro = n;
    }

    void adicionarFim(int valor){
      No *n = new No(valor);
      c++;
      if(vazio()){
        primeiro = n;
        ultimo = n;
      }
      ultimo -> proximo = n;
      ultimo = n;
    }

    void print(){
      No *aux = primeiro;
      printf("\n");
        while(aux != NULL){
            printf("%d -> ", aux -> valor);
            aux = aux -> proximo;
        }
        if((c==0)&&(primeiro==NULL)&&(ultimo==NULL)){
            printf("Lista Vazia.");
        }
    }
    int tamanho(){
      return c;
    }

    void removerInicio(){
      if(vazio()) return;
      if(c==1){
        delete(primeiro);
        primeiro = NULL;
        ultimo = NULL;
        c = 0;
        return;
      }
      No *apagar = primeiro;
      primeiro = primeiro -> proximo;
      delete(apagar);
      c--;
    }

    void removerFim(){
      if(vazio()) return;
      if(c==1){
        delete(primeiro);
        primeiro = NULL;
        ultimo = NULL;
        c = 0;
        return;
      }
      No *apagar = ultimo;
      No *aux = primeiro;

      while(aux -> proximo != ultimo){
        aux = aux -> proximo;
      }
      ultimo = aux;
      ultimo -> proximo = NULL;
      delete(apagar);
      c--;
    }

    void controlarRemocao(int total){
      if(c <= total){
        for(int i = 0;i<c;i++){
          removerInicio();
          removerFim();
          primeiro = NULL;
          ultimo = NULL;
          c = 0;
        }
      }else{
        for(int i = 0;i<total;i++){
          removerFim();
        }
      }
      
    }
};
int main(){
  /*---------------------------------------*/
  Lista a;
  a.adicionarFim(1);
  a.adicionarFim(2);
  a.adicionarFim(3);
  a.adicionarFim(4);
  a.adicionarFim(5);
  a.print();
  a.controlarRemocao(2);
  a.print();
  /*-------------------------------------------*/
  Lista b;
  b.adicionarInicio(5);
  b.adicionarInicio(4);
  b.adicionarInicio(3);
  b.adicionarInicio(2);
  b.adicionarInicio(1);
  b.print();
  b.controlarRemocao(5);
  b.print();
  /*--------------------------------------------*/
  Lista c;
  c.adicionarFim(10);
  c.adicionarFim(20);
  c.adicionarFim(30);
  c.print();
  c.controlarRemocao(2);
  c.print();
  /*--------------------------------------------*/
  Lista d;
  d.adicionarFim(50);
  d.adicionarFim(80);
  d.print();
  d.controlarRemocao(3);
  d.print();
  return 0;
}
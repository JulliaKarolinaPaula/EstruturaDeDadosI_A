/*2. Crie um método que remove o segundo elemento da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada.*/

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
    void controlarRemocao(int posicao){
      if(c > 1){
        if(posicao <= 0){
        removerInicio();
        return;
      }
      if(posicao >= c){
        removerFim();
        return;
      }
      No *aux = primeiro;
        for(int i = 0;i < posicao-1;i++, aux = aux -> proximo);
        No *toDel = aux -> proximo;
        aux -> proximo = toDel -> proximo;
        delete(toDel);
        c--;
      }
      
    }
};
int main(){
    Lista a;
    a.adicionarInicio(30);
    a.adicionarInicio(20);
    a.adicionarInicio(10);
    a.adicionarFim(40);
    a.adicionarFim(50);
    a.print();
    a.controlarRemocao(1);
    a.print();
  /*#########################################################################################*/
    Lista b;
    b.adicionarInicio(25);
    b.print();
    b.controlarRemocao(1);
    b.print();
  return 0;
}

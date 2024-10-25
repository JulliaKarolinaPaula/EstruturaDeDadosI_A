/*5. Crie um método que insere um elemento sempre na penúltima posição da lista. Se a lista tiver tamanho <= 1, seu método não deve fazer nada.*/
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
    void controlarAdicao(int novoValor){
          if(c <= 1){  
            return;
          }
            No *aux = new No();
            No *anterior = new No();

            aux = primeiro;
            for(int i = 0;i < c;i++, aux = aux -> proximo){
                  if(aux -> proximo == ultimo){
                  anterior = aux;
                  } 
            }
            No *n = new No(novoValor);
            anterior -> proximo = n;
            n -> proximo = ultimo;
            c++;
          }
};
int main(){
      Lista a;
      a.adicionarInicio(1);
      a.adicionarFim(2);
      a.adicionarFim(3);
      a.adicionarFim(10);
      a.print();
      a.controlarAdicao(4);
      a.print();
      a.controlarAdicao(5);
      a.print();
      a.controlarAdicao(6);
      a.print();
      a.controlarAdicao(7);
      a.print();
      a.controlarAdicao(8);
      a.print();
      a.controlarAdicao(9);
      a.print();
      /*-----------------------------------------------------------------------------------*/
      Lista b;
      b.adicionarInicio(1);
      b.print();
      b.controlarAdicao(2);
      b.print();
      return 0;
}

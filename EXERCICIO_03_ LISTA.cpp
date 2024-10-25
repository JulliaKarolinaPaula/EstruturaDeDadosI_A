/*3. Crie um método que seja capaz de inserir no final da lista o tamanho atual da lista.*/
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
    void controlarAdicao(){
        adicionarFim(c);  
    }
};
int main(){
      Lista a;
      a.adicionarInicio(9);
      a.adicionarInicio(8);
      a.adicionarInicio(7);
      a.print();
      a.controlarAdicao();
      a.print();
      a.adicionarFim(10);
      a.adicionarFim(11);
      a.adicionarFim(12);
      a.controlarAdicao();
      a.print();
      return 0;
}
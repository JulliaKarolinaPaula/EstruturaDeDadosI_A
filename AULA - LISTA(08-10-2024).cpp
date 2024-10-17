#include <stdio.h>

struct Node { /*Construção de uma struct para reserva de um espaço de memória para um nó vazio.*/
      int value; /*Valor*/
      Node *next; /*Ponteiro para o endereço do próximo elemento.*/

      Node(){ /*Struct que inicia um nó vazio*/
          value = 0;
          next = NULL;
      }

      Node(int _value){ /*Struct para inserção de um primeiro elemento de nó*/
          value = _value;
          next = NULL;
      }
};
struct List { /*Struct para criação da lista*/
    Node *first; /* Endereços que armazenam o primeiro e o último elemento da lista*/
    Node *last;

    List(){ /*Lista inicia com valor nulo*/
      first = NULL;
      last = NULL;
    }

    bool empty(){ /*Função para verificar se lista vazia*/
        return first == NULL;
    }
    void pushFront(int value){ /*Função para inserção de elemento no início da lista*/
      Node *n = new Node(value);
      if(empty()){
        first = n;
        last = n;
        return;
      }
      n->next = first;
      first = n;
    }

    void pushBack(int value){/*Função para inserção de elemento no fim da lista*/
      Node *n = new Node(value);
      if(empty()){
        first = n;
        last = n;
        return;
      }
      last->next = n;
      last = n;
    }

    void print(){
      Node *aux = first;
        while(aux != NULL){
            printf("%d ->", aux->value);
            aux = aux->next;
        }
    }
};

int main(){
    List l;
    l.pushFront(10);
    l.pushFront(20);
    l.pushFront(30);
    l.pushBack(30);
    l.pushBack(50);
    l.print();

    

  return 0;
}
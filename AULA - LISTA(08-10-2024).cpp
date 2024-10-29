#include <stdio.h>

struct Node { /*Construção de uma struct para reserva de um espaço de memória para um nó vazio.*/
      int value; /*Valor*/
      Node *next; /*Ponteiro para o endereço do próximo elemento.*/

      Node(){ /*Construtor vazio que inicia um nó*/
          value = 0;
          next = NULL;
      }

      Node(int _value){ /*Construtor sobrecarregado inicia o nó*/
          value = _value;
          next = NULL;
      } 
};
struct List { /*Struct para criação da lista*/
    Node *first; /* Endereços que armazenam o primeiro e o último elemento da lista*/
    Node *last;
    int c;

    List(){ /*Lista inicia com valor nulo*/
      first = NULL;
      last = NULL;
      c = 0;
    }

    bool empty(){ /*Função para verificar se lista vazia*/
        return first == NULL;
    }
    void pushFront(int value){ /*Função para inserção de elemento no início da lista*/
      Node *n = new Node(value);
      c++;
      if(empty()){ /*Verificação se a lista está vazia*/
        first = n;
        last = n;
        return;
      }
      n->next = first; /*Se não vazia...*/
      first = n;
    }

    void pushBack(int value){/*Função para inserção de elemento no fim da lista*/
      Node *n = new Node(value);
      c++;
      if(empty()){ /*Verificação se a lista está vazia*/
        first = n;
        last = n;
        return;
      }
      last->next = n;/*Se não vazia...*/
      last = n;
    }

    void print(){/*Função para Printar valores na tela*/
      Node *aux = first;/*Criação de um nó auxiliar*/
        while(aux != NULL){
            printf("%d -> ", aux->value); /*Auxiliar aponta para o valor*/
            aux = aux->next; /*Depois, auxiliar recebe o valor do próximo elemento*/
        }
    }
    int size(){/*Função para mostrar o tamanho da lista*/
      return c;
    }

    void popFront(){/*Função para remover o elemento do início da Lista*/
      if(empty()) return;/*Verificação de lista vazia*/
      if(c==1){/*Se a lista conter somente um elemento...*/
        delete(first);/*Remove esse elemento*/
        first = NULL;
        last = NULL;
        c = 0;/*E seta NULL para a lista agora vazia*/
        return;
      }
      Node *toDel = first;/*Se a lista conter mais que um elemento, cria um novo nó auxiliar para indicar qual elemento deve ser apagado*/
      first = first -> next;/*O proximo elemento se torna o elemento do inicio da lista*/
      delete(toDel);/*Nó auxiliar é apagado*/
      c--;/*Reduzido o número de elementos na lista*/
    }

    void popBack(){/*Função para remoção de elemento do final da lista*/
      if(empty()) return;/*Verificação se lista vazia...*/
      if(c==1){/*Se a lista conter apenas um elemento*/
        delete(first);/*Remove o elemento*/
        first = NULL;
        last = NULL;
        c = 0;/*E seta valor nulo a todas variáveis do nó, que agora se tornou vazia*/
        return;
    }

    Node *toDel = last;/*Se a lista conter mais que um elemento, cria novamente um nó auxiliar para apontar qual elemento deverá ser apagado*/
    Node *aux = first;/*Cria-se outro nó auxiliar, para ajudar a percorrer a lista*/
    while(aux -> next != last){/*Enquanto o proxímo elemento for diferente do último elemento...*/
      aux = aux -> next;/*Então, nó auxiliar recebe o valor do próximo elemento*/
    }
    last = aux;/*Se o proximo elemento for o último, então o último recebe o valor do nó auxiliar...*/
    last -> next = NULL;/*...E o próximo torna-se nulo.(FIM DA LISTA)*/
    delete(toDel);/*Nó auxiliar para remoção é apagado*/
    c--;/*Reduzido ou zerado elementos da lista*/
    }

    void insert(int value, int pos){/*Função para inserção de valores(POR VALOR) no meio da lista. Com os parâmetros de "Valor " e "Posição"*/
      if(pos <= 0){/*Se a posição for menor ou igual a zero...*/
        pushFront(value);/*Inserido valor no início da lista*/
        return;
      }
      if(pos >= c){/*Se a posição for maior ou igual ao tamanho atual da lista...*/
        pushBack(value);/*Inserido valor no final da lista*/
        return;
      }
      Node *aux = first;/*Se não for satisfeitos nenhuma das condições acima, cria-se um nó auxiliar para percorrer os elementos da lista */
      for(int i = 0;i < pos;i++, aux = aux -> next);/*Laço para percorrer a lista*/
      Node *n = new Node(value);/*Inserção de um novo nó n*/
      n -> next = aux -> next;/*N aponta proximo elemento de aux*/
      aux -> next = n;/*O próximo elemento do Auxiliar recebe o endereço de N*/
      c++;/*Acrescentado valor na quantidade de elementos da lista*/
    }

    void remove(int value){ /*Função para remoção de elemento do meio da lista*/
      if(empty()) return;/*Conferencia se lista vazia*/
      Node *aux = first;/*Criação de nó auxiliar que recebe o elemento do início, para percorrer a lista*/
      Node *prev;/*Criação de outro nó auxiliar, para guardar o valor do antecedente ao elemento que se deseja apagar*/
      for(int i = 0;i < c;i++){/*Laço para percorrer a lista*/
        if(aux -> value == value){/*Nó auxiliar aponta para o elemento enquanto ele for igual ao valor escolhido*/
          if(prev == NULL){/*Se não houver nenhum elemento anteriormente, ou seja, se ele for o 1º elemento...*/
            popFront();/*Apaga o elemento do inicio da lista*/
          } else{
            prev -> next = aux -> next; /*O ponteiro do anterior aponta para o posterior do elemento que se deseja apagar*/
            delete(aux);/*Deleta elemento*/
            c--;/*Reduz a quantidade de elementos da lista*/
            aux = prev; /*O auxiliar recebe o anterior*/
          }
        }
        prev = aux;/*O anterior passa a ter o mesmo valor que o nó auxiliar*/
        aux = aux -> next; /*E o auxiliar recebe o valor do proximo elemento*/
      }
    }

    void removeByPos(int pos){
      if(pos <= 0){
        popFront();
        return;
      }
      if(pos >= c){
        popBack();
        return;
      }
      Node* aux = first;
        for (int i = 0; i < pos - 1; i++, aux = aux->next);
        Node* toDel = aux->next;
        aux->next = toDel->next;
        delete(toDel);
        c--;
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
    l.popBack();
    l.popBack();
    l.popFront();
    printf("\n");
    l.print();
    

  return 0;
}

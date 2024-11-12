#include <stdio.h>

struct Node { 
      int value; 
      Node *next; 

      Node(){ 
          value = 0;
          next = NULL;
      }

      Node(int _value){ 
          value = _value;
          next = NULL;
      } 
};
struct List { 
    Node *first; 
    Node *last;
    int c;

    List(){
      first = NULL;
      last = NULL;
      c = 0;
    }

    bool empty(){ 
        return first == NULL;
    }
    void pushFront(int value){ 
      Node *n = new Node(value);
      c++;
      if(empty()){
        first = n;
        last = n;
        return;
      }
      n->next = first; 
      first = n;
    }

    void pushBack(int value){
      Node *n = new Node(value);
      c++;
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
            printf("%d -> ", aux->value); 
            aux = aux->next; 
        }
    }
    int size(){
      return c;
    }
    
    void popFront(){
      if(empty()) return;
      if(c==1){
        delete(first);
        first = NULL;
        last = NULL;
        c = 0;
        return;
      }
      Node *toDel = first;
      first = first -> next;
      delete(toDel);
      c--;
    }
     void popBack(){
      if(empty()) return;
      if(c==1){
        delete(first);
        first = NULL;
        last = NULL;
        c = 0;
        return;
    }

    Node *toDel = last;
    Node *aux = first;
    while(aux -> next != last){
      aux = aux -> next;
    }
    last = aux;
    last -> next = NULL;
    delete(toDel);
    c--;
    }
     void insert(int value, int pos){
      if(pos <= 0){
        pushFront(value);
        return;
      }
      if(pos >= c){
        pushBack(value);
        return;
      }
      Node *aux = first;
      for(int i = 0;i < pos;i++, aux = aux -> next);
      Node *n = new Node(value);
      n -> next = aux -> next;
      aux -> next = n;
      c++;
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

      return 0;
}
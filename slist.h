#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {
    public:
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){
          this -> current = this -> current -> next;
          return *this;
        };
};

template <typename Tr>
class SList {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;

    private:
        Node<T>* head;
        Operation cmp;

    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
          while(*pointer){
            if(cmp(search, (*pointer)->data)){
              if(search == (*pointer)->data){
                return true;
              }
              return false;
            }
            pointer = &((*pointer) -> next);
          }
            return false;
        }

// 0. no insertar, ya esta en la lista
// 1.Lista vacia
// 2. insertar al comienzo
// 3. insertar al medio
// 4. insertar al final
        bool insert(T data) { // Esta lógica tiene muchas repeticiones, se puede mejorar
          Node<T>* tmp = new Node<T>(data);
          if(!head){ //1.
            head=tmp;
            return true;
          }
          Node<T> **pointer = &head; //dir de head para que no chanques a head
          if(find(data, pointer)){ //1.
            return false;
          }
          if(*pointer==head){ //2.
            tmp -> next = head;
            head = tmp;
          }
          else if(!*pointer){ //4.
            tmp -> next = nullptr;
            *pointer = tmp;
          }
          else{ //3.
            tmp -> next = *pointer;
            *pointer = tmp;
          }
          return true;
        }

        bool remove(T item) {
          Node<T> **pointer = &head;
          if(!find(item, pointer)){
            return false;
          }
          delete *pointer;
          *pointer = (*pointer) -> next;
          return true;
        }

        iterator begin() {
          return iterator(head);
        }

        iterator end() {
          return iterator(nullptr);
        }

        ~SList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif

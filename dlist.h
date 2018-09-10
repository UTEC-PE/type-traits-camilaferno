#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {
    public:
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++(){
          this -> current = this -> current -> next;
          return *this;
        };
        DListIterator<T> operator--(){
          this -> current = this -> current -> prev;
          return *this;
        };
};

template <typename Tr>
class DList {
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;

    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T data) {
          Node<T>* tmp = new Node<T>(data);
            if(!head){
              tmp -> next = nullptr;
              tmp -> prev = nullptr;
              head=tail=tmp;
            }
            else{
              head -> prev = tmp;
              tmp -> next = head;
              tmp -> prev = nullptr;
              head=tmp;
            }
        }

        void push_back(T data) {
          Node<T>* tmp = new Node<T>(data);
            if(!head){ //da igual pq si esta vacio head y tail estan vacios
              tmp -> next = nullptr;
              tmp -> prev = nullptr;
              head=tail=tmp;
            }
            else{
              tail -> next = tmp;
              tmp -> prev = tail;
              tmp -> next = nullptr;
              tail=tmp;
            }
        }

        void pop_front() {
            if(!head){
              throw "Empty List";
            }
            else{
              if(!head->next){
                delete head;
              }
              Node<T>* tmp = head->next;
              head -> next = nullptr;
              head -> prev = nullptr;
              tmp -> prev = nullptr;
              delete head;
              head=tmp;
            }
        }

        void pop_back() {
            if(!head){
              throw "Empty List";
            }
            else{
              if(!head->next){
                delete head;
              }
              else{
                Node<T>* tmp = tail->prev;
                tail -> next = nullptr;
                tail -> prev = nullptr;
                tmp -> next = nullptr;
                delete tail;
                tail=tmp;
              }
            }
        }

        iterator begin() {
          return iterator(head);
        }

        iterator end() {;
          return iterator(nullptr);
        }

        ~DList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif

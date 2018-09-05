#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    protected:
        Node<T>* current;

    public:
        Iterator() : current(nullptr) {};
        Iterator(Node<T>* current) : current(current) {};

        Iterator<T> operator=(Iterator<T> other){
          current = other.current;

          return *this;
        };

        bool operator!=(Iterator<T> other){
          if(current!=other.current){
            return true;
          }
          else{
            return false;
          }
        };

        T operator*(){
          return current -> data;
        };
};

#endif

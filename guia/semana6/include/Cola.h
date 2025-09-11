#ifndef COLA_H
#define COLA_H

#include "Lista.h"

// Cola FIFO mutable sobre Lista<T> (con centinela).
// enqueue: O(n) (sin puntero a cola), dequeue: O(1), front: O(1)
template <class T>
class Cola : public Lista<T> {
public:
    using Lista<T>::Lista;                     // hereda Lista(), Lista(T)

    void enqueue(const T& d) { this->push_back(d); } // q ++ [d]
    T    front() { return this->head(); }            // lanza si vacía
    T    dequeue() { return this->pop_front(); }     // quita y devuelve cabeza

    bool empty() { return this->isEmpty(); }
    int  size()  { return this->length(); }
};

#endif // COLA_H

#ifndef PILA_H
#define PILA_H

#include "Lista.h"

// Pila LIFO mutable sobre Lista<T> (con centinela).
// push: O(1), pop: O(1), top: O(1)
template <class T>
class Pila : public Lista<T> {
public:
    using Lista<T>::Lista;                 // hereda Lista(), Lista(T)

    void push(const T& d) { this->add(d); }     // x : s
    T    top() { return this->head(); }         // lanza si vacía
    T    pop() { return this->pop_front(); }    // quita y devuelve cabeza

    bool empty() { return this->isEmpty(); }
    int  size()  { return this->length(); }
};

#endif // PILA_H

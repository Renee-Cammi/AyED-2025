#ifndef LISTA_H
#define LISTA_H

#include <stdexcept>
#include <string>

// -----------------------------------------------------------------------------
// Nodo<T>: nodo con 'dato' y puntero 'siguiente'.
// -----------------------------------------------------------------------------
template <class T>
class Nodo {
private:
    T dato;
    Nodo* siguiente;
public:
    Nodo() : dato{}, siguiente(nullptr) {}          // dato{}: 0, false, '\0', "" ...
    explicit Nodo(T a) : dato(a), siguiente(nullptr) {}
    void set_dato(T a) { dato = a; }
    void set_siguiente(Nodo* n) { siguiente = n; }
    T get_dato() { return dato; }
    Nodo* get_siguiente() { return siguiente; }
};

// -----------------------------------------------------------------------------
// Lista<T> con nodo centinela 'czo'.
// Invariante: la secuencia real empieza en czo->get_siguiente() y termina en nullptr.
// Usar solo tipos primitivos o std::string para T.
// -----------------------------------------------------------------------------
template <class T>
class Lista {
private:
    Nodo<T>* czo; // centinela (su dato no se usa)

    // ----- Helpers recursivos -----
    static void destruirRec(Nodo<T>* p) {
        if (!p) return;
        destruirRec(p->get_siguiente());
        delete p;
    }

    static Nodo<T>* clonarRec(Nodo<T>* q) {
        if (q == nullptr) return nullptr;                          // []
        Nodo<T>* r = new Nodo<T>(q->get_dato());                   // x :
        r->set_siguiente(clonarRec(q->get_siguiente()));           // copy(xs)
        return r;
    }

    static int lengthRec(Nodo<T>* q) {
        return (q == nullptr) ? 0 : 1 + lengthRec(q->get_siguiente());
    }

    static Nodo<T>* takeRec(Nodo<T>* q, int n) {
        if (n <= 0 || q == nullptr) return nullptr;                // []
        Nodo<T>* r = new Nodo<T>(q->get_dato());                   // x : take (n-1) xs
        r->set_siguiente(takeRec(q->get_siguiente(), n - 1));
        return r;
    }

    static Nodo<T>* dropRecCopia(Nodo<T>* q, int n) {
        if (q == nullptr) return nullptr;                          // []
        if (n <= 0) return clonarRec(q);                           // copy xs
        return dropRecCopia(q->get_siguiente(), n - 1);            // avanzar
    }

    static void concatRec(Nodo<T>* p, Nodo<T>* q2) {
        // p recorre por "siguiente" la lista receptora hasta el final
        if (p->get_siguiente() == nullptr) {                       // [] ++ ys = ys
            p->set_siguiente(clonarRec(q2));                       // anexar copia
            return;
        }
        concatRec(p->get_siguiente(), q2);                         // x:xs ++ ys
    }

    static void pushBackRec(Nodo<T>* p, const T& d) {
        if (p->get_siguiente() == nullptr) {                       // base: []
            p->set_siguiente(new Nodo<T>(d));
            return;
        }
        pushBackRec(p->get_siguiente(), d);                        // paso: tail
    }

public:
    // ----- Constructores / Destructor -----
    Lista() { czo = new Nodo<T>(); }                               // []

    explicit Lista(T d) {                                          // [d]
        czo = new Nodo<T>();
        czo->set_siguiente(new Nodo<T>(d));
    }

    ~Lista() { destruirRec(czo); }                                  // borra todo

    // ----- Operaciones básicas -----
    bool isEmpty() { return czo->get_siguiente() == nullptr; }

    // cons: insertar al frente (x : xs)  — O(1)
    void add(T d) {
        Nodo<T>* nuevo = new Nodo<T>(d);
        nuevo->set_siguiente(czo->get_siguiente());
        czo->set_siguiente(nuevo);
    }

    // quitar cabeza y devolver su valor — O(1)
    T pop_front() {
        if (isEmpty()) throw std::out_of_range("lista vacia");
        Nodo<T>* primero = czo->get_siguiente();
        T v = primero->get_dato();
        czo->set_siguiente(primero->get_siguiente());
        delete primero;
        return v;
    }

    // insertar al final (snoc) — O(n) recursivo
    void push_back(const T& d) { pushBackRec(czo, d); }

    // head (x:_) = x ; head [] -> error — O(1)
    T head() {
        if (isEmpty()) throw std::out_of_range("lista vacia");
        return czo->get_siguiente()->get_dato();
    }

    // tail (_:xs) = xs ; tail [] -> error
    // Devuelve NUEVA lista copiando la cola para evitar aliasing — O(n)
    Lista* tail() {
        if (isEmpty()) throw std::out_of_range("lista vacia");
        Nodo<T>* primero = czo->get_siguiente();                   // (x:xs)
        Lista* r = new Lista<T>();                                 // []
        r->czo->set_siguiente(clonarRec(primero->get_siguiente())); // copy(xs)
        return r;
    }

    int length() { return lengthRec(czo->get_siguiente()); }       // O(n)

    // NUEVAS listas (copian): seguras para la cátedra
    Lista* take(int n) {
        Lista* r = new Lista<T>();                                 // []
        r->czo->set_siguiente(takeRec(czo->get_siguiente(), n));
        return r;
    }

    Lista* drop(int n) {
        Lista* r = new Lista<T>();                                 // []
        r->czo->set_siguiente(dropRecCopia(czo->get_siguiente(), n));
        return r;
    }

    // concatena a *esta* una COPIA de l — O(|this| + |l|)
    void concat(Lista* l) { concatRec(czo, l->czo->get_siguiente()); }

    // copia profunda — O(n)
    Lista* copy() {
        Lista* r = new Lista<T>();                                 // []
        r->czo->set_siguiente(clonarRec(czo->get_siguiente()));
        return r;
    }
};

#endif // LISTA_H

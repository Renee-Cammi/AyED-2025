#include "Habitacion.h"

// --- Constructores / Destructor ---
Habitacion::Habitacion() : nombre("sin_nombre") {}
Habitacion::Habitacion(const std::string& n) : nombre(n) {}

Habitacion::~Habitacion() {
    // liberar TODOS los Sensor* que se agregaron
    while (!sensores.isEmpty()) {
        Sensor* p = sensores.pop_front();
        delete p;
    }
}

// --- Helpers recursivos (head / tail) ---
Sensor* Habitacion::buscarRec(Lista<Sensor*>* xs, const std::string& nom) {
    if (xs->isEmpty()) return nullptr;
    Sensor* h = xs->head();
    if (h->getNombre() == nom) return h;
    Lista<Sensor*>* t = xs->tail();
    Sensor* r = buscarRec(t, nom);
    delete t;
    return r;
}

void Habitacion::mostrarRec(Lista<Sensor*>* xs) {
    if (xs->isEmpty()) return;
    Sensor* h = xs->head();
    std::cout << "  - " << h->getNombre()
              << " = " << h->getValor()
              << " " << h->getUnidad()
              << "  (promMov=" << h->promedioMovil() << ")\n";
    Lista<Sensor*>* t = xs->tail();
    mostrarRec(t);
    delete t;
}

// --- API ---
void Habitacion::agregarSensor(const std::string& nom, const std::string& unidad) {
    sensores.push_back(new Sensor(nom, unidad));
}

Sensor* Habitacion::obtenerSensor(const std::string& nom) {
    Lista<Sensor*>* c = sensores.copy();   // copia segura para recorrer
    Sensor* r = buscarRec(c, nom);
    delete c;
    return r;
}

bool Habitacion::setValor(const std::string& nom, float v) {
    Sensor* s = obtenerSensor(nom);
    if (!s) return false;
    s->setValor(v);
    return true;
}

void Habitacion::mostrar() const {
    std::cout << "Habitacion: " << nombre << "\n";
    Lista<Sensor*>* c = const_cast<Lista<Sensor*>*>(&sensores)->copy();
    if (c->isEmpty()) std::cout << "  (sin sensores)\n";
    else mostrarRec(c);
    delete c;
}

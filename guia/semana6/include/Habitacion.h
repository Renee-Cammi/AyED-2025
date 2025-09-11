#ifndef HABITACION_H
#define HABITACION_H

#include <string>
#include <iostream>
#include "Lista.h"
#include "Sensor.h"

// Habitacion SIN STL: mantiene sensores en Lista<Sensor*>
class Habitacion {
private:
    std::string   nombre;
    Lista<Sensor*> sensores; // propiedad de la habitación (libera en destructor)

    // Helpers recursivos sobre Lista<Sensor*>
    static Sensor* buscarRec(Lista<Sensor*>* xs, const std::string& nom);
    static void    mostrarRec(Lista<Sensor*>* xs);

public:
    Habitacion();
    explicit Habitacion(const std::string& n);
    ~Habitacion();

    const std::string& getNombre() const { return nombre; }
    void setNombre(const std::string& n) { nombre = n; }

    // Gestión de sensores
    void    agregarSensor(const std::string& nom, const std::string& unidad); // crea y almacena
    Sensor* obtenerSensor(const std::string& nom);                             // nullptr si no existe
    bool    setValor(const std::string& nom, float v);                         // sugar helper
    void    mostrar() const;
};

#endif // HABITACION_H

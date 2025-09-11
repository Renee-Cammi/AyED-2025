#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include "Cola.h"   // tu Cola<T> basada en Lista<T>

class Sensor {
private:
    std::string nombre;
    float valor;
    std::string unidad;

    // Ventana deslizante con SOLO enqueue/dequeue + acumulador
    Cola<float>* ventana;   // últimas K lecturas
    int   K;                // tamaño objetivo
    float sumaVentana;      // suma de los elementos actuales en la cola

public:
    Sensor(std::string nombre, std::string unidad);
    ~Sensor();

    std::string getNombre() const { return nombre; }
    float       getValor()  const { return valor; }
    std::string getUnidad() const { return unidad; }

    void setNombre(std::string nuevo) { nombre = nuevo; }
    void setValor(float nuevo);     // actualiza valor y alimenta la ventana (si está configurada)

    // Ventana deslizante
    void  configurarVentana(int k); // crea/limpia la ventana
    void  agregarLectura(float x);  // enqueue; si excede K, dequeue
    float promedioMovil() const;    // O(1): sumaVentana / size()
    bool  estable(float umbral) const; // |valor - promedio| < umbral
};

#endif // SENSOR_H

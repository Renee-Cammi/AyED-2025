#ifndef SENSOR_H
#define SENSOR_H

#include <string>

// Declarar una clase Sensor que tenga un nombre (string), valor (flotante) y unidad (string)
// Metodos para mostrar el sensor, cambiar el valor, cambiar el nombre.

class Sensor {
    private:
        std::string nombre;
        float valor;
        std::string unidad;
    public:
        Sensor(std::string nombre, std::string unidad);
        std::string getNombre() const;
        float getValor() const;
        std::string getUnidad() const;

        void setNombre(std::string nombreNuevo);
        void setValor(float valorNuevo);

};
#endif

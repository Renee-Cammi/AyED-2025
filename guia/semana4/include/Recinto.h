#ifndef RECINTO_H
#define RECINTO_H

#include <string>
#include "Sensor.h"

// Declarar una clase Sensor que tenga un nombre (string), valor (flotante) y unidad (string)
// Metodos para mostrar el sensor, cambiar el valor, cambiar el nombre.

class Recinto {
    private:
        std::string nombre;
        Sensor** sensores;
        int nSensores;

        // Recursivos si o si (Nada iterativo, es decir con bucles NO)
        //sumar n lecturas (floats).
        float _suma(Sensor** v, int n, std::string unidad);
        int _maximo(Sensor** v, int n, std::string unidad, int mejorPos);
        int _buscar(Sensor** v, int n, const std::string& nombreBuscado);
        Sensor* _getSensor(Sensor** v, int n, int posBuscada);
        // TODO: Implementar funciones recursivas
        // Cuenta los sensores de una determinada unidad
        // que tienen un valor mayor al de referencia
        int _contarMayoresQue(Sensor** v, int n, float referencia, std::string unidad);
        void _mostrarSensores(Sensor** v, int n);
        // Normaliza todos los valores de los sensores de una determinada unidad 
        // a un rango entre 0 y 1.
        void _normalizarValores01(Sensor** v, int n, std::string unidad);

    public:
        Recinto(std::string nombre, int nSensores);
        ~Recinto();

        std::string getNombre();
        void setNombre(std::string nombreNuevo);
        int getCantSensores();
        int agregarSensor(Sensor* sensorNuevo, int pos, bool sobreescribir=false){
            if (pos < 0 || pos >= this->nSensores) return -1;
            if (!sobreescribir && this->sensores[pos]!=nullptr) return -2;
            this->sensores[pos] = sensorNuevo;
            return 0;
        };
        float suma(std::string unidad){return _suma(this->sensores,0,unidad);};
        Sensor* getSensor(int posBuscada){

            return _getSensor(this->sensores, 0, posBuscada);
        };
        int maximo(std::string unidad){
            return _maximo(this->sensores, 0, unidad, -1);
        };
        int buscar(std::string nombreBuscado){
            //TODO
            return -1;
        };

        // TODO: Implementar llamadas a funciones recursivas
        int contarMayoresQue(float referencia, std::string unidad);
        void mostrarSensores();
        void _normalizarValores01(std::string unidad);


};
#endif

#include "Sensor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Sensor::Sensor(std::string nombre, std::string unidad) {
    this->nombre = nombre;
    this->valor = 0;
    this->unidad = unidad;
}

std::string Sensor::getNombre() const{
    return this->nombre;
}

void Sensor::setNombre(std::string nombreNuevo){
    this->nombre = nombreNuevo;
}


float Sensor::getValor() const{
    return this->valor;
}

void Sensor::setValor(float valorNuevo){
    this->valor = valorNuevo;
}

std::string Sensor::getUnidad() const{
    return this->unidad;
}
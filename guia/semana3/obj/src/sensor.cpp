#include "Sensor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Sensor::Sensor(string nombre, float valor, string unidad){
    this->nombre= nombre;
    this->valor= valor;
    this->unidad= unidad; 
}
Sensor::~Sensor(){
}

string Sensor::getNombre(){
    return nombre; 
}
float Sensor::getValor(){
    return valor; 
}
string Sensor::getUnidad(){
    return unidad; 
}

void Sensor::setNombre(string nuevoNombre){
    nombre= nuevoNombre;
}
void Sensor::setValor(float nuevoValor){
    valor= nuevoValor; 
}

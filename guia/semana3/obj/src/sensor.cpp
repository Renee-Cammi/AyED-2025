#include "sensor.h"
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

void Sensor::cambioNombre(string nuevoNombre){
    nombre= nuevoNombre;
}
void Sensor::cambioValor(float nuevoValor){
    valor= nuevoValor; 
}

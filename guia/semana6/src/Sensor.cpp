#include "Sensor.h"
#include <cmath>   // std::fabs
#include <iostream>

Sensor::Sensor(std::string n, std::string u)
: nombre(n), valor(0.0f), unidad(u), ventana(nullptr), K(0), sumaVentana(0.0f) {}

Sensor::~Sensor() {
    if (ventana) delete ventana;
}

void Sensor::configurarVentana(int k) { 
    this->K= k;
    if(ventana==nullptr) ventana= new Cola<float>();
    else{
    while (!ventana->empty()) ventana->dequeue();
    };
    std::cout << "Configuracion finalizada"<<std::endl;
}

void Sensor::agregarLectura(float x) {
    if(ventana->size() > K){ this->sumaVentana-=ventana->front(); ventana->dequeue();};
    ventana->enqueue(x);
    this->sumaVentana+=x;
}

void Sensor::setValor(float nuevo) {
    this->valor=nuevo;
    agregarLectura(nuevo);
}

float Sensor::promedioMovil() const {
    if(ventana != nullptr){
        return sumaVentana/ ventana->size();
    }
    return -1;
}

bool Sensor::estable(float umbral) const {
    if(ventana !=nullptr) 
    return (ventana->front() - this->promedioMovil()) < umbral;
    return 0; 
}

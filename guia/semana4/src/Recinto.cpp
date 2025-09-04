#include "Recinto.h"
#include <iostream>

Recinto::Recinto(std::string nombre, int nSensores){
    this->nombre = nombre;
    this->nSensores = nSensores;
    this->sensores = new Sensor*[nSensores];
    for(int i=0; i<nSensores; i++) {
        this->sensores[i] = nullptr;
    }
}

Recinto::~Recinto(){
    delete[] sensores;
}

std::string Recinto::getNombre(){
    return nombre;
}

int Recinto::getCantSensores(){
    return nSensores;
}

void Recinto::setNombre(std::string nombreNuevo){
    this->nombre = nombreNuevo;
}

// ------------------ RECURSIVOS ------------------

float Recinto::_suma(Sensor** v, int n, std::string unidad){
    if(n==this->nSensores) return 0.0;
    else {
        if(v[n]!=nullptr && v[n]->getUnidad()==unidad)
            return _suma(v, n+1, unidad) + v[n]->getValor();
        else
            return _suma(v, n+1, unidad);
    }
}

int Recinto::_maximo(Sensor** v, int n, std::string unidad, int mejorPos){
    if(n==this->nSensores) return mejorPos;
    else{
        if(v[n]!=nullptr && v[n]->getUnidad()==unidad){
            if(mejorPos==-1 || v[mejorPos]->getValor()<=v[n]->getValor()){
                mejorPos = n;
            }
        }
        return _maximo(v, n+1, unidad, mejorPos);
    }
}

int Recinto::_buscar(Sensor** v, int n, const std::string& nombreBuscado){
    if(n==this->nSensores) return -1;
    else{
        if (v[n]!=nullptr && v[n]->getNombre()==nombreBuscado) return n;
        else return _buscar(v,n+1,nombreBuscado);
    }
}

Sensor* Recinto::_getSensor(Sensor** v, int n, int posBuscada){
    if(n==this->nSensores){
        return nullptr;
    }
    else{
        if(n==posBuscada){
            return v[n];
        }else{
            return _getSensor(v, n+1, posBuscada);
        }
    }
}

int Recinto::_contarMayoresQue(Sensor** v, int n, float referencia, std::string unidad)
{
if (n==this->nSensores) return 0;
else{
    if (v[n]!=nullptr && v[n]->getUnidad()==unidad && v[n]->getValor()>= referencia) return 1+_contarMayoresQue(v,n+1,referencia,unidad);
    else return _contarMayoresQue(v,n+1, referencia, unidad);
}
}

void Recinto::_mostrarSensores(Sensor** v, int n){
if(n==this->nSensores) return; 
else{ 
    if(v[n]!=nullptr){
        std::cout << v[n]->getNombre() << "= " << v[n]->getValor() << v[n]->getUnidad() << std::endl;
        _mostrarSensores(v,n+1);
    }
    else _mostrarSensores(v,n+1);
}
}

void Recinto::_normalizarValores01(Sensor** v, int n, std::string unidad){
    std::cout << n << std::endl;
    if(n==this->nSensores) return;
    else{
        if(v[n]!=nullptr && v[n]->getUnidad()== unidad) v[n]->setValor(v[n]->getValor()/ v[maximo(unidad)]->getValor() );
        _normalizarValores01(v,n+1,unidad);
    }
};

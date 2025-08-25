#include "sensor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void imprimir(const Sensor* lista, int n) {
    for(int i = 0; i<n; i++){
        // std::cout << lista[i].nombre << " = " << lista[i].valor << " " << lista[i].unidad << std::endl;
        std::cout << "Sensor["<<i<<"]: " << (lista+i)->nombre <<  " = " << (lista+i)->valor << " " << (lista+i)->unidad << std::endl;
    }
}

int cargarDesdeArchivo(const std::string& ruta, Sensor* lista, int n) {
    std::ifstream in(ruta);
    if(!in) return 0;

    int count = 0;
    while(count < n && (in >> lista[count].nombre >> lista[count].valor>> lista[count].unidad)){
        count++;
    }

    return count;
}

float promedioValores(const Sensor* lista, int n, std::string unidad){
    float suma=0;
    int cantidad_sensores= contarSensores(lista, n, unidad);

    if(cantidad_sensores==0) return 0; 

    for(int i=0; i<n; i++){
        if(unidad==lista[i].unidad){
            suma+=lista[i].valor;
        }
    }
    return suma/cantidad_sensores; 
}
int contarSensores(const Sensor* lista, int n, std::string unidad)
{ 
    int cant_sensores=0;
    for(int i=0; i<n; i++){
        if(unidad==lista[i].unidad){
            cant_sensores++;
        }
    }
    return cant_sensores; 
}
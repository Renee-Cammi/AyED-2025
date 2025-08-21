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
    while(count < n && (in >> lista[count].nombre >> lista[count].valor)>> lista[count].unidad){
        count++;
    }

    return count;
}

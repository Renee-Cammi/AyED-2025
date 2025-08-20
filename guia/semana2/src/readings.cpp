#include "readings.h"
#include <iostream>
#include <fstream>
#include <new>        // std::nothrow
#include <iomanip>    // std::setprecision

float* crear_arreglo(int size) {
    if (size <= 0) {
        return nullptr;
    }
    return new float[size];
}

void liberar_arreglo(float*& arr) {
    delete[]arr; 
    arr= nullptr; 
}

int cargar_desde_archivo(const std::string& ruta, float* arr, int size) {
    //TODO
    std::ifstream archivo(ruta); 
    if(!archivo){
        std::cout << "No se pudo abrir el archivo";
        return 1; 
    }
    int cant_leidos=0; 
    for(int i=0; i<size; i++)
    {
        archivo >> arr[i];
        cant_leidos++;  
    }
    archivo.close(); 
    return cant_leidos; 
}

bool guardar_en_archivo(const std::string& ruta, const float* arr, int size) {
    std::ofstream salida(ruta); 
    if(!salida){
        std::cout << "No se pudo abrir el archivo para escribir"; 
        return 0; 
    }
    for(int i=0; i<size; i++){
        salida << arr[i] << std::endl; 
    }
    salida.close();
    return 1; 
}

void imprimir(const float* arr, int size) {
    for(int i=0; i<size; i++){
        std::cout << arr[i]<< "\n"; 
    }
}
 

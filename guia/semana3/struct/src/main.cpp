#include <iostream>
#include "sensor.h"

using namespace std;
nt main() {
    
    int N;
    cout << "Cantidad de sensores: ";
    cin >> N;

    //TODO: Instanciar un array de Sensores de forma dinamica y de tamaño N
    Sensor* sensores= new Sensor[N];  
    
    
    string archivoEntrada;
    cout << "Archivo de entrada: ";
    cin >> archivoEntrada;

    int leidos = cargarDesdeArchivo(archivoEntrada, sensores, N);
    cout << "Se leyeron " << leidos << " sensores.\n";

    imprimir(sensores, leidos);

    // TODO: Que habria que hacer aca??
    free.()
    return 0;
}


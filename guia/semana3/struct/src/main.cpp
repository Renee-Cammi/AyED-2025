#include <iostream>
#include "sensor.h"

using namespace std;

int main() {
    // Sensor sCocina;
    // sCocina.nombre = "TempCocina";
    // sCocina.valor = 28.3;
    // sCocina.unidad = "C";

    // Sensor* sHabitacion = new Sensor;
    // sHabitacion->nombre = "TempHabitacion";



    
    int N;
    cout << "Cantidad de sensores: ";
    cin >> N;

    //TODO: Instanciar un array de Sensores de forma dinamica y de tamaño N
    Sensor* sensores = new Sensor[N];
    string archivoEntrada;
    cout << "Archivo de entrada: ";
    cin >> archivoEntrada;

    int leidos = cargarDesdeArchivo(archivoEntrada, sensores, N);
    cout << "Se leyeron " << leidos << " sensores.\n";

    imprimir(sensores, leidos);

    // delete sHabitacion;
    return 0;
}


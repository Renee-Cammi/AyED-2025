#include <iostream>
#include "sensor.h"
#include <string>

using namespace std;

int main() {
    // Instancia un objeto de la clase Sensor
    Sensor s("ruido", 75, "db");
    Sensor* sensores= new Sensor[2]{Sensor("particulas10", 14.8, "ug/m3"), Sensor("temperatura", 25, "C")};
    
    cout << s.getNombre() <<"= " << s.getValor() << " " << s.getUnidad() << endl; 
    cout << sensores[0].getNombre() <<"= " << sensores[0].getValor() << " " << sensores[0].getUnidad() << endl;
    cout << sensores[1].getNombre() <<"= " << sensores[1].getValor() << " " << sensores[1].getUnidad() << endl;

    sensores[0].cambioNombre("particulas25");
    sensores[0].cambioValor(4.5);

    cout << sensores[0].getNombre() <<"= " << sensores[0].getValor() << " " << sensores[0].getUnidad() << endl;

    delete[] sensores;

    return 0;
}

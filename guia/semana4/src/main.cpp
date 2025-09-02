#include <iostream>
#include "Recinto.h"
#include "Sensor.h"
using namespace std;

int main() {
    Sensor* s1 = new Sensor("Temp Sofa", "C");
    Sensor* s2 = new Sensor("Temp Mesa", "C");
    Sensor* s3 = new Sensor("Humedad", "%");

    s1->setValor(21.5);
    s2->setValor(24.0);
    s3->setValor(60);

    Recinto* sala= new Recinto("Sala", 5);
    sala->agregarSensor(s1, 0);
    sala->agregarSensor(s2, 1);
    sala->agregarSensor(s3, 2);

    cout << "Suma temperaturas: " << sala->suma("C") << endl;
    cout << "Posición del máximo en C: " << sala->maximo("C") << endl;
    int posHumedad = sala->buscar("Humedad");
    cout << "Buscar Humedad -> pos: " << posHumedad << endl;

    Sensor* obtenido = sala->getSensor(1);
    if(obtenido) cout << "Sensor en pos 1: " << obtenido->getNombre()<<" valor: "<< obtenido->getValor() << obtenido->getUnidad()<< endl;

    return 0;
}
#include <iostream>
#include "Habitacion.h"
#include "Sensor.h"

using namespace std;

int main() {
    Habitacion h("Living");

    // Altas usando ambos métodos
    h.agregarSensor("temp_living", "C");   // valor por defecto 0.0 segun tu clase Sensor
    h.agregarSensor(Sensor("hum_living", "%"));

    // Setear valores
    h.setValor("temp_living", 22.8f);
    h.setValor("hum_living", 45.0f);

    // Consultas
    cout << "Cantidad de sensores: " << h.cantidadSensores() << "\n";
    cout << "Existe 'temp_living'? " << (h.existeSensor("temp_living") ? "si" : "no") << "\n";

    // Renombrar un sensor
    h.setNombreSensor("hum_living", "hum_sala");

    // Mostrar
    h.mostrar();

    // Obtener puntero y operar directo (opcional)
    Sensor* p = h.obtenerSensor("temp_living");
    if (p != nullptr) {
        p->setValor(23.1f);
    }

    // Eliminar por nombre
    h.eliminarSensorPorNombre("hum_sala");
    h.mostrar();

    return 0;
}

#include <iostream>
#include "Habitacion.h"
#include "Reglas.h"

int main() {
    // 1) Construcción del modelo (sin STL)
    Habitacion living("Living");

    // Sensores base
    living.agregarSensor("temp", "C");
    living.agregarSensor("hum",  "%");

    // Configurar ventanas deslizantes (K = 5)
    Sensor* sTemp = living.obtenerSensor("temp");
    Sensor* sHum  = living.obtenerSensor("hum");
    if (sTemp) sTemp->configurarVentana(5);
    if (sHum)  sHum ->configurarVentana(5);

    // 2) Alimentar lecturas (setValor también ingresa en ventana)
    living.setValor("temp", 26.0f);
    living.setValor("hum",  38.0f);

    living.setValor("temp", 27.0f);
    living.setValor("hum",  37.0f);

    living.setValor("temp", 28.5f);
    living.setValor("hum",  35.0f);

    living.mostrar();

    // 3) Regla RPN: si temp > 25 && hum < 40 entonces ACT:ventilador=ON
    // tokens (en orden postfijo):
    //   temp 25 > hum 40 < && ACT:ventilador=ON
    Lista<std::string> regla;
    regla.push_back("temp");
    regla.push_back("25");
    regla.push_back(">");
    regla.push_back("hum");
    regla.push_back("40");
    regla.push_back("<");
    regla.push_back("&&");
    regla.push_back("ACT:ventilador=ON");

    bool accion = Reglas::evaluarRPN(&living, &regla);
    std::cout << "¿Se disparo alguna accion? " << (accion ? "Si" : "No") << "\n";

    // 4) Comprobar estabilidad con ventana (solo enqueue/dequeue + suma)
    if (sTemp) {
        std::cout << "Promedio movil temp = " << sTemp->promedioMovil()
                  << "  (estable ±0.5? " << (sTemp->estable(0.5f) ? "Si" : "No") << ")\n";
    }
    if (sHum) {
        std::cout << "Promedio movil hum  = " << sHum->promedioMovil()
                  << "  (estable ±2.0? " << (sHum->estable(2.0f) ? "Si" : "No") << ")\n";
    }

    return 0;
}

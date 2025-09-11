#ifndef REGLAS_H
#define REGLAS_H

#include <string>
#include "Lista.h"
#include "Pila.h"
#include "Habitacion.h"

// Motor de reglas en notación postfija (RPN) usando Pila<std::string>.
// Tokens posibles (strings):
//   - nombres de sensor (ej: "temp", "hum")  -> se reemplazan por su valor en la pila
//   - literales numéricos (ej: "25", "40")
//   - operadores: ">", "<", "==", "&&", "||"
//   - acción: "ACT:mensaje"  (consume el tope booleando y si es 1, "dispara" la acción)
//
// Devuelve true si alguna acción se ejecutó (imprime por consola la acción).
class Reglas {
public:
    static bool evaluarRPN(Habitacion* h, Lista<std::string>* tokens);
};

#endif // REGLAS_H

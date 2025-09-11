#include "Reglas.h"
#include <cstdlib>   // std::strtof
#include <iostream>

// utilitario: ¿es operador aritmético/relacional?
static bool esOpNum(const std::string& t) {
    return (t == ">" || t == "<" || t == "==" );
}
static bool esOpBool(const std::string& t) {
    return (t == "&&" || t == "||");
}

bool Reglas::evaluarRPN(Habitacion* h, Lista<std::string>* tokens) {
    // TODO
}

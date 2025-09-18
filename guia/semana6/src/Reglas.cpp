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
    Pila<std::string>* pilaT= new Pila<std::string>; //crear Pila

    while(!tokens->isEmpty()){ //mientras que la lista de token este llena se repite
        std::string token= tokens->pop_front(); // me quedo con el primer elemento de la lista de tokens
        //comparacion de token y accion según lo que sea el token
        if(token == "temp" || token == "hum"){ 
            Sensor* s= h->obtenerSensor(token);  
            pilaT->push(std::to_string(s->getValor()));
        }

        else if(esOpNum(token)){
            if(pilaT->size() < 2) return false;
            float a= stof(pilaT->pop());
            float b= stof(pilaT->pop());

            if(token == ">"){
                pilaT->push(std::to_string(a > b));
            }
            else if(token == "<"){
                pilaT->push(std::to_string( a < b ));
            }
            else{
                pilaT->push(std::to_string(a == b));
            }
        }

        else if(esOpBool(token)){
            if(pilaT->size() < 2) return false;

            float a= stof(pilaT->pop());
            float b= stof(pilaT->pop());

            if(token == "&&"){
                pilaT->push(std::to_string(a && b));
            }
            if(token == "||"){
                pilaT->push(std::to_string(a || b));
            }
        }

        else{
            float tope= stof(pilaT->top());
            if(tope==0) return false;
            else{
                std::cout << token;
                return true;
            }
        }

    }

    return 1; 
}

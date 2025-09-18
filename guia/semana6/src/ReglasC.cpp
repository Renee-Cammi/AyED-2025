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
    Lista<std::string>* aux= tokens->copy();
    
    if (tokens->isEmpty()) return 0;
    
    while(!aux->isEmpty()){ //mientras que la lista de token este llena se repite
        std::string token= aux->pop_front(); // me quedo con el primer elemento de la lista de tokens
        //comparacion de token y accion según lo que sea el token

		if(esOpNum(token)){
            if(pilaT->size() < 2) return false;
            float b= stof(pilaT->pop());
            float a= stof(pilaT->pop());

            if(token == ">"){
                pilaT->push(a > b ? "1":"0");
                std::cout << "OPNUM" << token << std::endl;
            }
            else if(token == "<"){
                pilaT->push( a < b ? "1":"0");
                std::cout << "OPNUM" << token << std::endl;

            }
            else{
                pilaT->push(a == b ? "1":"0");
                std::cout << "OPNUM" << token << std::endl;

            }
        }

        else if(esOpBool(token)){
            if(pilaT->size() < 2) return false;

            float a= stof(pilaT->pop());
            float b= stof(pilaT->pop());

            if(token == "&&"){
                pilaT->push(a&&b ? "1":"0");
                std::cout << "OPBOOL" << token << std::endl;

            }
            if(token == "||"){
                pilaT->push(a||b ? "1":"0");
                 std::cout << "OPBOOL" << token << std::endl;

            }
        }
		
		else if(token.rfind("ACT:",0)==0){
			float tope= stof(pilaT->top());
            if(tope==0) return false;
            else{
                std::cout << token << std::endl; 
                return true;
			}
		}
        else{
			Sensor* s= h->obtenerSensor(token);  
			if(s) pilaT->push(std::to_string(s->getValor()));
			else pilaT->push(token);
            }
        }

    }


#ifndef SENSOR_H
#define SENSOR_H

#include <string>
using namespace std; 

// Declarar una clase Sensor que tenga un nombre (string), valor (flotante) y unidad (string)
// Metodos para mostrar el sensor, cambiar el valor, cambiar el nombre.

class Sensor{
	public: 
	Sensor(string, float, string);
	~Sensor();

	string getNombre();
	float getValor();
	string getUnidad();

	void cambioNombre(string);
	void cambioValor(float);

private:
	string nombre; 
	float valor; 
	string unidad; 
	};

#endif

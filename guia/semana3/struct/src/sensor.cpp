#include "sensor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void imprimir(const Sensor* lista, int n) {
	/*for(int i=0; i<n; i++){
		cout << lista[i].nombre<< " " << lista[i].valor<< " "<< lista[i].unidad << endl;
		} */
		cout << (lista+i)->nombre << (lista+i)->valor << (lista+i)->unidad << endl;
}

int cargarDesdeArchivo(const std::string& ruta, Sensor* lista, int n) {
	ifstream archivo(ruta);
	if(!archivo){
		cout <<"no se pudo abrir el archivo";
		return 0;
		}
		int leidos=0;
	/*for(int i=0; i<n;i++){
		archivo >> lista[i].nombre; 
		archivo >> lista[i].valor;
		archivo >> lista[i].unidad;
		leidos++;
		}*/	
		
	while (leidos<n && (archivo >>lista[leidos].nombre >> lista[leidos].valor >>lista[leidos].unidad)){
		leidos ++;
		}
		return leidos; 
}

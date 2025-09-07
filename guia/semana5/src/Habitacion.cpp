#include "Habitacion.h"
#include <iostream>

// ===== Constructores / básicos =====
Habitacion::Habitacion() : nombre("sin_nombre") {}
Habitacion::Habitacion(const std::string& n) : nombre(n) {}

const std::string& Habitacion::getNombre() const { return nombre; }
void Habitacion::setNombre(const std::string& n) { nombre = n; }

int  Habitacion::cantidadSensores() const { return (int)sensores.size(); }
bool Habitacion::vacia() const { return sensores.empty(); }

void Habitacion::agregarSensor(const Sensor& s) { sensores.push_back(s); }
void Habitacion::agregarSensor(const std::string& n, const std::string& u) {
    sensores.push_back(Sensor(n, u));
}

// ===== Helpers recursivos (head / tail) =====

void Habitacion::mostrarRec(std::vector<Sensor>::const_iterator it,
                            std::vector<Sensor>::const_iterator fin,
                            int idxBase) const {
    // Mostrar todos: cabeza = *it, resto = [next(it), end)
    // imprimir la cabeza y llamar a la recursión con el resto
    if(it==fin) return;
    else{
        std::cout << "Sensor " << idxBase+1 << ": " <<  it->getNombre() << " = " << it->getValor() << " " << it->getUnidad() << std::endl;
        mostrarRec(std::next(it),fin, idxBase+1);
    }
}

int Habitacion::indiceDeRec(std::vector<Sensor>::const_iterator it,
                            std::vector<Sensor>::const_iterator fin,
                            int idxBase,
                            const std::string& nombreSensor) const {
    // devolver índice si la cabeza coincide, o recursión con el resto
    if(it==fin) return -1;
    else{
        if(it->getNombre()==nombreSensor) return idxBase;
        return indiceDeRec(std::next(it),fin,idxBase+1,nombreSensor);
    }
}

bool Habitacion::setValorRec(std::vector<Sensor>::iterator it,
                             std::vector<Sensor>::iterator fin,
                             const std::string& nombreSensor,
                             float nuevoValor) {
    // si la cabeza coincide cambiar valor, si no, recursión con el resto
    if(it==fin) return false;
    else{
        if(it->getNombre()==nombreSensor){
            it->setValor(nuevoValor);
            return true;
        }
        else return setValorRec(std::next(it),fin,nombreSensor,nuevoValor);
    }
}

bool Habitacion::setNombreRec(std::vector<Sensor>::iterator it,
                              std::vector<Sensor>::iterator fin,
                              const std::string& nombreActual,
                              const std::string& nombreNuevo) {
    // si la cabeza coincide cambiar nombre, si no, recursión con el resto
    if(it==fin) return false;
    else{
        if(it->getNombre()==nombreActual){
            it->setNombre(nombreNuevo);
            return true;
        }
        else return setNombreRec(std::next(it),fin,nombreActual,nombreNuevo);
    }
}

const Sensor* Habitacion::obtenerConstRec(std::vector<Sensor>::const_iterator it,
                                          std::vector<Sensor>::const_iterator fin,
                                          const std::string& nombreSensor) const {
    // devolver puntero al sensor si coincide, si no, recursión con el resto
    if(it==fin) return nullptr;
    else{
        if(it->getNombre()==nombreSensor) return &(*it);
        return obtenerConstRec(std::next(it),fin,nombreSensor);
    }
}

Sensor* Habitacion::obtenerRec(std::vector<Sensor>::iterator it,
                               std::vector<Sensor>::iterator fin,
                               const std::string& nombreSensor) {
    // devolver puntero al sensor si coincide, si no, recursión con el resto
    if(it==fin) return nullptr;
    else{
        if(it->getNombre()==nombreSensor) return &(*it);
        return obtenerRec(std::next(it),fin,nombreSensor);
    }
}

bool Habitacion::eliminarPorNombreRec(std::vector<Sensor>::iterator it,
                                      std::vector<Sensor>::iterator fin,
                                      const std::string& nombreSensor) {
    //TODO: si la cabeza coincide, borrar con erase; si no, recursión con el resto
    if(it==fin) return false;
    else{
        if(it->getNombre()==nombreSensor){
            this->sensores.erase(it);
            return true;
        }
        return eliminarPorNombreRec(std::next(it),fin,nombreSensor);
    }
}

// ===== API pública (envoltorios) =====

void Habitacion::mostrar() const {
    std::cout << "Habitacion: " << nombre << "\n";
    if (sensores.empty()) { std::cout << "  (sin sensores)\n"; return; }
    mostrarRec(sensores.begin(), sensores.end(), 0);
}

int Habitacion::indiceDe(const std::string& nombreSensor) const {
    return indiceDeRec(sensores.begin(), sensores.end(), 0, nombreSensor);
}

bool Habitacion::existeSensor(const std::string& nombreSensor) const {
    return indiceDe(nombreSensor) != -1;
}

bool Habitacion::setValor(const std::string& nombreSensor, float nuevoValor) {
    return setValorRec(sensores.begin(), sensores.end(), nombreSensor, nuevoValor);
}

bool Habitacion::setNombreSensor(const std::string& nombreActual, const std::string& nombreNuevo) {
    return setNombreRec(sensores.begin(), sensores.end(), nombreActual, nombreNuevo);
}

const Sensor* Habitacion::obtenerSensor(const std::string& nombreSensor) const {
    return obtenerConstRec(sensores.begin(), sensores.end(), nombreSensor);
}

Sensor* Habitacion::obtenerSensor(const std::string& nombreSensor) {
    return obtenerRec(sensores.begin(), sensores.end(), nombreSensor);
}

bool Habitacion::eliminarSensorPorNombre(const std::string& nombreSensor) {
    return eliminarPorNombreRec(sensores.begin(), sensores.end(), nombreSensor);
}

bool Habitacion::eliminarSensorPorIndice(int idx) {
    if (idx < 0 || idx >= (int)sensores.size()) return false;
    sensores.erase(sensores.begin() + idx);
    return true;
}

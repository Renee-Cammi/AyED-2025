#ifndef HABITACION_H
#define HABITACION_H

#include <string>
#include <vector>
#include <iterator>  // std::next
#include "Sensor.h"

class Habitacion {
private:
    std::string nombre;
    std::vector<Sensor> sensores;

    // ===== Helpers recursivos (head / tail con iteradores) =====
    // Mostrar todos: cabeza = *it, resto = [next(it), end)
    void mostrarRec(std::vector<Sensor>::const_iterator it,
                    std::vector<Sensor>::const_iterator fin,
                    int idxBase) const;

    // Buscar índice por nombre: devuelve -1 si no está
    int indiceDeRec(std::vector<Sensor>::const_iterator it,
                    std::vector<Sensor>::const_iterator fin,
                    int idxBase,
                    const std::string& nombreSensor) const;

    // Setear valor por nombre (true si lo encontró)
    bool setValorRec(std::vector<Sensor>::iterator it,
                     std::vector<Sensor>::iterator fin,
                     const std::string& nombreSensor,
                     float nuevoValor);

    // Setear nombre por nombre (true si lo encontró)
    bool setNombreRec(std::vector<Sensor>::iterator it,
                      std::vector<Sensor>::iterator fin,
                      const std::string& nombreActual,
                      const std::string& nombreNuevo);

    // Obtener puntero (o nullptr si no está)
    const Sensor* obtenerConstRec(std::vector<Sensor>::const_iterator it,
                                  std::vector<Sensor>::const_iterator fin,
                                  const std::string& nombreSensor) const;

    Sensor* obtenerRec(std::vector<Sensor>::iterator it,
                       std::vector<Sensor>::iterator fin,
                       const std::string& nombreSensor);

    // Eliminar por nombre (true si borró alguno)
    bool eliminarPorNombreRec(std::vector<Sensor>::iterator it,
                              std::vector<Sensor>::iterator fin,
                              const std::string& nombreSensor);

public:
    Habitacion();
    Habitacion(const std::string& nombre);

    const std::string& getNombre() const;
    void setNombre(const std::string& n);

    int  cantidadSensores() const;
    bool vacia() const;

    void agregarSensor(const Sensor& s);
    void agregarSensor(const std::string& nombre, const std::string& unidad);

    // ===== API pública (usa los helpers recursivos) =====
    void mostrar() const;

    int  indiceDe(const std::string& nombreSensor) const;
    bool existeSensor(const std::string& nombreSensor) const;

    bool setValor(const std::string& nombreSensor, float nuevoValor);
    bool setNombreSensor(const std::string& nombreActual, const std::string& nombreNuevo);

    const Sensor* obtenerSensor(const std::string& nombreSensor) const;
    Sensor*       obtenerSensor(const std::string& nombreSensor);

    bool eliminarSensorPorNombre(const std::string& nombreSensor);
    bool eliminarSensorPorIndice(int idx); // esta queda simple (no recursiva)
};

#endif // HABITACION_H

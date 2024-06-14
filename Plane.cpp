#include "Plane.h"

// Constructor
Plane::Plane(std::string v, std::string nr, std::string m, std::string f, int adf, int c, double pmd, std::string e, std::string a)
    : vuelo(v), numero_de_registro(nr), modelo(m), fabricante(f), año_de_fabricación(adf), capacidad(c), peso_max_despegue(pmd), estado(e), aerolinea(a), next(nullptr), prev(nullptr) {}

// Display method
void Plane::displayInfo() const {
    std::cout << "Vuelo: " << vuelo << std::endl;
    std::cout << "Numero de Registro: " << numero_de_registro << std::endl;
    std::cout << "Modelo: " << modelo << std::endl;
    std::cout << "Fabricante: " << fabricante << std::endl;
    std::cout << "Año de Fabricación: " << año_de_fabricación << std::endl;
    std::cout << "Capacidad: " << capacidad << std::endl;
    std::cout << "Peso Max Despegue: " << peso_max_despegue << std::endl;
    std::cout << "Estado: " << estado << std::endl;
    std::cout << "Aerolinea: " << aerolinea << std::endl;
}

// Equality operator
bool Plane::operator==(const Plane& other) const {
    return (vuelo == other.vuelo &&
            numero_de_registro == other.numero_de_registro &&
            modelo == other.modelo &&
            fabricante == other.fabricante &&
            año_de_fabricación == other.año_de_fabricación &&
            capacidad == other.capacidad &&
            peso_max_despegue == other.peso_max_despegue &&
            estado == other.estado &&
            aerolinea == other.aerolinea);
}

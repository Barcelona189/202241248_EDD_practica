#include "Passenger.h"

// Default constructor
Passenger::Passenger()
    : nombre(""), nacionalidad(""), numero_de_pasaporte(""), vuelo(""), asiento(""), destino(""), origen(""), equipaje_facturado(0) {}

// Parameterized constructor
Passenger::Passenger(const std::string& n, const std::string& nat, const std::string& num, const std::string& v,
                     const std::string& seat, const std::string& dest, const std::string& orig, int equip)
    : nombre(n), nacionalidad(nat), numero_de_pasaporte(num), vuelo(v), asiento(seat), destino(dest), origen(orig), equipaje_facturado(equip) {}

// Display method
void Passenger::displayInfo() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Nacionalidad: " << nacionalidad << std::endl;
    std::cout << "Número de Pasaporte: " << numero_de_pasaporte << std::endl;
    std::cout << "Vuelo: " << vuelo << std::endl;
    std::cout << "Asiento: " << asiento << std::endl;
    std::cout << "Destino: " << destino << std::endl;
    std::cout << "Origen: " << origen << std::endl;
    std::cout << "Equipaje Facturado: " << equipaje_facturado << std::endl;
}

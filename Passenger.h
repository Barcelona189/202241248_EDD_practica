#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <iostream>

class Passenger {
public:
    std::string nombre;
    std::string nacionalidad;
    std::string numero_de_pasaporte;
    std::string vuelo;
    std::string asiento;
    std::string destino;
    std::string origen;
    int equipaje_facturado;

    // Constructors
    Passenger();
    Passenger(const std::string& n, const std::string& nat, const std::string& num, const std::string& v,
              const std::string& seat, const std::string& dest, const std::string& orig, int equip);

    // Display method
    void displayInfo() const;

    // Equality operator (if needed)
    bool operator==(const Passenger& other) const;
};

#endif

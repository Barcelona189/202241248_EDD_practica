#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <iostream>

class Plane {
public:
    std::string vuelo;
    std::string numero_de_registro;
    std::string modelo;
    std::string fabricante;
    int año_de_fabricación;
    int capacidad;
    double peso_max_despegue;
    std::string estado;
    std::string aerolinea;

    Plane* next;
    Plane* prev;

    // Constructor
    Plane(std::string v, std::string nr, std::string m, std::string f, int adf, int c, double pmd, std::string e, std::string a);

    // Display method
    void displayInfo() const;

    // Equality operator
    bool operator==(const Plane& other) const;
};

#endif

#include <iostream>
#include "Plane.h"
#include "DoubleCircularList.h"

int main() {
    // Creating a double circular list of planes
    DoubleCircularList<Plane> planeList;

    // Adding some planes with fictitious data
    planeList.addElement(Plane("AA100", "N123AA", "Boeing 737", "Boeing", 2015, 160, 79015, "En servicio", "American Airlines"));
    planeList.addElement(Plane("DL200", "N456DL", "Airbus A320", "Airbus", 2017, 150, 73500, "En mantenimiento", "Delta Airlines"));
    planeList.addElement(Plane("UA300", "N789UA", "Boeing 777", "Boeing", 2012, 396, 297550, "En servicio", "United Airlines"));
    planeList.addElement(Plane("SW400", "N101SW", "Boeing 737", "Boeing", 2018, 162, 79015, "En servicio", "Southwest Airlines"));
    planeList.addElement(Plane("BA500", "G-ZBJB", "Boeing 787", "Boeing", 2016, 242, 227930, "En servicio", "British Airways"));

    // Displaying information of all planes
    std::cout << "All planes:" << std::endl;
    planeList.displayElements();

    // Remove a plane
    planeList.removeElement(Plane("DL200", "N456DL", "Airbus A320", "Airbus", 2017, 150, 73500, "En mantenimiento", "Delta Airlines"));

    // Displaying information of all planes after removal
    std::cout << "Planes after removal:" << std::endl;
    planeList.displayElements();

    return 0;
}

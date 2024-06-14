#include <iostream>
#include <fstream>
#include "Plane.h"
#include "Passenger.h"
#include "DoubleCircularList.h"
#include "Queue.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

void displayMenu() {
    cout << "****************************" << endl;
    cout << "*        M E N U           *" << endl;
    cout << "****************************" << endl;
    cout << "1. Carga de opciones" << endl;
    cout << "2. Carga de pasajeros" << endl;
    cout << "3. Carga de movimiento" << endl;
    cout << "4. Consultar pasajeros" << endl;
    cout << "5. Visualizar reportes" << endl;
    cout << "6. Salir" << endl;
    cout << "****************************" << endl;
    cout << "Seleccione una opción: ";
}

DoubleCircularList<Plane> loadEnServicioList() {
	DoubleCircularList<Plane> enServicioList;
	// Load data from JSON file
    std::ifstream ifs("planes.json");
    if (!ifs.is_open()) {
        std::cerr << "Failed to open planes.json" << std::endl;
        return enServicioList;
    }
    
    nlohmann::json j;
    ifs >> j;
    
    // Iterate through JSON array and create Plane objects
    for (const auto& planeJson : j) {
        Plane plane(planeJson["vuelo"], planeJson["numero_de_registro"], planeJson["modelo"],
                    planeJson["fabricante"], planeJson["año_de_fabricación"], planeJson["capacidad"],
                    planeJson["peso_max_despegue"], planeJson["estado"], planeJson["aerolinea"]);

        if (plane.estado == "Disponible") {
            enServicioList.addElement(plane);
        }
    }
    return enServicioList;
}

DoubleCircularList<Plane> loadEnMantenimientoList() {
	DoubleCircularList<Plane> enServicioList;
	// Load data from JSON file
    std::ifstream ifs("planes.json");
    if (!ifs.is_open()) {
        std::cerr << "Failed to open planes.json" << std::endl;
        return enServicioList;
    }
    
    nlohmann::json j;
    ifs >> j;
    
    // Iterate through JSON array and create Plane objects
    for (const auto& planeJson : j) {
        Plane plane(planeJson["vuelo"], planeJson["numero_de_registro"], planeJson["modelo"],
                    planeJson["fabricante"], planeJson["año_de_fabricación"], planeJson["capacidad"],
                    planeJson["peso_max_despegue"], planeJson["estado"], planeJson["aerolinea"]);

        if (plane.estado == "Mantenimiento") {
            enServicioList.addElement(plane);
        }
    }
    return enServicioList;
}

Queue<Passenger> loadPasajerosQueue() {
	Queue<Passenger> pasajerosQueue;
	// Load data from JSON file
    std::ifstream ifs("passengers.json");
    if (!ifs.is_open()) {
        std::cerr << "Failed to open planes.json" << std::endl;
        return pasajerosQueue;
    }
    
    nlohmann::json j;
    ifs >> j;
    
    // Iterate through JSON array and create Plane objects
    for (const auto& passengerJson : j) {
        Passenger passenger(passengerJson["nombre"], passengerJson["nacionalidad"],
                            passengerJson["numero_de_pasaporte"], passengerJson["vuelo"],
                            passengerJson["asiento"], passengerJson["destino"],
                            passengerJson["origen"], passengerJson["equipaje_facturado"]);

        // Add passenger to the list
        pasajerosQueue.enqueue(passenger);
    }
    return pasajerosQueue;
}

int main() {
	DoubleCircularList<Plane> enServicioList = loadEnServicioList();
    DoubleCircularList<Plane> enMantenimientoList = loadEnMantenimientoList();
    
    Queue<Passenger> pasajerosQueue = loadPasajerosQueue();
    
    // Display planes in both lists
    std::cout << "Aviones en Servicio:" << std::endl;
    enServicioList.displayElements();

    std::cout << "Aviones en Mantenimiento:" << std::endl;
    enMantenimientoList.displayElements();
    
    std::cout << "------------------------" << std::endl;
    pasajerosQueue.displayQueue();
	
    int option;
    do {
        displayMenu();
        cin >> option;

        switch(option) {
            case 1:
                cout << "Opción 1 seleccionada: Carga de aviones" << endl;
                break;
            case 2:
                cout << "Opción 2 seleccionada: Carga de pasajeros" << endl;
                break;
            case 3:
                cout << "Opción 3 seleccionada: Carga de movimiento" << endl;
                break;
            case 4:
                cout << "Opción 4 seleccionada: Consultar pasajeros" << endl;
                break;
            case 5:
                cout << "Opción 5 seleccionada: Visualizar reportes" << endl;
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida, por favor intente nuevamente." << endl;
                break;
        }

        cout << endl;

    } while (option != 6);

    return 0;
}

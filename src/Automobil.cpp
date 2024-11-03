#include "Automobil.h"
#include <iostream>

// Constructorul inițializează atributele și alocă memorie pentru kilometraj
Automobil::Automobil(const std::string& marca, const std::string& model, int an, int km)
    : marca(marca), model(model), anFabricatie(an), kilometraj(new int(km)) {
    std::cout << "Constructor: Automobil creat - Marca: " << marca
              << ", Model: " << model << ", An: " << anFabricatie
              << ", Kilometraj: " << *kilometraj << " km\n";
}

// Destructorul eliberează memoria alocată pe heap pentru kilometraj
Automobil::~Automobil() {
    std::cout << "Destructor: Eliberare memorie pentru kilometraj (" << *kilometraj << " km) pentru "
              << "Automobilul - Marca: " << marca << ", Model: " << model << "\n";
    delete kilometraj;
}

Automobil& Automobil::operator=(const Automobil& other) {
    // Verificăm dacă obiectul curent este diferit de cel copiat (pentru a evita auto-atribuirea)
    if (this != &other) {
        std::cout << "Operator=: Începem copierea atributelor de la un alt Automobil.\n";

        // Eliberăm memoria alocată anterior pentru kilometraj, dacă există
        if (kilometraj != nullptr) {
            std::cout << "Operator=: Eliberăm memoria existentă pentru kilometraj (" << *kilometraj << " km).\n";
            delete kilometraj;
        }

        // Copiem valorile atributelor simple (marca, modelul, anFabricatie)
        marca = other.marca;
        model = other.model;
        anFabricatie = other.anFabricatie;

        // Alocăm memorie nouă pentru kilometraj și copiem valoarea kilometrajului din obiectul sursă
        kilometraj = new int(*other.kilometraj);
        std::cout << "Operator=: Memorie nouă alocată și kilometraj copiat: " << *kilometraj << " km\n";
    } else {
        std::cout << "Operator=: Auto-atribuire detectată, nicio acțiune necesară.\n";
    }

    // Returnăm referința la obiectul curent pentru a permite atribuiri în lanț
    return *this;
}


// Getter pentru marca automobilului
std::string Automobil::getMarca() const { return marca; }

// Getter pentru modelul automobilului
std::string Automobil::getModel() const { return model; }

// Getter pentru anul de fabricație
int Automobil::getAnFabricatie() const { return anFabricatie; }

// Getter pentru kilometrajul automobilului
int Automobil::getKilometraj() const { return *kilometraj; }

// Setter pentru a actualiza kilometrajul
void Automobil::setKilometraj(int km) {
    *kilometraj = km;
    std::cout << "setKilometraj: Kilometraj actualizat la " << *kilometraj << " km pentru "
              << "Automobilul - Marca: " << marca << ", Model: " << model << "\n";
}

#include "Automobil.h"
#include <iostream>

// Constructorul initializeaza atributele si aloca memorie pentru kilometraj
Automobil::Automobil(const std::string& marca, const std::string& model, int an, int km)
    : marca(marca), model(model), anFabricatie(an), kilometraj(new int(km)) {
    std::cout << "Constructor: Automobil creat - Marca: " << marca
              << ", Model: " << model << ", An: " << anFabricatie
              << ", Kilometraj: " << *kilometraj << " km\n";
}

// Destructorul elibereaza memoria alocata pe heap pentru kilometraj
Automobil::~Automobil() {
    std::cout << "Destructor: Eliberare memorie pentru kilometraj (" << *kilometraj << " km) pentru "
              << "Automobilul - Marca: " << marca << ", Model: " << model << "\n";
    delete kilometraj;
}

Automobil& Automobil::operator=(const Automobil& other) {
    // Verificam daca obiectul curent este diferit de cel copiat (pentru a evita auto-atribuirea)
    if (this != &other) {
        std::cout << "Operator=: Incepem copierea atributelor de la un alt Automobil.\n";

        // Eliberam memoria alocata anterior pentru kilometraj, dacă exista
        if (kilometraj != nullptr) {
            std::cout << "Operator=: Eliberam memoria existentă pentru kilometraj (" << *kilometraj << " km).\n";
            delete kilometraj;
        }

        // Copiem valorile atributelor simple (marca, modelul, anFabricatie)
        marca = other.marca;
        model = other.model;
        anFabricatie = other.anFabricatie;

        // Alocam memorie noua pentru kilometraj și copiem valoarea kilometrajului din obiectul sursa
        kilometraj = new int(*other.kilometraj);
        std::cout << "Operator=: Memorie noua alocata si kilometraj copiat: " << *kilometraj << " km\n";
    } else {
        std::cout << "Operator=: Auto-atribuire detectata, nicio actiune necesara.\n";
    }

    // Returnam referința la obiectul curent pentru a permite atribuiri în lanț
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

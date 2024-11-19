#include "automobil.h"

// Constructor
Automobil::Automobil(const std::string& marca, const std::string& model, int an, const std::string& culoare)
    : marca(marca), model(model), anFabricatie(an), vopsea(new std::string(culoare)) {
    std::cout << " Obiect creat: " << marca << " " << model << ", An: " << an << ", Culoare: " << *vopsea << "\n";
}

// Destructor
Automobil::~Automobil() {
    if (vopsea != nullptr) {
        std::cout << " Eliberare memorie pentru vopsea: " << *vopsea << " pentru Automobil: " << marca << ", " << model << "\n";
        delete vopsea;
    } else {
        std::cout << " Nu este nevoie de eliberarea memoriei " << marca << ", " << model << "\n";
    }
}

// Copy Constructor
Automobil::Automobil(const Automobil& other)
    : marca(other.marca), model(other.model), anFabricatie(other.anFabricatie), vopsea(new std::string(*other.vopsea)) {
    std::cout << " Copiere obiect: " << marca << " " << model << "\n";
}

// Move Constructor
Automobil::Automobil(Automobil&& other) noexcept
    : marca(std::move(other.marca)), model(std::move(other.model)), anFabricatie(other.anFabricatie), vopsea(other.vopsea) {
    other.vopsea = nullptr;//punem pointerul vopsea pe null
    std::cout << " Mutare resurse pentru obiect: " << marca << " " << model << "\n";
}

// Copy Assignment Operator
Automobil& Automobil::operator=(const Automobil& other) {
    if (this != &other) {
        std::cout << " Copiere valori pentru Automobil: " << marca << "\n";
        delete vopsea;
        marca = other.marca;
        model = other.model;
        anFabricatie = other.anFabricatie;
        vopsea = new std::string(*other.vopsea);
    }
    return *this;
}

// Move Assignment Operator
Automobil& Automobil::operator=(Automobil&& other) noexcept {
    if (this != &other) {
        std::cout << " Mutare resurse pentru Automobil: " << marca << "\n";
        delete vopsea;
        marca = std::move(other.marca);
        model = std::move(other.model);
        anFabricatie = other.anFabricatie;
        vopsea = other.vopsea;
        other.vopsea = nullptr;
    }
    return *this;
}

// Getters
std::string Automobil::getMarca() const { return marca; }
std::string Automobil::getModel() const { return model; }
int Automobil::getAnFabricatie() const { return anFabricatie; }
std::string Automobil::getVopsea() const { return *vopsea; }

// Setter for vopsea
void Automobil::setVopsea(const std::string& culoareNoua) {
    *vopsea = culoareNoua;
    std::cout << "Setter- Culoare schimbata in: " << *vopsea << " pentru Automobil: " << marca << ", " << model << "\n";
}

// Derived class MasinaDeCurse constructor
MasinaDeCurse::MasinaDeCurse(const std::string& marca, const std::string& model, int an, const std::string& culoare, int vitezaMaxima)
    : Automobil(marca, model, an, culoare), vitezaMaxima(vitezaMaxima) {
    std::cout << " Obiect creat: " << marca << " " << model << " cu viteza maxima: " << vitezaMaxima << " km/h\n";
}

// Destructor
MasinaDeCurse::~MasinaDeCurse() {
    std::cout << "Distrugere obiect: " << marca << " " << model << "\n";
}

// Copy Constructor
MasinaDeCurse::MasinaDeCurse(const MasinaDeCurse& other)
    : Automobil(other), vitezaMaxima(other.vitezaMaxima) {
    std::cout << " Copiere obiect MasinaDeCurse: " << marca << " " << model << "\n";
}

// Move Constructor
MasinaDeCurse::MasinaDeCurse(MasinaDeCurse&& other) noexcept
    : Automobil(std::move(other)), vitezaMaxima(other.vitezaMaxima) {
    std::cout << " Mutare resurse pentru MasinaDeCurse: " << marca << " " << model << "\n";
    other.vitezaMaxima = 0;
}

// Copy Assignment Operator
MasinaDeCurse& MasinaDeCurse::operator=(const MasinaDeCurse& other) {
    if (this != &other) {
        Automobil::operator=(other);
        vitezaMaxima = other.vitezaMaxima;
        std::cout << " Copiere valori pentru MasinaDeCurse: " << marca << "\n";
    }
    return *this;
}

// Move Assignment Operator
MasinaDeCurse& MasinaDeCurse::operator=(MasinaDeCurse&& other) noexcept {
    if (this != &other) {
        Automobil::operator=(std::move(other)); 
        vitezaMaxima = other.vitezaMaxima;
        other.vitezaMaxima = 0;
        std::cout << " Mutare resurse pentru MasinaDeCurse: " << marca << "\n";
    }
    return *this;
}

// Getter and Setter for vitezaMaxima
int MasinaDeCurse::getVitezaMaxima() const { return vitezaMaxima; }
void MasinaDeCurse::setVitezaMaxima(int vitezaNoua) {
    vitezaMaxima = vitezaNoua;
    std::cout << "Getter- Viteza maxima setata la: " << vitezaMaxima << " km/h\n";
}

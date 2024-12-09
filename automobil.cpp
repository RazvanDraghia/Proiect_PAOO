#include "automobil.h"

// Constructor
Automobil::Automobil(const std::string& marca, const std::string& model, int an, const std::string& culoare)
    : marca(marca), model(model), anFabricatie(an), vopsea(std::make_unique<std::string>(culoare)) {
    std::cout << " Obiect creat: " << marca << " " << model << ", An: " << an << ", Culoare: " << *vopsea << "\n";
}

// Destructor
Automobil::~Automobil() {
    std::lock_guard<std::mutex> lock(mtx); // asiguram sincronizarea
    std::cout << " Destructor pentru Automobil: " << marca << ", " << model << "\n";
}

// Copy Constructor
Automobil::Automobil(const Automobil& other)
    : marca(other.marca), model(other.model), anFabricatie(other.anFabricatie), vopsea(std::make_unique<std::string>(*other.vopsea)) {
    std::cout << " Copiere obiect: " << marca << " " << model << "\n";
}

// Move Constructor
Automobil::Automobil(Automobil&& other) noexcept
    : marca(std::move(other.marca)), model(std::move(other.model)), anFabricatie(other.anFabricatie), vopsea(std::move(other.vopsea)) {
    std::cout << " Mutare resurse pentru obiect: " << marca << " " << model << "\n";
}

// Copy Assignment Operator
Automobil& Automobil::operator=(const Automobil& other) {
    if (this != &other) {
        std::lock_guard<std::mutex> lock(mtx);
        marca = other.marca;
        model = other.model;
        anFabricatie = other.anFabricatie;
        vopsea = std::make_unique<std::string>(*other.vopsea);
        std::cout << " Copiere valori pentru Automobil: " << marca << "\n";
    }
    return *this;
}

// Move Assignment Operator
Automobil& Automobil::operator=(Automobil&& other) noexcept {
    if (this != &other) {
        std::lock_guard<std::mutex> lock(mtx);
        marca = std::move(other.marca);
        model = std::move(other.model);
        anFabricatie = other.anFabricatie;
        vopsea = std::move(other.vopsea);
        std::cout << " Mutare resurse pentru Automobil: " << marca << "\n";
    }
    return *this;
}

// Getters
std::string Automobil::getMarca() const { return marca; }
std::string Automobil::getModel() const { return model; }
int Automobil::getAnFabricatie() const { return anFabricatie; }
std::string Automobil::getVopsea() const {
    std::lock_guard<std::mutex> lock(mtx);
    return *vopsea;
}

// Setter for vopsea
void Automobil::setVopsea(const std::string& culoareNoua) {
    std::lock_guard<std::mutex> lock(mtx);
    *vopsea = culoareNoua;
    std::cout << "Setter- Culoare schimbata in: " << *vopsea << " pentru Automobil: " << marca << ", " << model << "\n";
}

// Constructor MasinaDeCurse
MasinaDeCurse::MasinaDeCurse(const std::string& marca, const std::string& model, int an, const std::string& culoare, int vitezaMaxima)
    : Automobil(marca, model, an, culoare), vitezaMaxima(vitezaMaxima), motorPerformanta(std::make_shared<int>(vitezaMaxima)) {
    std::cout << " Obiect creat: " << marca << " " << model << " cu viteza maxima: " << vitezaMaxima << " km/h\n";
}

// Destructor MasinaDeCurse
MasinaDeCurse::~MasinaDeCurse() {
    std::cout << " Destructor pentru MasinaDeCurse: " << marca << " " << model << "\n";
}

// Copy Constructor
MasinaDeCurse::MasinaDeCurse(const MasinaDeCurse& other)
    : Automobil(other), vitezaMaxima(other.vitezaMaxima), motorPerformanta(other.motorPerformanta) {
    std::cout << " Copiere obiect MasinaDeCurse: " << marca << " " << model << "\n";
}

// Move Constructor
MasinaDeCurse::MasinaDeCurse(MasinaDeCurse&& other) noexcept
    : Automobil(std::move(other)), vitezaMaxima(other.vitezaMaxima), motorPerformanta(std::move(other.motorPerformanta)) {
    std::cout << " Mutare resurse pentru MasinaDeCurse: " << marca << " " << model << "\n";
}

// Copy Assignment Operator
MasinaDeCurse& MasinaDeCurse::operator=(const MasinaDeCurse& other) {
    if (this != &other) {
        Automobil::operator=(other);
        vitezaMaxima = other.vitezaMaxima;
        motorPerformanta = other.motorPerformanta;
        std::cout << " Copiere valori pentru MasinaDeCurse: " << marca << "\n";
    }
    return *this;
}

// Move Assignment Operator
MasinaDeCurse& MasinaDeCurse::operator=(MasinaDeCurse&& other) noexcept {
    if (this != &other) {
        Automobil::operator=(std::move(other));
        vitezaMaxima = other.vitezaMaxima;
        motorPerformanta = std::move(other.motorPerformanta);
        std::cout << " Mutare resurse pentru MasinaDeCurse: " << marca << "\n";
    }
    return *this;
}

// Getter and Setter for vitezaMaxima
int MasinaDeCurse::getVitezaMaxima() const { return vitezaMaxima; }
void MasinaDeCurse::setVitezaMaxima(int vitezaNoua) {
    vitezaMaxima = vitezaNoua;
    *motorPerformanta = vitezaNoua;
    std::cout << "Setter- Viteza maxima setata la: " << vitezaMaxima << " km/h\n";
}

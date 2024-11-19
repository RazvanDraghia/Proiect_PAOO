#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include <string>
#include <iostream>

class Automobil {
protected:
    std::string marca;  // marca masinii
    std::string model;  // modelul
    int anFabricatie;   // anul fabricatiei
    std::string* vopsea; // vopseaua masinii care este un pointer alocat in heap

public:
    // constructorul pentru obiectul automobil
    Automobil(const std::string& marca, const std::string& model, int an, const std::string& culoare);

    // destructorul
    virtual ~Automobil();

    // copy constructor, folosim const pentru ca nu vrem ca sa se modifice din greseala variabilele automobilului
    Automobil(const Automobil& other);

    // move constructor
    Automobil(Automobil&& other) noexcept;

    // operatorul copy assigment
    Automobil& operator=(const Automobil& other);

    // operatorul move assigment
    Automobil& operator=(Automobil&& other) noexcept;

    // getters & setters
    std::string getMarca() const;
    std::string getModel() const;
    int getAnFabricatie() const;
    std::string getVopsea() const;
    void setVopsea(const std::string& culoareNoua);
};

// clasa masina de curse care este derivata din automobil care are in plus, un top speed
class MasinaDeCurse : public Automobil {
private:
    int vitezaMaxima; // top speed-ul

public:
    // constructorul clasei derivate
    MasinaDeCurse(const std::string& marca, const std::string& model, int an, const std::string& culoare, int vitezaMaxima);

    // destructorul clasei derivate
    ~MasinaDeCurse() override;

    // copy constructor, folosim const pentru ca nu vrem ca sa se modifice din greseala variabilele automobilului
    MasinaDeCurse(const MasinaDeCurse& other);

    // move constructor
    MasinaDeCurse(MasinaDeCurse&& other) noexcept;

    // operatorul copy assigment
    MasinaDeCurse& operator=(const MasinaDeCurse& other);

    // operatorul move assigment
    MasinaDeCurse& operator=(MasinaDeCurse&& other) noexcept;

    // getters & setters
    int getVitezaMaxima() const;
    void setVitezaMaxima(int vitezaNoua);
};

#endif



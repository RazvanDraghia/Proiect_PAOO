#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include <string>
#include <iostream>
#include <memory> // pentru std::unique_ptr si std::shared_ptr
#include <mutex>  // pentru std::mutex

class Automobil {
protected:
    std::string marca;  // marca masinii
    std::string model;  // modelul
    int anFabricatie;   // anul fabricatiei
    std::unique_ptr<std::string> vopsea; // vopseaua masinii este acum un unique_ptr
    mutable std::mutex mtx; // mutex pentru sincronizare

public:
    // constructorul pentru obiectul automobil
    Automobil(const std::string& marca, const std::string& model, int an, const std::string& culoare);

    // destructorul
    virtual ~Automobil();

    // copy constructor
    Automobil(const Automobil& other);

    // move constructor
    Automobil(Automobil&& other) noexcept;

    // operatorul copy assignment
    Automobil& operator=(const Automobil& other);

    // operatorul move assignment
    Automobil& operator=(Automobil&& other) noexcept;

    // getters & setters
    std::string getMarca() const;
    std::string getModel() const;
    int getAnFabricatie() const;
    std::string getVopsea() const;
    void setVopsea(const std::string& culoareNoua);
};

// clasa masina de curse derivata din automobil
class MasinaDeCurse : public Automobil {
private:
    int vitezaMaxima; // viteza maxima
    std::shared_ptr<int> motorPerformanta; // shared_ptr pentru resurse partajate

public:
    // constructorul clasei derivate
    MasinaDeCurse(const std::string& marca, const std::string& model, int an, const std::string& culoare, int vitezaMaxima);

    // destructorul clasei derivate
    ~MasinaDeCurse() override;

    // copy constructor
    MasinaDeCurse(const MasinaDeCurse& other);

    // move constructor
    MasinaDeCurse(MasinaDeCurse&& other) noexcept;

    // operatorul copy assignment
    MasinaDeCurse& operator=(const MasinaDeCurse& other);

    // operatorul move assignment
    MasinaDeCurse& operator=(MasinaDeCurse&& other) noexcept;

    // getters & setters
    int getVitezaMaxima() const;
    void setVitezaMaxima(int vitezaNoua);
};

#endif


#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include <string>

class Automobil {
private:
    std::string marca;         // Marca automobilului
    std::string model;         // Modelul automobilului
    int anFabricatie;          // Anul de fabricație
    int* kilometraj;           // Pointer pentru kilometraj, alocat pe heap

public:
    // Constructor cu parametri pentru inițializarea atributelor
    Automobil(const std::string& marca, const std::string& model, int an, int km);
    
    // Destructor pentru eliberarea memoriei alocate pe heap
    ~Automobil();
    
    // Operator de atribuire pentru copierea corectă a atributelor între obiecte
    Automobil& operator=(const Automobil& other);

    // Metode de acces pentru atribute
    std::string getMarca() const;
    std::string getModel() const;
    int getAnFabricatie() const;
    int getKilometraj() const;
    void setKilometraj(int km);  // Metodă pentru a seta noul kilometraj
};

#endif


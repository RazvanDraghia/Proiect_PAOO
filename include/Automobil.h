#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include <string>

class Automobil {
///aic facem incapsularea
private:
    std::string marca;//marca msinii
    std::string model;//modelul auto
    int anFabricatie;//anul de fabricatie
    std::string* vopsea;//pointer pentru culoare, alocat pe heap

public:
    //constructor care are parametrii de initializare
    Automobil(const std::string& marca, const std::string& model, int an, const std::string& culoare);
    
    //destructor pentru eliberarea memoriei alocate pe heap 
    ~Automobil();
    
    //operatorul de copierea unui obiect
    Automobil& operator=(const Automobil& other);

    //metodele care ne ofera marca, modelul,anul de fabricatie vopseaua
    std::string getMarca() const;
    std::string getModel() const;
    int getAnFabricatie() const;
    std::string getVopsea() const;
    void setVopsea(const std::string& culoareNoua);//metoda de schimbare avopselei
};

#endif


#include "automobil.h"
#include <iostream>

//facem un constructor pt initializare si formare si vopsea care se aloca pe heap pnetru a fi modificata pe parcurs cand se cere 
Automobil::Automobil(const std::string& marca, const std::string& model, int an, const std::string& culoare)
    : marca(marca), model(model), anFabricatie(an), vopsea(new std::string(culoare)) {
    std::cout<<"constructor:Obiectul-automobil este creat-marca: "<< marca<<", model: "<<model<<",an:"<<anFabricatie<<", culoare: "<<*vopsea<<"\n";
}

//destructorul elibereaza memoria alocata pe heap pentru vopsea
Automobil::~Automobil() {
    std::cout<<"Eliberare memorie pentru vopsea ("<<*vopsea<<") pentru "<<" Masina-Marca: "<<marca<<", model: "<<model<<"\n";
    delete vopsea;
}

Automobil& Automobil::operator=(const Automobil& other) {
    // facem o verificare sa vedem daca obiectul auto curent este diferit de cel copiat
    if (this != &other) {
        std::cout << "Facem copierea caracteristicilor unui obiect masina in altul\n";
        // eliberam memoria din heap in caz ca este, adica la locatia de memorie din heap unde vrem sa punem noua valoare, trebuie sa fie gol
	//inainte sa facem modificari
        if (vopsea != nullptr) {
            std::cout<<"eliberam memoria ("<<*vopsea<<").\n";
            delete vopsea;
        }
        //copiem valorile masinii(marca, modelul, anFabricatie)
        marca=other.marca;
        model=other.model;
        anFabricatie = other.anFabricatie;

        //alocam memorie pentru noua vopsea
        vopsea=new std::string(*other.vopsea);
        std::cout<<"memoria este alocata pentru noua vopsea: "<<*vopsea<<"\n";
    } else {
        std::cout<<"in caz ca s-a faut deja acest proces, nu mai este nevoie de inca o vopsire.\n";
    }

    //returnam referința la obiectul curent
    return *this;
}

//getter pentru marca automobilului
std::string Automobil::getMarca() const{return marca;}

//getter pentru modelul automobilului
std::string Automobil::getModel() const{return model;}

//getter pentru anul de fabricație
int Automobil::getAnFabricatie() const{return anFabricatie;}

//getter pentru vopseaua automobilului
std::string Automobil::getVopsea() const{return *vopsea;}

//setter pentru a schimba vopseaua
void Automobil::setVopsea(const std::string& culoareNoua) {
    *vopsea = culoareNoua;
    std::cout <<"setVopsea: culoare schimbata: "<<*vopsea<<"pentru"<<"Masina-Marca:"<<marca<<", Model: "<<model<<"\n";
}

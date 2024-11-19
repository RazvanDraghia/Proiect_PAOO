#include <iostream>
#include "automobil.h"

int main() {
    std::cout << " Creare obiecte\n";

    // crearea obiectelor automobil
    Automobil auto1("BMW", "F11(Seria 5)", 2012, "Rosu");
    MasinaDeCurse masinaDeCurse("Ferrari", "488 Pista", 2020, "Rosu", 340);

    // afisam proprietattil initiale ale masinilor
    std::cout << "\n Afisam detalii initiale pentru obiectele create:\n";
    std::cout << "Automobil auto1: " << auto1.getMarca() << ", " << auto1.getModel() << ", An: " << auto1.getAnFabricatie() << ", Culoare: " << auto1.getVopsea() << "\n";
    std::cout << "Masina de Curse: " << masinaDeCurse.getMarca() << ", " << masinaDeCurse.getModel() << ", An: " << masinaDeCurse.getAnFabricatie() << ", Culoare: " << masinaDeCurse.getVopsea() << ", Viteza Maxima: " << masinaDeCurse.getVitezaMaxima() << " km/h\n";

    // schimbam culoarea automobilului BMW si ii facem soft la Ferrari
    std::cout << "\n Modificam valorile obiectelor, o schimbare de culoare la BMW si un SOFT la motor la Ferrari:\n";
    auto1.setVopsea("Negru"); 
    masinaDeCurse.setVitezaMaxima(423);  

    // afisam sa vedem daca copy constructorul si move constructorul functioneaza
    std::cout << "\n Afisam sa vedem daca Copy Constructorul a functionat pentru MasinaDeCurse: \n";
    MasinaDeCurse masinaCopy = masinaDeCurse; 

    std::cout << "\n Afisam sa vedem daca Move Constructorul a functionat pentru MasinaDeCurse:\n";
    MasinaDeCurse masinaMoved = std::move(masinaDeCurse); 

    // afisam noile culori si noile imbunatatiri de performanta a masinilor
    std::cout << "\n Afisam valorile actualizate ale obiectelor:\n";
    std::cout << "Automobil auto1 (vopsit): " << auto1.getMarca() << ", " << auto1.getModel() << ", An: " << auto1.getAnFabricatie() << ", Culoare: " << auto1.getVopsea() << "\n";
    std::cout << "Masina de Curse2 (copie): " << masinaCopy.getMarca() << ", " << masinaCopy.getModel() << ", An: " << masinaCopy.getAnFabricatie() << ", Culoare: " << masinaCopy.getVopsea() << ", Viteza Maxima: " << masinaCopy.getVitezaMaxima() << " km/h\n";
    std::cout << "Masina de Curse (din move): " << masinaMoved.getMarca() << ", " << masinaMoved.getModel() << ", An: " << masinaMoved.getAnFabricatie() << ", Culoare: " << masinaMoved.getVopsea() << ", Viteza Maxima: " << masinaMoved.getVitezaMaxima() << " km/h\n";

    std::cout << "Apelam destructorii la finalul programului pentru eliberarea memoriei\n";

    return 0;
}


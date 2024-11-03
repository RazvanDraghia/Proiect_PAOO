#include <iostream>
#include "Automobil.h"

int main() {
    // Creăm mai multe obiecte Automobil folosind constructorul
    Automobil auto1("BMW", "F11(Seria 5)", 2012, 186890);
    Automobil auto2("Mercedes", "C-Class", 2010, 298140);
    Automobil auto3("Audi", "A4", 2019, 145678);
    Automobil auto4("Range Rover", "Sport", 2021, 2455);

    std::cout << "\n===== Testare operator de atribuire =====\n";

    // Folosim operatorul de atribuire pentru a copia un obiect în altul
    Automobil auto5 = auto1;  // auto5 primește valorile din auto1
    std::cout << "Copierea lui auto1 (BMW F11) în auto5\n";

    Automobil auto6 = auto2;  // auto6 primește valorile din auto2
    std::cout << "Copierea lui auto2 (Mercedes C-Class) în auto6\n";

    // Afișăm detalii pentru fiecare automobil creat, inclusiv copii
    std::cout << "\n===== Afișarea detaliilor pentru fiecare automobil =====\n";
    std::cout << "auto1 - Marca: " << auto1.getMarca()
              << ", Model: " << auto1.getModel()
              << ", An: " << auto1.getAnFabricatie()
              << ", Kilometraj: " << auto1.getKilometraj() << " km\n";

    std::cout << "auto2 - Marca: " << auto2.getMarca()
              << ", Model: " << auto2.getModel()
              << ", An: " << auto2.getAnFabricatie()
              << ", Kilometraj: " << auto2.getKilometraj() << " km\n";

    std::cout << "auto3 - Marca: " << auto3.getMarca()
              << ", Model: " << auto3.getModel()
              << ", An: " << auto3.getAnFabricatie()
              << ", Kilometraj: " << auto3.getKilometraj() << " km\n";

    std::cout << "auto4 - Marca: " << auto4.getMarca()
              << ", Model: " << auto4.getModel()
              << ", An: " << auto4.getAnFabricatie()
              << ", Kilometraj: " << auto4.getKilometraj() << " km\n";

    std::cout << "auto5 - Marca: " << auto5.getMarca()
              << ", Model: " << auto5.getModel()
              << ", An: " << auto5.getAnFabricatie()
              << ", Kilometraj: " << auto5.getKilometraj() << " km (copie a lui auto1)\n";

    std::cout << "auto6 - Marca: " << auto6.getMarca()
              << ", Model: " << auto6.getModel()
              << ", An: " << auto6.getAnFabricatie()
              << ", Kilometraj: " << auto6.getKilometraj() << " km (copie a lui auto2)\n";

    // Modificăm kilometrajul pentru câteva obiecte pentru a vedea efectul
    auto1.setKilometraj(55000);  // Actualizăm kilometrajul pentru auto1
    auto3.setKilometraj(45000);  // Actualizăm kilometrajul pentru auto3

    // Afișăm din nou detaliile pentru a observa schimbările
    std::cout << "\n===== Afișarea detaliilor după modificarea kilometrajului =====\n";
    std::cout << "auto1 - Marca: " << auto1.getMarca()
              << ", Model: " << auto1.getModel()
              << ", An: " << auto1.getAnFabricatie()
              << ", Kilometraj: " << auto1.getKilometraj() << " km (kilometraj actualizat)\n";

    std::cout << "auto3 - Marca: " << auto3.getMarca()
              << ", Model: " << auto3.getModel()
              << ", An: " << auto3.getAnFabricatie()
              << ", Kilometraj: " << auto3.getKilometraj() << " km (kilometraj actualizat)\n";

    // Destructorii pentru fiecare obiect vor fi apelați automat la sfârșitul programului
    std::cout << "\n===== Programul se încheie - Destructorii vor fi apelați automat =====\n";

    return 0;
}


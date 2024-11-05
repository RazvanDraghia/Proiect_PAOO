#include <iostream>
#include "automobil.h"

int main() {
    //cream mai multe obiecte Automobil folosind constructorul
    Automobil auto1("BMW", "F11(Seria 5)", 2012, "Rosu");
    Automobil auto2("Mercedes", "C-Class", 2010, "Albastru");
    Automobil auto3("Audi", "A4", 2019, "Verde");

    std::cout<<"\nincercam copierea unei masini in alt auto\n";

    //folosim operatorul de atribuire pentru a copia un obiect în altul
    Automobil auto4 = auto1;  // auto4 primeste valorile din auto1
    std::cout<<"Copierea masinii (BMW F11) intr-o copie auto4\n";

    //afisam detalii pentru fiecare automobil creat, si o copie a unuia
    std::cout<< "\nafisarea detaliilor pentru fiecare automobil\n";
    std::cout<< "masina1-marca:"<<auto1.getMarca()<<", model:"<<auto1.getModel()<<", an:"<<auto1.getAnFabricatie()<<",culoare: "<<auto1.getVopsea()<<"\n";
    std::cout<<"masina2-marca:"<<auto2.getMarca()<<", model:"<<auto2.getModel()<<", an:"<<auto2.getAnFabricatie()<<",culoare: "<<auto2.getVopsea()<< "\n";
    std::cout<<"masina3-marca:"<<auto3.getMarca()<<", model:"<<auto3.getModel()<<", an:"<<auto3.getAnFabricatie()<<",culoare:"<<auto3.getVopsea()<< "\n";
    std::cout<<"masina4-marca:"<<auto4.getMarca()<<", model:"<<auto4.getModel()<<",an:"<<auto4.getAnFabricatie()<<",culoare:"<< auto4.getVopsea()<<"(copie a lui auto1)\n";

    //schimbam culoarea masinilor(obiecte)
    auto1.setVopsea("Galben");  //masina1 se vopseste in galben
    auto3.setVopsea("Negru");   //masina3 se vopseste in negru

    //afișam noile detalii ale masinilor sa vedem daca aplicarea vopselei a functionat
    std::cout<< "\nafișare a noilor culori a masinii\n";
    std::cout<<"masina1-marca:"<<auto1.getMarca()<<", model:"<<auto1.getModel()<< ",an: "<<auto1.getAnFabricatie()<<", culoare noua: "<<auto1.getVopsea();

    std::cout<<"maasina3-marca:"<<auto3.getMarca()<<", model:"<<auto3.getModel()<<",an: "<<auto3.getAnFabricatie()<<", culoare noua: "<<auto3.getVopsea();

    //destructorii ii apelam la finalul programului
    std::cout<<"Procesul de vopsire a masnii a fost realizat cu succes, acum este momentul in care se apeleaza destructorii pentru a elibera memoria\n";

    return 0;
}

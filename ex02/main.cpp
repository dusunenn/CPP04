#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=========================================" << std::endl;
    std::cout << "       BOLUM 1: SOYUT SINIF TESTI        " << std::endl;
    std::cout << "=========================================" << std::endl;

    // AAnimal soyut bir sınıf olduğu için aşağıdaki satır HATA verir.
    // Derleyicinin hata vereceğini görmek için yorum satırını kaldırabilirsin.
    
    // const AAnimal* meta = new AAnimal(); 
    // std::cout << "Bunu goremezsin cunku derlenmez." << std::endl;

    std::cout << ">> new AAnimal() yapilamiyor (Basarili)." << std::endl;
    std::cout << ">> Ancak AAnimal* isaretcisi kullanilabilir.\n" << std::endl;

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << "j'nin Tipi: " << j->getType() << std::endl;
    std::cout << "i'nin Tipi: " << i->getType() << std::endl;

    std::cout << "\n[Ses Testi]" << std::endl;
    j->makeSound(); // Dog::makeSound() çalışır
    i->makeSound(); // Cat::makeSound() çalışır

    delete j; // Önce ~Dog(), sonra ~Brain(), sonra ~AAnimal()
    delete i; // Önce ~Cat(), sonra ~Brain(), sonra ~AAnimal()


    std::cout << "\n\n=========================================" << std::endl;
    std::cout << "       BOLUM 2: DERIN KOPYALAMA TESTI    " << std::endl;
    std::cout << "=========================================" << std::endl;

    std::cout << ">> Bir kopek olusturuluyor (Kopek 1)..." << std::endl;
    Dog* dog1 = new Dog();
    
    // Kopek 1'in beynine bir fikir ekleyelim
    // Not: Dog sınıfında getBrain() metodunu public varsayıyoruz.
    if (dog1->getBrain())
        dog1->getBrain()->ideas[0] = "KEMIK ISTIYORUM!";
    
    std::cout << ">> Kopek 1'den Kopek 2 kopyalaniyor (Copy Constructor)..." << std::endl;
    Dog* dog2 = new Dog(*dog1);

    std::cout << "\n[Degisiklikten Once]" << std::endl;
    std::cout << "Kopek 1 Fikri: " << dog1->getBrain()->ideas[0] << std::endl;
    std::cout << "Kopek 2 Fikri: " << dog2->getBrain()->ideas[0] << std::endl;

    // Simdi Kopek 2'nin fikrini degistirelim
    std::cout << "\n>> Kopek 2'nin fikri degistiriliyor..." << std::endl;
    dog2->getBrain()->ideas[0] = "UYUMAK ISTIYORUM...";

    std::cout << "\n[Degisiklikten Sonra (Bagimsizlik Kontrolu)]" << std::endl;
    std::cout << "Kopek 1 Fikri: " << dog1->getBrain()->ideas[0] << " (Degismemeli)" << std::endl;
    std::cout << "Kopek 2 Fikri: " << dog2->getBrain()->ideas[0] << " (Degismeli)" << std::endl;

    // Hafıza Adreslerini Kontrol Et
    std::cout << "\n[Adres Kontrolu]" << std::endl;
    std::cout << "Kopek 1 Beyin Adresi: " << dog1->getBrain() << std::endl;
    std::cout << "Kopek 2 Beyin Adresi: " << dog2->getBrain() << std::endl;

    if (dog1->getBrain() != dog2->getBrain())
        std::cout << ">> BASARILI: Beyin adresleri farkli (Deep Copy)." << std::endl;
    else
        std::cout << ">> HATA: Beyin adresleri ayni (Shallow Copy)!" << std::endl;

    delete dog1;
    delete dog2;

    return 0;
}
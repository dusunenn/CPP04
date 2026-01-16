#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // =========================================================
    // BÖLÜM 1: Doğru Polymorphism (PDF'teki Örnek)
    // =========================================================
    std::cout << "\n----- 1. Subject Test (Polymorphism Working) -----" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    // Tipleri yazdır (Dog ve Cat olarak gelmeli)
    std::cout << "J Type: " << j->getType() << " " << std::endl;
    std::cout << "I Type: " << i->getType() << " " << std::endl;

    // Sesleri Çıkar (Virtual olduğu için kendi sesleri çıkmalı)
    std::cout << "Cat Sound: ";
    i->makeSound(); // ÇIKTI: Meow! Meow!
    
    std::cout << "Dog Sound: ";
    j->makeSound(); // ÇIKTI: Woof! Woof!
    
    std::cout << "Animal Sound: ";
    meta->makeSound();

    // =========================================================
    // BÖLÜM 2: Yanlış Polymorphism (WrongAnimal Testi)
    // =========================================================
    std::cout << "\n----- 2. Wrong Animal Test (No Virtual Function) -----" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;

    // BURASI KRİTİK NOKTA:
    // Fonksiyon 'virtual' olmadığı için, işaretçinin türüne (WrongAnimal)
    // ait fonksiyon çağrılır. "Wrong Meow" yerine genel ses çıkar.
    std::cout << "WrongCat Sound: ";
    wrongCat->makeSound(); // ÇIKTI: WrongAnimal makes a weird sound...
    
    std::cout << "WrongAnimal Sound: ";
    wrongMeta->makeSound();

    // =========================================================
    // BÖLÜM 3: Temizlik (Memory Cleanup)
    // =========================================================
    std::cout << "\n----- 3. Destructors (Cleaning Memory) -----" << std::endl;
    
    // Doğru Sınıfları Silme (Virtual Destructor sayesinde güvenli)
    delete j;
    delete i;
    delete meta;

    // Yanlış Sınıfları Silme
    // Uyarı: WrongAnimal'da destructor virtual olmadığı için
    // sadece WrongAnimal kısmı silinir, WrongCat kısmı bellekte kalabilir (leak).
    // Ancak egzersiz bu hatayı göstermek üzerine kurulu olduğu için böyle bırakıyoruz.
    delete wrongCat;
    delete wrongMeta;

    return 0;
}
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        std::cout << "\n----- 1. Subject Test (Polymorphism Working) -----" << std::endl;

        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << "J Type: " << j->getType() << " " << std::endl;
        std::cout << "I Type: " << i->getType() << " " << std::endl;

        std::cout << "Cat Sound: ";
        i->makeSound();
        
        std::cout << "Dog Sound: ";
        j->makeSound();
        std::cout << "Animal Sound: ";
        meta->makeSound();

        delete j;
        delete i;
        delete meta;
    }
    // {
    //     std::cout << "\n----- 2. Wrong Animal Test (No Virtual Function) -----" << std::endl;

    //     const WrongAnimal* wrongMeta = new WrongAnimal();
    //     const WrongAnimal* wrongCat = new WrongCat();

    //     std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;


    //     std::cout << "WrongCat Sound: ";
    //     wrongCat->makeSound();
        
    //     std::cout << "WrongAnimal Sound: ";
    //     wrongMeta->makeSound();

    //     std::cout << "\n----- 3. Destructors (Cleaning Memory) -----" << std::endl;

    //     delete wrongCat;
    //     delete wrongMeta;
    // }
    return 0;
}
/*Derleyici bakar: "j bir Animal işaretçisi."

Derleyici Animal sınıfına gider ve makeSound fonksiyonuna bakar.

Fonksiyonun başında virtual kelimesini görür.

Derleyici der ki: "Tamam, bu fonksiyon sanal. O yüzden ben bu işaretçinin tipine (Animal) bakarak karar vermeyeceğim. Program çalıştığında (Runtime) bu işaretçi gerçekten neyi gösteriyorsa (Dog) onun fonksiyonunu çağıracağım."

Program çalışır, hafızadaki nesnenin Dog olduğunu görür ve Dog::makeSound çalışır.*/



/*Derleyici bakar: "wrongCat bir WrongAnimal işaretçisi."

    Derleyici WrongAnimal sınıfına gider ve makeSound fonksiyonuna bakar.

    Fonksiyonun başında virtual YOKTUR.

    Derleyici der ki: "Bu fonksiyon sanal değil. O zaman işaretçi neyse fonksiyon da odur. Bu bir WrongAnimal işaretçisi olduğuna göre WrongAnimal::makeSound çalışacak. İşaretçinin bellekte neyi tuttuğu (WrongCat) umurumda değil." (Buna Static Binding denir).

    Çıktı: Some generic wrong animal sound (Halbuki WrongCat nesnesiydi!)*/
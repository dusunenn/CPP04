#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// Konsol çıktılarını renklendirmek için (İsteğe bağlı, okunabilirliği artırır)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main()
{
    // --------------------------------------------------------------------
    // BÖLÜM 1: PDF'teki Zorunlu Test (Subject Test)
    // --------------------------------------------------------------------
    std::cout << BLUE << "\n=== 1. SUBJECT TEST (Polymorphism Working) ===" << RESET << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << "\n" << RED << "Destructors:" << RESET << std::endl;
    delete i;    // Önce ~Cat(), sonra ~Animal() çağrılmalı
    delete j;    // Önce ~Dog(), sonra ~Animal() çağrılmalı
    delete meta; // Sadece ~Animal() çağrılmalı

    
    // --------------------------------------------------------------------
    // BÖLÜM 2: Yanlış Sınıf Testi (Wrong Class Test)
    // Bu kısım 'virtual' kullanılmazsa ne olacağını kanıtlar.
    // --------------------------------------------------------------------
    std::cout << BLUE << "\n=== 2. WRONG ANIMAL TEST (Polymorphism FAIL) ===" << RESET << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat(); // Dikkat: Pointer tipi WrongAnimal

    std::cout << "\n" << YELLOW << "Types:" << RESET << std::endl;
    std::cout << "wrongCat is a: " << wrongCat->getType() << " " << std::endl;

    std::cout << "\n" << YELLOW << "Sounds (Expectation: WrongCat sounds like WrongAnimal):" << RESET << std::endl;
    
    std::cout << "WrongCat makes: ";
    wrongCat->makeSound(); 
    // BEKLENEN: WrongAnimal sesi çıkmalı! (Çünkü virtual değil)
    // EĞER "Miyav" derse WrongAnimal sınıfında yanlışlıkla virtual kullandınız demektir.

    std::cout << "WrongAnimal makes: ";
    wrongMeta->makeSound();

    std::cout << "\n" << RED << "Destructors:" << RESET << std::endl;
    delete wrongCat;  // Eğer WrongAnimal destructor'ı virtual değilse, SADECE WrongAnimal silinir (Leak!)
    delete wrongMeta;

    return 0;
}
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    // =========================================================
    // TEST 1: PDF Gereksinimi (Array of Animals)
    // =========================================================
    std::cout << "----- TEST 1: Array of Animals -----" << std::endl;
    
    const int arraySize = 4; // Toplam hayvan sayısı (Örnek için 4, PDF'te sayı belirtilmemiş ama çift sayı iyi olur)
    const Animal* animals[arraySize]; // Animal işaretçileri dizisi

    // Dizinin yarısını Dog, yarısını Cat ile doldur
    for (int i = 0; i < arraySize / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; i++) {
        animals[i] = new Cat();
    }

    // Hayvanların seslerini test edelim
    std::cout << "\n--- Sounds ---" << std::endl;
    animals[0]->makeSound(); // Woof
    animals[3]->makeSound(); // Meow

    // Hepsini sil (Destructor zinciri ve Memory Leak kontrolü için)
    std::cout << "\n--- Deleting Animals ---" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }

    // =========================================================
    // TEST 2: Deep Copy Kanıtı
    // =========================================================
    std::cout << "\n\n----- TEST 2: Deep Copy Proof -----" << std::endl;

    Dog* dog1 = new Dog();
    
    // Dog1'in beynine bir fikir koyalım
    dog1->getBrain()->ideas[0] = "I want a bone!";
    
    // Dog2'yi Dog1'den kopyalayalım (Copy Constructor çalışır)
    Dog* dog2 = new Dog(*dog1);

    std::cout << "\nBefore Modification:" << std::endl;
    std::cout << "Dog1 Idea: " << dog1->getBrain()->ideas[0] << std::endl;
    std::cout << "Dog2 Idea: " << dog2->getBrain()->ideas[0] << std::endl;

    // Dog2'nin fikrini değiştirelim
    dog2->getBrain()->ideas[0] = "I want to sleep!";

    std::cout << "\nAfter Modification (Check Independence):" << std::endl;
    std::cout << "Dog1 Idea: " << dog1->getBrain()->ideas[0] << " (Should stay 'I want a bone!')" << std::endl;
    std::cout << "Dog2 Idea: " << dog2->getBrain()->ideas[0] << " (Should be 'I want to sleep!')" << std::endl;

    // Deep Copy Başarılı mı?
    if (dog1->getBrain()->ideas[0] != dog2->getBrain()->ideas[0])
        std::cout << "\nSUCCESS: Deep Copy works! Brains are independent." << std::endl;
    else
        std::cout << "\nFAILURE: Shallow Copy detected! Brains are shared." << std::endl;

    // Temizlik
    delete dog1;
    delete dog2;

    return 0;
}
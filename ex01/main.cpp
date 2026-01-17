#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

 
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"

int main()
{
    std::cout << CYAN << "=========================================" << RESET << std::endl;
    std::cout << CYAN << "    TEST 1: ARRAY OF ANIMALS (SUBJECT)   " << RESET << std::endl;
    std::cout << CYAN << "=========================================" << RESET << std::endl;

    const int count = 6;
    const Animal* animals[count];

    std::cout << YELLOW << ">> Creating Animals..." << RESET << std::endl;
    for (int i = 0; i < count / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = count / 2; i < count; i++) {
        animals[i] = new Cat();
    }


    std::cout << "\n[Sound Test]" << std::endl;
    animals[0]->makeSound();
    animals[count - 1]->makeSound();


    std::cout << YELLOW << "\n>> Deleting Animals (Destructor Chain)..." << RESET << std::endl;
    for (int i = 0; i < count; i++) {
        delete animals[i];
    }
    std::cout << GREEN << ">> Array cleaned. (Success if no memory leaks)" << RESET << std::endl;


    std::cout << CYAN << "\n\n=========================================" << RESET << std::endl;
    std::cout << CYAN << "    TEST 2: DEEP COPY PROOF              " << RESET << std::endl;
    std::cout << CYAN << "=========================================" << RESET << std::endl;


    std::cout << YELLOW << ">> Creating Dog 1..." << RESET << std::endl;
    Dog* dog1 = new Dog();
    
    if (dog1->getBrain())
        dog1->getBrain()->ideas[0] = "I want a bone!";

    std::cout << YELLOW << ">> Creating Dog 2 as a copy of Dog 1 (Copy Constructor)..." << RESET << std::endl;
    Dog* dog2 = new Dog(*dog1);

    std::cout << "\n[Check Before Modification]" << std::endl;
    std::cout << "Dog 1 Idea: " << dog1->getBrain()->ideas[0] << std::endl;
    std::cout << "Dog 2 Idea: " << dog2->getBrain()->ideas[0] << std::endl;

    std::cout << YELLOW << "\n>> Modifying Dog 2's idea..." << RESET << std::endl;
    if (dog2->getBrain())
        dog2->getBrain()->ideas[0] = "I want to sleep...";

    std::cout << "\n[Check After Modification (Independence Check)]" << std::endl;
    std::cout << "Dog 1 Idea: " << dog1->getBrain()->ideas[0] << " (Should stay 'I want a bone!')" << std::endl;
    std::cout << "Dog 2 Idea: " << dog2->getBrain()->ideas[0] << " (Should change to 'I want to sleep...')" << std::endl;

    if (dog1->getBrain()->ideas[0] != dog2->getBrain()->ideas[0]) {
        std::cout << GREEN << "\n>> SUCCESS: Ideas are different! (Deep Copy works)" << RESET << std::endl;
        std::cout << GREEN << ">> Dog 1 Brain Address: " << dog1->getBrain() << RESET << std::endl;
        std::cout << GREEN << ">> Dog 2 Brain Address: " << dog2->getBrain() << RESET << std::endl;
    } else {
        std::cout << RED << "\n>> FAILURE: Ideas are the same! (Shallow Copy detected)" << RESET << std::endl;
    }

    delete dog1;
    delete dog2;

    return 0;
}
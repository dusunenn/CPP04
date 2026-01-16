#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp" // Animal yerine AAnimal
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain *brain;

public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();

    // Bu fonksiyonu implemente etmek ZORUNDAYIZ.
    // Etmezsek Dog sınıfı da soyut olur ve new Dog() diyemeyiz.
    virtual void makeSound() const;

    Brain *getBrain() const;
};

#endif
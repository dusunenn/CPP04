#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat: default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    std::cout << "Cat: copy constructor called" << std::endl;
    this->brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        *(this->brain) = *(other.brain);
    }
    std::cout << "Cat: copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat: destructor called" << std::endl;
}

void Cat::makeSound() const {
    AAnimal::makeSound();
    std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->brain;
}
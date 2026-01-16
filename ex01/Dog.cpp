#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog: default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog: copy constructor called" << std::endl;
    this->brain = new Brain(*(other.brain));
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        *(this->brain) = *(other.brain);
    }
    std::cout << "Dog: copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog: destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->brain;
}
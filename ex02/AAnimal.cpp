#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    std::cout << "AAnimal copy constructor called" << std::endl;
    this->type = other.type;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}
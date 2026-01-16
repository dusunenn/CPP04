#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    // İŞTE SİHİRLİ KISIM BURASI:
    // "= 0" ekleyerek bu fonksiyonu "Pure Virtual" yapıyoruz.
    // Artık AAnimal sınıfından doğrudan nesne oluşturulamaz.
    virtual void makeSound() const = 0;

    std::string getType() const;
};

#endif
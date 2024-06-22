
#include "Animal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal deconstructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src) {
	std::cout << "AAnimal copy assignment operator" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

std::string AAnimal::getType() const {
	return (this->type); 
}
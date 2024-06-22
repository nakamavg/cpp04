#include "Dog.hpp"

Dog::Dog()
    : Animal() {
		this->type = "Dog";
	    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog() {
	std::cout << "Dog deconstructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
	std::cout << "Dog copy assignment operator" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void Dog::makeSound() const {
    std::cout << "Guau Guau" << std::endl;
}

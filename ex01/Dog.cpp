#include "Dog.hpp"

Dog::Dog()
    : Animal() {
		this->type = "Dog";
		this->brain = new Brain();
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
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, src.getIdea(i));
	return (*this);
}

void Dog::makeSound() const {
    std::cout << "Guau Guau" << std::endl;
}

std::string	Dog::getIdea(int i) const
{
	return this->brain->getIdea(i);
}

void	Dog::setIdea(int i, std::string idea)
{
	this->brain->setIdea(i, idea);
}

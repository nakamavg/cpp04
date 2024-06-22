#include "Cat.hpp"

Cat::Cat()
    : AAnimal() {
		this->type = "Cat";
		this->brain = new Brain();
	    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat() {
	std::cout << "Cat deconstructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
	std::cout << "Cat copy assignment operator" << std::endl;
	if (this != &src)
		this->type = src.type;
	this->brain = new Brain(*src.brain);
	for(int i = 0; i < 100; i++)
	{
		this->brain->setIdea(i, src.brain->getIdea(i));
	}

	return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meow meow" << std::endl;
}
std::string	Cat::getIdea(int i) const
{
	return this->brain->getIdea(i);
}

void	Cat::setIdea(int i, std::string idea)
{
	this->brain->setIdea(i, idea);
}
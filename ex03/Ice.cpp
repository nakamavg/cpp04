#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice") {
}

Ice::Ice(const AMateria &src) {
	*this = src;
}

Ice	&Ice::operator=(const AMateria &src) {
	if (this == &src)
		return (*this);
	this->type = src.getType();
	return (*this);
}

Ice::~Ice() {
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
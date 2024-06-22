#include "Cat.hpp"
#include "Dog.hpp"


int main() {

	const AAnimal  j ;
	const AAnimal 	i ;
	
	j->makeSound();
	i->makeSound();
	
	delete j;
	delete i;

	/* Cat cat;
	Dog dog;

	cat.makeSound();
	dog.makeSound(); */
	return 0;
}
#include "Cat.hpp"
#include "Dog.hpp"

#define ANIMALNUMBERS 4

int main() {

	Dog david;
	Cat patricia;
	Dog david2;

	patricia.makeSound();
	david.makeSound();
	patricia.setIdea(0, "hello cat world");
	patricia.setIdea(1, "hello cat world 2");
	david.setIdea(0, "hello dog world");
	
	std::cout << patricia.getIdea(0) << std::endl;
	std::cout << patricia.getIdea(1) << std::endl;
	std::cout << david.getIdea(0) << std::endl;
	david2 = david;
	std::cout << david2.getIdea(0) << std::endl;

	
	return 0;
}
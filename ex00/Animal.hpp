#pragma once
#include <iostream>
#include <string>

class Animal {

	protected:
	    std::string type;

	public:
	    Animal();
		Animal(const Animal &src);
	    virtual ~Animal();

		Animal &operator=(const Animal &src);

	    virtual void makeSound() const;
		std::string getType() const;
};
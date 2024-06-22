#pragma once
#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal  {

	protected:
	    std::string type;
		Brain *brain;
	public:
	    AAnimal();
		AAnimal(const AAnimal &src);
	    virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &src);

	    virtual void makeSound() const = 0;
		std::string getType() const;
};
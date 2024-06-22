#include "Animal.hpp"
#include "Brain.hpp"
#pragma once

class Cat : public AAnimal {
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &src);
		virtual ~Cat();

		Cat &operator=(const Cat &src);

		virtual void makeSound() const;
		std::string	getIdea(int i) const;
		void setIdea(int index, std::string idea) ;

};
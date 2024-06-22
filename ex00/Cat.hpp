#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &src);
		virtual ~Cat();

		Cat &operator=(const Cat &src);

		virtual void makeSound() const;
};
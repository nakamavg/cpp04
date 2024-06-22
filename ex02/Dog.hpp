#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal 
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &src);
		virtual ~Dog();

		Dog &operator=(const Dog &src);

		virtual void makeSound() const;
		std::string	getIdea(int i) const;
		void setIdea(int index, std::string idea) ;
};
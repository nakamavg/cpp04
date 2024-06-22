#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria {

	public:
		Cure();
		~Cure();
		Cure(const AMateria &src);
		Cure &operator=(const AMateria &src);

		AMateria* clone() const ;
		void use(ICharacter &target) ;
};
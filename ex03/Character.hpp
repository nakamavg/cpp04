#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp" 

class Character : public ICharacter {
private:
    AMateria* inventory[4]; 
    std::string _name;

public:
    Character();
    Character(std::string const & name);
    ~Character();
    Character(const Character & src);
    Character &operator=(const Character & rhs);

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif

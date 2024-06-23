#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];

public:
    Character(std::string const & name);
    Character(Character const & other);
    Character& operator=(Character const & other);
    virtual ~Character();
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

private:
    void clearInventory();
    void copyInventory(Character const & other);
};

#endif // CHARACTER_HPP

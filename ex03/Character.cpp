#include "Character.hpp"

Character::Character() : _name("Unnamed") {
    for (int i = 0; i < 4; ++i) {
        inventory[i] = nullptr;
    }
}

Character::Character(std::string const & name) : _name(name) {
    for (int i = 0; i < 4; ++i) {
        inventory[i] = nullptr;
    }
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
}

Character::Character(const Character & src) {
    _name = src._name;
    for (int i = 0; i < 4; ++i) {
        if (src.inventory[i] != nullptr) {
            inventory[i] = src.inventory[i]->clone();
        } else {
            inventory[i] = nullptr;
        }
    }
}

Character & Character::operator=(const Character & rhs) {
    if (this == &rhs) {
		return (*this);
	}
	_name = rhs._name;
	for (int i = 0; i < 4; ++i) {
		delete inventory[i];
		if (rhs.inventory[i] != nullptr) {
			inventory[i] = rhs.inventory[i]->clone();
		} else {
			inventory[i] = nullptr;
		}
	}
	return (*this);
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (inventory[i] == nullptr) {
            inventory[i] = m;
            return; 
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || inventory[idx] == nullptr) {
        return; 
    }
  
    inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || inventory[idx] == nullptr) {
        return;
    }
    inventory[idx]->use(target);
}

// Character.cpp
#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; ++i) {
        inventory[i] = nullptr;
    }
}

Character::Character(Character const & other) : name(other.name) {
    copyInventory(other);
}

Character& Character::operator=(Character const & other) {
    if (this != &other) {
        name = other.name;
        clearInventory();
        copyInventory(other);
    }
    return *this;
}

Character::~Character() {
    clearInventory();
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (m == nullptr) return;
    for (int i = 0; i < 4; ++i) {
        if (inventory[i] == nullptr) {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        inventory[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx] != nullptr) {
        inventory[idx]->use(target);
    }
	else if (idx >= 0 && idx < 4 && inventory[idx] == nullptr)
		std::cout << "No materia in slot " << idx << std::endl;
	else
		std::cout << "Invalid slot " << idx << std::endl;
}

void Character::clearInventory() {
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
        inventory[i] = nullptr;
    }
}

void Character::copyInventory(Character const & other) {
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i] != nullptr) {
            inventory[i] = other.inventory[i]->clone();
        } else {
            inventory[i] = nullptr;
        }
    }
}

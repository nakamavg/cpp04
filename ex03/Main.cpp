#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

/* int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Additional test 1: Inventory full
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice"); // This should not be added
    me->equip(tmp);

    std::cout << "Using all 4 materias:\n";
    for (int i = 0; i < 4; ++i) {
        me->use(i, *me);  // should use all 4 equipped materias
    }

    std::cout << "Trying to use a non-existent materia (index 4):\n";
    me->use(4, *me);  // should do nothing

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    // Additional test 2: Unused slots
    std::cout << "Unequipping slot 2:\n";
    me->unequip(2);
    me->use(2, *bob);  // should do nothing

    // Additional test 3: Reuse of slots
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(2, *bob);  // should use the new ice materia

    // Additional test 4: Creating unknown materia
    std::cout << "Trying to create an unknown materia:\n";
    tmp = src->createMateria("fire");
    if (tmp == nullptr) {
        std::cout << "Materia type 'fire' is unknown and cannot be created.\n";
    }

    // Additional test 5: Cloning and destruction
    std::cout << "Cloning a materia and using it:\n";
    AMateria* clone = tmp->clone();
    clone->use(*bob);
    delete clone;

    delete bob;
    delete me;
    delete src;

    return 0;
} */


#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Additional test 1: Inventory full
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice"); // This should not be added
    me->equip(tmp);

    std::cout << "Using all 4 materias:\n";
    for (int i = 0; i < 4; ++i) {
        me->use(i, *me);  // should use all 4 equipped materias
    }

    std::cout << "Trying to use a non-existent materia (index 4):\n";
    me->use(4, *me);  // should do nothing

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    // Additional test 2: Unused slots
    std::cout << "Unequipping slot 2:\n";
    me->unequip(2);
    me->use(2, *bob);  // should do nothing

    // Additional test 3: Reuse of slots
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(2, *bob);  // should use the new ice materia

    // Additional test 4: Creating unknown materia
    std::cout << "Trying to create an unknown materia:\n";
    tmp = src->createMateria("fire");
    if (tmp == nullptr) {
        std::cout << "Materia type 'fire' is unknown and cannot be created.\n";
    }

    // Additional test 5: Cloning and using known materias
    std::cout << "Cloning and using a known materia (ice):\n";
    tmp = src->createMateria("ice");
    if (tmp != nullptr) {
        AMateria* clone = tmp->clone();
        if (clone != nullptr) {
            clone->use(*bob);
            delete clone;
        } else {
            std::cout << "Clone failed, clone is nullptr.\n";
        }
    } else {
        std::cout << "Clone failed, tmp is nullptr.\n";
    }

    std::cout << "Cloning and using a known materia (cure):\n";
    tmp = src->createMateria("cure");
    if (tmp != nullptr) {
        AMateria* clone = tmp->clone();
        if (clone != nullptr) {
            clone->use(*bob);
            delete clone;
        } else {
            std::cout << "Clone failed, clone is nullptr.\n";
        }
    } else {
        std::cout << "Clone failed, tmp is nullptr.\n";
    }

    // Additional test 6: Copy character and ensure deep copy
    std::cout << "Copying character and ensuring deep copy:\n";
    Character* copyMe = new Character(*dynamic_cast<Character*>(me));
    copyMe->use(0, *bob); // Should use the first materia
    copyMe->use(5, *bob); // Should do nothing
	copyMe->equip(src->createMateria("cure"));
	copyMe->use(1, *bob); // Should use the new materia

    delete bob;
    delete me;
    delete copyMe;
    delete src;

    return 0;
}


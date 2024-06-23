// MateriaSource.cpp
#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        templates[i] = nullptr;
    }
}

MateriaSource::MateriaSource(MateriaSource const & other) {
    copyTemplates(other);
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other) {
    if (this != &other) {
        clearTemplates();
        copyTemplates(other);
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    clearTemplates();
}

void MateriaSource::learnMateria(AMateria* m) {
    if (m == nullptr) return;
    for (int i = 0; i < 4; ++i) {
        if (templates[i] == nullptr) {
            templates[i] = m->clone();
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (templates[i] != nullptr && templates[i]->getType() == type) {
            return templates[i]->clone();
        }
    }
    return nullptr;
}

void MateriaSource::clearTemplates() {
    for (int i = 0; i < 4; ++i) {
        delete templates[i];
        templates[i] = nullptr;
    }
}

void MateriaSource::copyTemplates(MateriaSource const & other) {
    for (int i = 0; i < 4; ++i) {
        if (other.templates[i] != nullptr) {
            templates[i] = other.templates[i]->clone();
        } else {
            templates[i] = nullptr;
        }
    }
}

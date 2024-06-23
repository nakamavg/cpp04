#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* templates[4];

public:
    MateriaSource();
    MateriaSource(MateriaSource const & other);
    MateriaSource& operator=(MateriaSource const & other);
    virtual ~MateriaSource();
    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);

private:
    void clearTemplates();
    void copyTemplates(MateriaSource const & other);
};

#endif

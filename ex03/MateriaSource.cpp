#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource ctor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
		this->learned[i] = other.learned[i];
	std::cout << "MateriaSource copy-ctor called" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
			this->learned[4] = other.learned[i];
		std::cout << "MateriaSource assignment operator called" << std::endl;
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource dtor called" << std::endl;
}

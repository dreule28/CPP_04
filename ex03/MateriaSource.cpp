#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		learned[i] = NULL;
	std::cout << "MateriaSource ctor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
		if (learned[i])
			this->learned[i] = other.learned[i]->clone();
		else
			this->learned[i] = NULL;
	std::cout << "MateriaSource copy-ctor called" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (learned[i])
			{
				delete learned[i];
				learned[i] = NULL;
			}
		}
		for (int i = 0; i < 4; ++i)
			if (learned[i])
				this->learned[i] = other.learned[i]->clone();
		std::cout << "MateriaSource assignment operator called" << std::endl;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		if (learned[i])
			delete learned[i];
	std::cout << "MateriaSource dtor called" << std::endl;
}

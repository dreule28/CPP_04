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

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		std::cout << "Materia is NULL" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; ++i)
		if (!learned[i])
		{
			learned[i] = materia->clone();
			std::cout << "Learned materia " << materia->getType() << " in position" << i << std::endl;
			return ;
		}
	std::cout << "Full. Cannot learn any new materias" << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i< 4; ++i)
		if (learned[i] && learned[i]->getType() == type)
		{
			std::cout << "Creating materia type " << type << std::endl;
			return (learned[i]->clone());
		}
	std::cout << "Can't learn type " << type << std::endl;
	return (NULL);
}

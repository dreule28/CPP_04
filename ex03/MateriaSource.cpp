#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
		if (other.learned[i])
			this->learned[i] = other.learned[i]->clone();
		else
			this->learned[i] = NULL;
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
			if (other.learned[i])
				this->learned[i] = other.learned[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		if (learned[i])
		{
			delete learned[i];
			learned[i] = NULL;
		}
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
			delete materia;
			return ;
		}
	delete materia;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; ++i)
		if (learned[i] && learned[i]->getType() == type)
			return (learned[i]->clone());
	return (NULL);
}

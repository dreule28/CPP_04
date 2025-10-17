#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource& other);
		virtual ~MateriaSource();

		void	learnMateria(AMateria*);
		AMateria*	createMateria(const std::string& type);

	private:
		AMateria*	learned[4];
};
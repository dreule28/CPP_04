#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		virtual ~Cure();

		void use(Character& target);
		AMateria* clone();
};
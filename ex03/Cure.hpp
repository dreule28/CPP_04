#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		virtual ~Cure();

		void use(ICharacter& target);
		AMateria* clone() const;
};
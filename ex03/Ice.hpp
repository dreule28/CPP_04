#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		virtual ~Ice();

		virtual void use(ICharacter& target);
		virtual AMateria* clone() const;
};
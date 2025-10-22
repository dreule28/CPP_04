#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		virtual ~Ice();
		Ice&	operator=(const Ice& other);

		virtual void use(ICharacter& target);
		virtual AMateria* clone() const;
};
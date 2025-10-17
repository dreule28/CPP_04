#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		virtual ~Ice();
		
		virtual void use(Character& target);
		virtual AMateria* clone() const;
};
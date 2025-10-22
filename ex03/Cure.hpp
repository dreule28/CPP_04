#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		virtual ~Cure();

		void use(ICharacter& target);
		AMateria* clone() const;
};
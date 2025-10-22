#pragma once

#include <iostream>
#include "Character.hpp"

class AMateria
{
	public:
		AMateria(const AMateria& other);
		AMateria(const std::string& type);
		AMateria&	operator=(const AMateria& other);
		virtual ~AMateria();

		const std::string& getType() const;
		virtual void use(ICharacter& target);
		virtual AMateria* clone() const = 0;

	protected:
		const std::string	_type;
};
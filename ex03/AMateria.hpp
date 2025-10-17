#pragma once

#include <iostream>

class Character;

class AMateria
{
	public:
		AMateria(const AMateria& other);
		AMateria(const std::string& type);
		AMateria&	operator=(const AMateria& other);
		~AMateria();

		const std::string& getType() const;
		virtual void use(Character& target);
		virtual AMateria* clone() const = 0;

	protected:
		const std::string	type;
};
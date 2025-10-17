#pragma once

#include <iostream>

class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(const AMateria& other);
		AMateria(const std::string& type);
		AMateria&	operator=(const AMateria& other);
		~AMateria();
		const std::string& getType() const;
		virtual void use(ICharacter& target);

		virtual AMateria* clone() const = 0;

	protected:
		const std::string	type;
};
#include "AMateria.hpp"

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria&	AMateria::operator=(const AMateria& other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria() {}

void	AMateria::use(ICharacter& target) {(void)target;}

const std::string&	AMateria::getType() const {return (_type);}

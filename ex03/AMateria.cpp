#include "AMateria.hpp"

AMateria::AMateria(const AMateria& other) {}

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria&	AMateria::operator=(const AMateria& other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria() {}

const std::string&	AMateria::getType() const {
	return (type);
}

#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AAMAteria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	std::cout << "AMateria copy-constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) : type(type) {
	std::cout << "AMateria name-constructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this!= &other)
		std::cout << "AMateria assignment overload called" << std::endl;
	return (*this);
}

AMateria::~AMateria() {
	std::cout << "AAmateria detructor called" << std::endl;
}

const std::string&	AMateria::getType() const {
	return (type);
}

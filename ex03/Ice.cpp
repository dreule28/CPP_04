#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Ice materia created" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice materia destroyed" << std::endl;
}

Ice&	Ice::operator=(const Ice& other)
{
	(void)other;
	return (*this);
}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "Ice materia copied" << std::endl;
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone() const {
	return (new Ice(*this));
}

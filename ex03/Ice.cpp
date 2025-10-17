#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Ice materia created" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice materia destroyed" << std::endl;
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone() const {
	return (new Ice(*this));
}

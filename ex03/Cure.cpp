#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure materia created" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure materia destroyed" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << "Cure materia copied" << std::endl;
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone() const {
	return (new Cure(*this));
}

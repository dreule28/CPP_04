#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& other) : AMateria(other) {}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria*	Cure::clone() const {
	return (new Cure(*this));
}

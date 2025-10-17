#include "IMateriaSource.hpp"
#include "Character.hpp"

int main()
{
	AMateriaSource* src = new AMateriaSource();
	src->learnAMateriaa(new Ice());
	src->learnAMateriaa(new Cure());
	Character* me = new Character("me");
	AMateria* tmp;
	tmp = src->createAMateriaa("ice");
	me->equip(tmp);
	tmp = src->createAMateriaa("cure");
	me->equip(tmp);
	Character* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

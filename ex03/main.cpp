#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Floor.hpp"
#include "Cure.hpp"

static void title(const char* t) {
	std::cout << "\n==== " << t << " ====\n";
}

int main()
{
	title("Test 1: Subject main");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		Character* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		Character* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		Floor::clean();
	}

	title("Test 2: Equip overflow (more than 4)");
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		Character alice("alice");
		for (int i = 0; i < 6; ++i) {
			AMateria* m = src.createMateria((i % 2) ? "ice" : "cure");
			alice.equip(m);
		}
		alice.use(0, alice);
		alice.use(1, alice);
		alice.use(4, alice);
		alice.use(-1, alice);
		Floor::clean();
	}


	title("Test 3: Unknown materia type and nullptr equip");
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		Character target("target");
		AMateria* unknown = src.createMateria("fire");
		if (!unknown)
			std::cout << "createMateria(\"fire\") returned nullptr as expected\n";
		target.equip(unknown);
		Floor::clean();
	}


	title("Test 4: Unequip, invalid indices, Floor cleanup");
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		Character hero("hero");
		hero.equip(src.createMateria("ice"));
		hero.equip(src.createMateria("cure"));

		hero.use(0, hero);
		hero.use(1, hero);

		hero.unequip(1);
		hero.unequip(1);
		hero.unequip(-1);
		hero.unequip(99);

		hero.use(1, hero);


		Floor::drop(new Ice());
		Floor::drop(new Cure());


		Floor::clean();
	}


	title("Test 5: Character deep copy and independence");
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		Character* copyPtr = NULL;
		{
			Character original("original");
			original.equip(src.createMateria("ice"));
			original.equip(src.createMateria("cure"));


			copyPtr = new Character(original);

			original.use(0, original);
			original.use(1, original);

		}

		copyPtr->use(0, *copyPtr);
		copyPtr->use(1, *copyPtr);
		delete copyPtr;

		Floor::clean();
	}


	title("Test 6: Character assignment operator");
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());

		Character left("left");
		left.equip(src.createMateria("ice"));

		Character right("right");
		right.equip(src.createMateria("cure"));
		right.equip(src.createMateria("ice"));

		left = right;
		left.use(0, left);
		left.use(1, left);


		right.unequip(0);
		right.use(0, right);
		left.use(0, left);

		Floor::clean();
	}


	title("Test 7: MateriaSource capacity and copy");
	{
		MateriaSource s1;
		s1.learnMateria(new Ice());
		s1.learnMateria(new Cure());
		s1.learnMateria(new Ice());
		s1.learnMateria(new Cure());
		s1.learnMateria(new Ice());

		AMateria* shouldBeNull = s1.createMateria("thunder");
		if (!shouldBeNull)
			std::cout << "createMateria(\"thunder\") returned nullptr as expected\n";


		MateriaSource s2(s1);
		AMateria* m1 = s2.createMateria("ice");
		AMateria* m2 = s2.createMateria("cure");


		Floor::drop(m1);
		Floor::drop(m2);
		Floor::clean();
	}

	title("All tests done");
	return 0;
}

#pragma once

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		virtual ~Character();

		const std::string& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		const std::string name;
		AMateria* inventory[4];
};
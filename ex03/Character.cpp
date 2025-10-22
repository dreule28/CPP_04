#include "Character.hpp"

Character::Character() {
	std::cout << "Character created" << std::endl;
}

Character::Character(const std::string& name) : name(name)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
	std::cout << "Character " << name << " created" << std::endl;
}

Character::Character(const Character& other) : name(other.name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	std::cout << "Character " << name << " copied" << std::endl;
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (inventory[i])
			{
				delete (inventory[i]);
				inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; ++i)
		{
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
		}
	}
	std::cout << "Character assignment operator called" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (inventory[i])
			delete (inventory[i]);
	}
	std::cout << "Character " << name << " destroyed" << std::endl;
}

const std::string&	Character::getName() const {
	return (name);
}

void	Character::equip(AMateria* m)
{
	if (!m) {
		std::cout << "No materia to equip!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			std::cout << name << " equipped " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << name << "'s inventory is full!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Idx out of scope" << std::endl;
		return ;
	}
	if (!inventory[idx])
	{
		std::cout << "Slot " << idx << " is already empty!" << std::endl;
		return ;
	}
	std:: cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
	inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Idx out of scope" << std::endl;
		return ;
	}
	if (!inventory[idx])
	{
		std::cout << "Slot is empty!" << std::endl;
		return ;
	}
	inventory[idx]->use(target);
}

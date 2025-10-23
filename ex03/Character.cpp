#include "Character.hpp"

Character::Character() {}

Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
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
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (inventory[i])
			delete (inventory[i]);
	}
}

const std::string&	Character::getName() const {
	return (_name);
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
			return ;
		}
	}
	std::cout << _name << "'s inventory is full!" << std::endl;
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
	std:: cout << _name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
	Floor::drop(inventory[idx]);
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

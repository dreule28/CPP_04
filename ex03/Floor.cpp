#include "Floor.hpp"

int	Floor::_count = 0;
AMateria*	Floor::_store[100] = {0};

Floor::Floor() {}

Floor::Floor(const Floor& other)
{
	(void)other;
}

Floor&	Floor::operator=(const Floor& other)
{
	(void)other;
	return *this;
}

Floor::~Floor() {};

void	Floor::drop(AMateria* materia)
{
	if (!materia)
		return ;
	if (_count < 100)
		_store[_count++] = materia;
	else
		delete materia;
	return ;
}

void	Floor::clean()
{
	for (int i = 0; i < _count; ++i)
		delete _store[i];
	_count = 0;
}

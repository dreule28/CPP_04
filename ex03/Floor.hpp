#pragma once

#include "Character.hpp"

class Floor
{
	public:
		Floor();
		Floor(const Floor& other);
		Floor&	operator=(const Floor& other);
		~Floor();
		static void	drop(AMateria* materia);
		static void	clean();

	private:
		static AMateria*	_store[100];
		static int	_count;
};
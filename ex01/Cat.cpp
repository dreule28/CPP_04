/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:37:18 by dreule            #+#    #+#             */
/*   Updated: 2025/10/16 12:33:57 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain) {
	new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "Cat assignment operator called" << std::endl;
	}
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const{
	std::cout << "Cat go meow meow" << std::endl;
}

Brain*	Cat::getBrain() const {
	return (_brain);
}

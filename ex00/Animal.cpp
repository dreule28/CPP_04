/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:33:57 by dreule            #+#    #+#             */
/*   Updated: 2025/10/16 12:32:30 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
Animal::Animal(): type("Animal"){
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string& name) : type(name){
	std::cout << "Animal name-constructor called."
			<< " Animal named: " << name << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type){
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << "Animal assignment overload called" << std::endl;
	}
	return (*this);
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const{
	std::cout << "Generic ahh sounds..." << std::endl;
}

const std::string	Animal::getType() const{
	return (type);
}

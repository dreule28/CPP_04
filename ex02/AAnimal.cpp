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

#include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal"){
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& name) : type(name){
	std::cout << "AAnimal name-constructor called."
			<< " AAnimal named: " << name << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type){
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << "AAnimal assignment overload called" << std::endl;
	}
	return (*this);
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called" << std::endl;
}

void	AAnimal::makeSound() const{
	std::cout << "Generic ahh sounds..." << std::endl;
}

const std::string	AAnimal::getType() const{
	return (type);
}

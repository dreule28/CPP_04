/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:33:21 by dreule            #+#    #+#             */
/*   Updated: 2025/10/15 18:21:39 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const std::string& name);
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);
		virtual ~Animal();
		virtual void	makeSound();


	protected:
		std::string	type;
};

#endif
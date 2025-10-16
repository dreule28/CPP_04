/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:24:40 by dreule            #+#    #+#             */
/*   Updated: 2025/10/16 12:29:12 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		const Animal* meta = new Animal();
		const Animal* d = new Dog();
		const Animal* c = new Cat();

		std::cout << d->getType() << " " << std::endl;
		std::cout << c->getType() << " " << std::endl;
		c->makeSound();
		d->makeSound();
		meta->makeSound();

		delete (meta);
		delete (d);
		delete (c);
	}

	std::cout << "\nFirst scope finished\n" << std::endl;

	{
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* d = new Dog();
		const WrongAnimal* c = new WrongCat();

		std::cout << d->getType() << " " << std::endl;
		std::cout << c->getType() << " " << std::endl;
		c->makeSound();
		d->makeSound();
		meta->makeSound();

		delete (meta);
		delete (d);
		delete (c);
	}

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:24:40 by dreule            #+#    #+#             */
/*   Updated: 2025/10/16 16:20:00 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"

static void line(const std::string& title) {
	std::cout << YELLOW << "\n=== " << title << " ===" << RESET << std::endl;
}

int main()
{
	line("Basic leak test");
	{
		const Animal*	d = new Dog();
		const Animal*	c = new Cat();
		delete d;
		delete c;
	}

	line("Array of Animals (half Dogs, half Cats)");
	{
		const size_t	N = 10;
		Animal*	zoo[N];

		for (size_t i = 0; i < N; ++i)
		{
			if (i < N / 2)
				zoo[i] = new Dog();
			else
				zoo[i] = new Cat();
		}

		for (size_t i = 0; i < N; ++i)
			zoo[i]->makeSound();

		for (size_t i = 0; i < N; ++i)
			delete zoo[i];
	}

	line("Deep copy test: Dog");
	{
		Dog	a;
		a.getBrain()->setIdea(0, "Chase cats");
		a.getBrain()->setIdea(1, "Eat food");

		Dog	b(a);
		Dog	c;
		c = a;

		a.getBrain()->setIdea(0, "Dig holes");

		std::cout << GREEN << "a.idea[0]: " << a.getBrain()->getIdea(0) << RESET << std::endl;
		std::cout << GREEN << "b.idea[0]: " << b.getBrain()->getIdea(0) << RESET << std::endl;
		std::cout << GREEN << "c.idea[0]: " << c.getBrain()->getIdea(0) << RESET << std::endl;
	}

	line("Deep copy test: Cat");
	{
		Cat x;
		x.getBrain()->setIdea(42, "Nap on keyboard");

		Cat y(x);
		Cat z;
		z = x;

		x.getBrain()->setIdea(42, "Knock over glass");

		std::cout << GREEN << "x.idea[42]: " << x.getBrain()->getIdea(42) << RESET << std::endl;
		std::cout << GREEN << "y.idea[42]: " << y.getBrain()->getIdea(42) << RESET << std::endl;
		std::cout << GREEN << "z.idea[42]: " << z.getBrain()->getIdea(42) << RESET << std::endl;
	}

	line("Done");
	return 0;
}
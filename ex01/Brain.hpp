#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		~Brain();
		const std::string& getIdea(int index) const;
		void	setIdea(std::string& idead, int index);

	private:
		std::string ideas[100];
};

#endif
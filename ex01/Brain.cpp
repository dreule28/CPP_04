#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
	std::cout << "Brain copy-constructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
		std::cout << "Brain assignment operator called" << std::endl;
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

const std::string&	Brain::getIdea(int index) const
{
	static const std::string empty;
	if (index < 0 || index > 100)
		return (empty);
	return (ideas[index]);
}

void	Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index > 100)
		return ;
	ideas[index] = idea;
}

#include "ft_vector.hpp"

void	test_vector_1_capacity()
{
	ft::vector<int>	intVector1;

	if (intVector1.empty())
		std::cout << "intVector1.empty()    = true" << std::endl;
	else
		std::cout << "intVector1.empty()    = false" << std::endl;
	std::cout << "intVector1.size()     = " << intVector1.size() << std::endl;
	std::cout << "intVector1.max_size() = " << intVector1.max_size() << std::endl;
	std::cout << "intVector1.capacity() = " << intVector1.capacity() << std::endl;

	intVector1.push_back(1);
	intVector1.push_back(2);
	intVector1.push_back(3);
	intVector1.push_back(4);

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "intVector1: ";
	for (ft::vector<int>::iterator it = intVector1.begin(); it != intVector1.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	if (intVector1.empty())
		std::cout << "intVector1.empty()    = true" << std::endl;
	else
		std::cout << "intVector1.empty()    = false" << std::endl;
	std::cout << "intVector1.size()     = " << intVector1.size() << std::endl;
	std::cout << "intVector1.max_size() = " << intVector1.max_size() << std::endl;
	std::cout << "intVector1.capacity() = " << intVector1.capacity() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	intVector1.reserve(2);

	std::cout << BLUE << "$>> intVector1.reserve(2)" << NORMAL << std::endl;

	std::cout << "intVector1.size()     = " << intVector1.size() << std::endl;
	std::cout << "intVector1.capacity() = " << intVector1.capacity() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	intVector1.reserve(8);

	std::cout << BLUE << "$>> intVector1.reserve(8)" << NORMAL << std::endl;

	std::cout << "intVector1.size()     = " << intVector1.size() << std::endl;
	std::cout << "intVector1.capacity() = " << intVector1.capacity() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << BLUE << "$>> intVector1.reserve(intVector1.max_size() + 10) ==>" << NORMAL << std::endl;

	try
	{
		intVector1.reserve(intVector1.max_size() + 10);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << NORMAL;
	}
	std::cout << std::endl;

	std::cout << "intVector1.size()     = " << intVector1.size() << std::endl;
	std::cout << "intVector1.capacity() = " << intVector1.capacity() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;
}

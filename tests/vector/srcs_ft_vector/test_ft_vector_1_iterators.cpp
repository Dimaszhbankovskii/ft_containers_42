#include "ft_vector.hpp"

void	test_vector_1_iterators()
{
	ft::vector<int>	intVector1;

	intVector1.push_back(1);
	intVector1.push_back(2);
	intVector1.push_back(3);
	intVector1.push_back(4);

	std::cout << "intVector1( begit(), end() ): ";
	for (ft::vector<int>::iterator it = intVector1.begin(); it != intVector1.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "intVector1( rbegit(), rend() ): ";
	for (ft::vector<int>::reverse_iterator rIt = intVector1.rbegin(); rIt != intVector1.rend(); ++rIt)
		std::cout << *rIt << " ";
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<int>::iterator				it1 = intVector1.begin();
	ft::vector<int>::const_iterator			it2 = intVector1.begin();

	ft::vector<int>::iterator				it3 = intVector1.end() - 1;
	ft::vector<int>::const_iterator			it4 = intVector1.end() - 1;

	ft::vector<int>::reverse_iterator		rIt1 = intVector1.rbegin();
	// ft::vector<int>::const_reverse_iterator	rIt2 = intVector1.rbegin();
	
	ft::vector<int>::reverse_iterator		rIt3 = intVector1.rend() - 1;
	// ft::vector<int>::const_reverse_iterator	rIt4 = intVector1.rend() - 1;

	std::cout << "iterator                intVector1.begin()  = " << *it1 << std::endl;
	std::cout << "const_iterator          intVector1.begin()  = " << *it2 << std::endl;

	std::cout << "iterator                intVector1.end()    = " << *it3 << std::endl;
	std::cout << "const_iterator          intVector1.end()    = " << *it4 << std::endl;

	std::cout << "reverse_iterator        intVector1.rbegin() = " << *rIt1 << std::endl;
	// std::cout << "const_reverse_iterator  intVector1.rbegin() = " << *rIt2 << std::endl;

	std::cout << "reverse_iterator        intVector1.rend()   = " << *rIt3 << std::endl;
	// std::cout << "const_reverse_iterator  intVector1.rend()   = " << *rIt4 << std::endl;

	*it1 = 10;
	std::cout << BLUE << "$>> *( it1 = intVector1.begin() ) = 10" << NORMAL << std::endl;

	std::cout << "iterator                intVector1.begin()  = " << *it1 << std::endl;
	// std::cout << "const_iterator          intVector1.begin()  = " << *it2 << std::endl;

	std::cout << "iterator                intVector1.end()    = " << *it3 << std::endl;
	// std::cout << "const_iterator          intVector1.end()    = " << *it4 << std::endl;

	std::cout << "reverse_iterator        intVector1.rbegin() = " << *rIt1 << std::endl;
	// std::cout << "const_reverse_iterator  intVector1.rbegin() = " << *rIt2 << std::endl;

	std::cout << "reverse_iterator        intVector1.rend()   = " << *rIt3 << std::endl;
	// std::cout << "const_reverse_iterator  intVector1.rend()   = " << *rIt4 << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;
}

#include "ft_vector.hpp"

void	test_reverse_iterator_1()
{
	ft::vector<int>			        	intVector;
	ft::vector<int>::reverse_iterator	it1, it2;

	intVector.push_back(1);
	intVector.push_back(2);
	intVector.push_back(3);
	intVector.push_back(4);
	intVector.push_back(5);
	intVector.push_back(6);

	std::cout << "------------------------------------------------------------" << std::endl;

	it1 = intVector.rbegin();
	it2 = intVector.rend() - 1;
	
	std::cout << "intVector: ";
	for (ft::vector<int>::reverse_iterator it = intVector.rbegin(); it != intVector.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "*( it1 = intVector.rbegin() ) = " << *it1 << std::endl;
	std::cout << "*( it2 = intVector.rend() - 1 ) = " << *it2 << std::endl;

	ft::vector<int>::reverse_iterator	it3(it1);
	ft::vector<int>::reverse_iterator	it4 = it1;

	std::cout << "*( it3( it1 ) ) = " << *it3 << std::endl;
	std::cout << "*( it4 = it1 ) = " << *it4 << std::endl;
	std::cout << "it1[1] = " << it1[1] << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "it1 = " << *it1 << " --> ++it1 = " << *(++it1);
	std::cout << " --> it1 = " << *it1 << std::endl;

	std::cout << "it1 = " << *it1 << " --> --it1 = " << *(--it1);
	std::cout << " --> it1 = " << *it1 << std::endl;

	std::cout << "it1 = " << *it1 << " --> it1++ = " << *(it1++);
	std::cout << " --> it1 = " << *it1 << std::endl;

	std::cout << "it1 = " << *it1 << " --> it1-- = " << *(it1--);
	std::cout << " --> it1 = " << *it1 << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<int>::reverse_iterator	it5 = it1 + 3;
	ft::vector<int>::reverse_iterator	it6 = it5 - 2;

	std::cout << "it5 = it1 + 3 = " << *it5 << std::endl;
	std::cout << "it6 = it5 - 2 = " << *it6 << std::endl;

	it4 += 3;
	std::cout << "it4 += 3 = " << *it4 << std::endl;
	it4 -= 3;
	std::cout << "it4 -= 3 = " << *it4 << std::endl;

	std::cout << "it5 - it6 = " << it5 - it6 << std::endl;
	std::cout << "it6 - it5 = " << it6 - it5 << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "it1 = " << *it1 << std::endl;
	std::cout << "it4 = " << *it4 << std::endl;

	if (it1 == it4)
		std::cout << "it1 == it4 = True" << std::endl;
	else
		std::cout << "it1 == it4 = False" << std::endl;

	if (it1 != it4)
		std::cout << "it1 != it4 = True" << std::endl;
	else
		std::cout << "it1 != it4 = False" << std::endl;
	
	if (it1 > it4)
		std::cout << "it1 > it4 = True" << std::endl;
	else
		std::cout << "it1 > it4 = False" << std::endl;

	if (it1 >= it4)
		std::cout << "it1 >= it4 = True" << std::endl;
	else
		std::cout << "it1 >= it4 = False" << std::endl;

	if (it1 < it4)
		std::cout << "it1 < it4 = True" << std::endl;
	else
		std::cout << "it1 < it4 = False" << std::endl;

	if (it1 <= it4)
		std::cout << "it1 <= it4 = True" << std::endl;
	else
		std::cout << "it1 <= it4 = False" << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "it1 = " << *it1 << std::endl;
	std::cout << "it5 = " << *it5 << std::endl;

	if (it1 == it5)
		std::cout << "it1 == it5 = True" << std::endl;
	else
		std::cout << "it1 == it5 = False" << std::endl;

	if (it1 != it5)
		std::cout << "it1 != it5 = True" << std::endl;
	else
		std::cout << "it1 != it5 = False" << std::endl;
	
	if (it1 > it5)
		std::cout << "it1 > it5 = True" << std::endl;
	else
		std::cout << "it1 > it5 = False" << std::endl;

	if (it1 >= it5)
		std::cout << "it1 >= it5 = True" << std::endl;
	else
		std::cout << "it1 >= it5 = False" << std::endl;

	if (it1 < it5)
		std::cout << "it1 < it5 = True" << std::endl;
	else
		std::cout << "it1 < it5 = False" << std::endl;

	if (it1 <= it5)
		std::cout << "it1 <= it5 = True" << std::endl;
	else
		std::cout << "it1 <= it5 = False" << std::endl;
	
	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<int>::reverse_iterator	it7 = 2 + it1;

	std::cout << "it7 = 2 + it1 = " << *it7 << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;
}

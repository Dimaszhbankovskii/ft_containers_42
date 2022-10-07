#include "ft_vector.hpp"

void	test_vector_1_modifiers()
{
	ft::vector<int>	intVector1;

	intVector1.push_back(1);
	intVector1.push_back(2);
	intVector1.push_back(3);
	intVector1.push_back(4);

	std::cout << "intVector1: ";
	for (ft::vector<int>::iterator it = intVector1.begin(); it != intVector1.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	if (intVector1.empty())
		std::cout << "intVector1.empty()    = true" << std::endl;
	else
		std::cout << "intVector1.empty()    = false" << std::endl;
	std::cout << "intVector1.size()     = " << intVector1.size() << std::endl;
	std::cout << "intVector1.capacity() = " << intVector1.capacity() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

/*************************************************************************************************/
/**************************               VECTOR.CLEAR()                **************************/
/*************************************************************************************************/

	intVector1.clear();

	std::cout << BLUE << "$>> intVector1.clear()" << NORMAL << std::endl;

	std::cout << "intVector1: ";
	for (ft::vector<int>::iterator it = intVector1.begin(); it != intVector1.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	if (intVector1.empty())
		std::cout << "intVector1.empty()    = true" << std::endl;
	else
		std::cout << "intVector1.empty()    = false" << std::endl;
	std::cout << "intVector1.size()     = " << intVector1.size() << std::endl;
	std::cout << "intVector1.capacity() = " << intVector1.capacity() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

/*************************************************************************************************/
/**************************               VECTOR.INSERT()               **************************/
/*************************************************************************************************/

	ft::vector<int>	intVector2(4);

	intVector1.push_back(1);
	intVector1.push_back(2);
	intVector1.push_back(3);
	intVector1.push_back(4);
	intVector1.push_back(5);

	std::cout << "intVector1: ";
	for (ft::vector<int>::iterator it = intVector1.begin(); it != intVector1.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "intVector1.size()     = " << intVector1.size() << std::endl;
	std::cout << "intVector1.capacity() = " << intVector1.capacity() << std::endl;

	std::cout << "intVector2: ";
	for (ft::vector<int>::iterator it = intVector2.begin(); it != intVector2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "intVector2.size()     = " << intVector2.size() << std::endl;
	std::cout << "intVector2.capacity() = " << intVector2.capacity() << std::endl;

	intVector2.insert(intVector2.begin() + 1, 5);

	std::cout << BLUE << "$>> intVector2.insert(intVector2.begin() + 1, 5)" << NORMAL << std::endl;

	std::cout << "intVector2: ";
	for (ft::vector<int>::iterator it = intVector2.begin(); it != intVector2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "intVector2.size()     = " << intVector2.size() << std::endl;
	std::cout << "intVector2.capacity() = " << intVector2.capacity() << std::endl;

	intVector2.insert(intVector2.begin() + 3, 3, 99);

	std::cout << BLUE << "$>> intVector2.insert(intVector2.begin() + 3, 3, 99)" << NORMAL << std::endl;

	std::cout << "intVector2: ";
	for (ft::vector<int>::iterator it = intVector2.begin(); it != intVector2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "intVector2.size()     = " << intVector2.size() << std::endl;
	std::cout << "intVector2.capacity() = " << intVector2.capacity() << std::endl;

	intVector2.insert(intVector2.end() - 1, intVector1.begin(), intVector1.end());

	std::cout << BLUE << "$>> intVector2.insert(intVector2.end() - 1, intVector1.begin(), intVector1.end())" << NORMAL << std::endl;

	std::cout << "intVector2: ";
	for (ft::vector<int>::iterator it = intVector2.begin(); it != intVector2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "intVector2.size()     = " << intVector2.size() << std::endl;
	std::cout << "intVector2.capacity() = " << intVector2.capacity() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;
}

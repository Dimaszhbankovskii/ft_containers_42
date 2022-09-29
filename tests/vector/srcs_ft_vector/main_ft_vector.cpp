#include "ft_vector.hpp"

int	main()
{
	std::cout << VIOLET;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "----------------   TEST VECTOR_ITERATOR 1   ----------------" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << NORMAL;

	test_iterator_1();

	std::cout << VIOLET;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "----------------   TEST VECTOR_ITERATOR 2   ----------------" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << NORMAL;
	
	test_iterator_2();

	std::cout << VIOLET;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "------------   TEST VECTOR_REVERSE_ITERATOR 1   ------------" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << NORMAL;

	test_reverse_iterator_1();

	return 0;
}

#include "std_vector.hpp"

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

	// std::cout << VIOLET;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << "------------   TEST VECTOR_REVERSE_ITERATOR 1   ------------" << std::endl;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << NORMAL;

	// test_reverse_iterator_1();

	// std::cout << VIOLET;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << "------------   TEST VECTOR_REVERSE_ITERATOR 2   ------------" << std::endl;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << NORMAL;

	// test_reverse_iterator_2();

	// std::cout << VIOLET;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << "--------------------    TEST VECTOR 1   --------------------" << std::endl;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << NORMAL;

	// test_vector_1();

	// std::cout << VIOLET;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << "------------    TEST VECTOR 1 (ELEMENT ACCESS)    ----------" << std::endl;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << NORMAL;

	// test_vector_1_element_access();

	// std::cout << VIOLET;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << "------------      TEST VECTOR 1 ( ITERATORS )     ----------" << std::endl;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << NORMAL;

	// test_vector_1_iterators();

	// std::cout << VIOLET;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << "------------      TEST VECTOR 1 ( CAPACITY )     -----------" << std::endl;
	// std::cout << "------------------------------------------------------------" << std::endl;
	// std::cout << NORMAL;

	// test_vector_1_capacity();

	return 0;
}

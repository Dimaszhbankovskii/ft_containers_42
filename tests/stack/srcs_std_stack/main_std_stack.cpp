#include <iostream>
#include <stack>

# define NORMAL "\033[0m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"
# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define VIOLET "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"

int	main()
{
	std::cout << VIOLET;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "--------------------    TEST STACK 1    --------------------" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << NORMAL;

	std::stack<int>	intStack1;

	std::cout << BLUE << "init    stack<int> intStack1" << NORMAL << std::endl;

	if (intStack1.empty())
		std::cout << "intStack1.empty() = true" << std::endl;
	else
		std::cout << "intStack1.empty() = false" << std::endl;
	std::cout << "intStack1.size() = " << intStack1.size() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	intStack1.push(1);
	intStack1.push(2);
	intStack1.push(3);

	std::cout << BLUE << "$>> intStack1.push(1)" << NORMAL << std::endl;
	std::cout << BLUE << "$>> intStack1.push(2)" << NORMAL << std::endl;
	std::cout << BLUE << "$>> intStack1.push(3)" << NORMAL << std::endl;

	if (intStack1.empty())
		std::cout << "intStack1.empty() = true" << std::endl;
	else
		std::cout << "intStack1.empty() = false" << std::endl;
	std::cout << "intStack1.size() = " << intStack1.size() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::stack<int>	intStack2(intStack1);

	std::cout << BLUE << "init    stack<int> intStack2(intStack1)" << NORMAL << std::endl;

	if (intStack2.empty())
		std::cout << "intStack2.empty() = true" << std::endl;
	else
		std::cout << "intStack2.empty() = false" << std::endl;
	std::cout << "intStack2.size() = " << intStack2.size() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::stack<int>	intStack3;
	intStack3 = intStack1;

	std::cout << BLUE << "init    intStack3 = intStack1" << NORMAL << std::endl;

	if (intStack3.empty())
		std::cout << "intStack3.empty() = true" << std::endl;
	else
		std::cout << "intStack3.empty() = false" << std::endl;
	std::cout << "intStack3.size() = " << intStack3.size() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "intStack3: ";
	while (intStack3.size())
	{
		std::cout << intStack3.top() << " ";
		intStack3.pop();
	}
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << VIOLET;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "--------    TEST STACK 1 ( ==, !=, <, <=, >, >= )   --------" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << NORMAL;

	intStack3 = intStack1;
	intStack3.push(10);

	std::cout << BLUE << "intStack1: 3 2 1" << NORMAL << std::endl;
	std::cout << BLUE << "intStack2: 3 2 1" << NORMAL << std::endl;
	std::cout << BLUE << "intStack3: 10 3 2 1" << NORMAL << std::endl;

	if (intStack1 == intStack2)
		std::cout << "intStack1 == intStack2 = True" << std::endl;
	else
		std::cout << "intStack1 == intStack2 = False" << std::endl;

	if (intStack1 != intStack2)
		std::cout << "intStack1 != intStack2 = True" << std::endl;
	else
		std::cout << "intStack1 != intStack2 = False" << std::endl;
	
	if (intStack1 > intStack2)
		std::cout << "intStack1 > intStack2 = True" << std::endl;
	else
		std::cout << "intStack1 > intStack2 = False" << std::endl;

	if (intStack1 >= intStack2)
		std::cout << "intStack1 >= intStack2 = True" << std::endl;
	else
		std::cout << "intStack1 >= intStack2 = False" << std::endl;

	if (intStack1 < intStack2)
		std::cout << "intStack1 < intStack2 = True" << std::endl;
	else
		std::cout << "intStack1 < intStack2 = False" << std::endl;

	if (intStack1 <= intStack2)
		std::cout << "intStack1 <= intStack2 = True" << std::endl;
	else
		std::cout << "intStack1 <= intStack2 = False" << std::endl;
	
	std::cout << "\n";

	if (intStack1 == intStack3)
		std::cout << "intStack1 == intStack3 = True" << std::endl;
	else
		std::cout << "intStack1 == intStack3 = False" << std::endl;

	if (intStack1 != intStack3)
		std::cout << "intStack1 != intStack3 = True" << std::endl;
	else
		std::cout << "intStack1 != intStack3 = False" << std::endl;
	
	if (intStack1 > intStack3)
		std::cout << "intStack1 > intStack3 = True" << std::endl;
	else
		std::cout << "intStack1 > intStack3 = False" << std::endl;

	if (intStack1 >= intStack3)
		std::cout << "intStack1 >= intStack3 = True" << std::endl;
	else
		std::cout << "intStack1 >= intStack3 = False" << std::endl;

	if (intStack1 < intStack3)
		std::cout << "intStack1 < intStack3 = True" << std::endl;
	else
		std::cout << "intStack1 < intStack3 = False" << std::endl;

	if (intStack1 <= intStack3)
		std::cout << "intStack1 <= intStack3 = True" << std::endl;
	else
		std::cout << "intStack1 <= intStack3 = False" << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	return 0;
}

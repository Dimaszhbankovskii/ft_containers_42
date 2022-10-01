#include "std_vector.hpp"

void	test_vector_1_element_access()
{
	std::vector<int>	intVector1;

	intVector1.push_back(1);
	intVector1.push_back(2);
	intVector1.push_back(3);
	intVector1.push_back(4);

	std::cout << "intVector1: ";
	for (size_t i = 0; i < intVector1.size(); ++i)
		std::cout << intVector1[i] << " ";
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	for (int i = -1; i < (int)intVector1.size() + 1; ++i)
	{
		std::cout << "intVector1.at( " << i << " ) = ";
		try
		{
			std::cout << intVector1.at(i);
		}
		catch(const std::exception& e)
		{
			std::cout << RED << e.what() << NORMAL;
		}
		std::cout << std::endl;
	}

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << BLUE << "intVector1: ";
	for (size_t i = 0; i < intVector1.size(); ++i)
		std::cout << intVector1[i] << " ";
	std::cout << NORMAL << std::endl;

	std::vector<int>::reference			refIntVector1 = intVector1.at(1);
	std::vector<int>::const_reference	cRefIntVector1 = intVector1.at(1);

	std::vector<int>::reference			refIntVector2 = intVector1[1];
	std::vector<int>::const_reference	cRefIntVector2 = intVector1[1];

	std::vector<int>::reference			refIntVector3 = intVector1.front();
	std::vector<int>::const_reference	cRefIntVector3 = intVector1.front();

	std::vector<int>::reference			refIntVector4 = intVector1.back();
	std::vector<int>::const_reference	cRefIntVector4 = intVector1.back();

	std::vector<int>::pointer			prtDataIntVector1 = intVector1.data();
	std::vector<int>::const_pointer		cPrtDataIntVector1 = intVector1.data();

	std::cout << "reference        intVector1.at(1)   = " << refIntVector1 << std::endl;
	std::cout << "const_reference  intVector1.at(1)   = " << cRefIntVector1 << std::endl;
	std::cout << "reference        intVector1[1]      = " << refIntVector2 << std::endl;
	std::cout << "const_reference  intVector1[1]      = " << cRefIntVector2 << std::endl;
	std::cout << "reference        intVector1.front() = " << refIntVector3 << std::endl;
	std::cout << "const_reference  intVector1.front() = " << cRefIntVector3 << std::endl;
	std::cout << "reference        intVector1.back()  = " << refIntVector4 << std::endl;
	std::cout << "const_reference  intVector1.back()  = " << cRefIntVector4 << std::endl;

	std::cout << "pointer          intVector1.data()  = ";
	for (size_t i = 0; i < intVector1.size(); ++i)
		std::cout << *(prtDataIntVector1 + i) << " ";
	std::cout << std::endl;

	std::cout << "const_pointer    intVector1.data()  = ";
	for (size_t i = 0; i < intVector1.size(); ++i)
		std::cout << *(cPrtDataIntVector1 + i) << " ";
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;
}

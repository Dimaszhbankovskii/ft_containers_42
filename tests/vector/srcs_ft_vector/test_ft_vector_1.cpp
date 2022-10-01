#include "ft_vector.hpp"

void	test_vector_1()
{
	ft::vector<int>	intVector1;

	std::cout << BLUE << "$>> init   vector<int> intVector1" << NORMAL << std::endl;

	ft::vector<int>::pointer	prt1 = intVector1.data();
	if (!prt1)
		std::cout << "prt1 = intVector1.data() == NULL" << std::endl;
	else
		std::cout << "prt1 = intVector1.data() == this->_prt" << std::endl;
	std::cout << "intVector1.capacity() = " << intVector1.capacity() << std::endl;
	std::cout << "intVector1.size() = " << intVector1.size() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<int>	intVector2(5);

	std::cout << BLUE << "$>> init   vector<int> intVector2(5)" << NORMAL << std::endl;

	ft::vector<int>::pointer	prt2 = intVector2.data();
	if (!prt2)
		std::cout << "prt2 = intVector2.data() == NULL" << std::endl;
	else
		std::cout << "prt2 = intVector2.data() == this->_prt" << std::endl;
	std::cout << "intVector2.capacity() = " << intVector2.capacity() << std::endl;
	std::cout << "intVector2.size() = " << intVector2.size() << std::endl;

	std::cout << "intVector2: ";
	for (size_t i = 0; i < intVector2.size(); ++i)
		std::cout << intVector2[i] << " ";
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<int>	intVectorTmp1(2);

	intVectorTmp1.push_back(3);
	intVectorTmp1.push_back(4);
	intVectorTmp1.push_back(5);

	try
	{
		std::cout << BLUE << "$>> intVectorTmp2(intVectorTmp1.end(), intVectorTmp1.begin()) ==>" << NORMAL << std::endl;
		ft::vector<int>	intVectorTmp2(intVectorTmp1.end(), intVectorTmp1.begin());
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << NORMAL << std::endl;
	}

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << BLUE << "$>> init   vector<int> intVector3(intVectorTmp.begin(), intVectorTmp.end())" << NORMAL << std::endl;

	ft::vector<int>				intVector3(intVectorTmp1.begin(), intVectorTmp1.end());
	ft::vector<int>::pointer	prt3 = intVector3.data();
	if (!prt3)
		std::cout << "prt3 = intVector3.data() == NULL" << std::endl;
	else
		std::cout << "prt3 = intVector3.data() == this->_prt" << std::endl;
	std::cout << "intVector3.capacity() = " << intVector3.capacity() << std::endl;
	std::cout << "intVector3.size() = " << intVector3.size() << std::endl;
	
	std::cout << "intVector3: ";
	for (size_t i = 0; i < intVector3.size(); ++i)
		std::cout << intVector3[i] << " ";
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << BLUE << "$>> init   vector<int> intVector4(intVector3)" << NORMAL << std::endl;

	ft::vector<int>				intVector4(intVector3);
	ft::vector<int>::pointer	prt4 = intVector4.data();
	if (!prt4)
		std::cout << "prt4 = intVector4.data() == NULL" << std::endl;
	else
		std::cout << "prt4 = intVector4.data() == this->_prt" << std::endl;
	std::cout << "intVector4.capacity() = " << intVector4.capacity() << std::endl;
	std::cout << "intVector4.size() = " << intVector4.size() << std::endl;
	
	std::cout << "intVector4: ";
	for (size_t i = 0; i < intVector4.size(); ++i)
		std::cout << intVector4[i] << " ";
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << BLUE << "$>> init   intVector5 = intVector4" << NORMAL << std::endl;
	
	ft::vector<int>	intVector5;

	intVector5 = intVector4;

	ft::vector<int>::pointer	prt5 = intVector5.data();
	if (!prt5)
		std::cout << "prt5 = intVector5.data() == NULL" << std::endl;
	else
		std::cout << "prt5 = intVector5.data() == this->_prt" << std::endl;
	std::cout << "intVector5.capacity() = " << intVector5.capacity() << std::endl;
	std::cout << "intVector5.size() = " << intVector5.size() << std::endl;
	
	std::cout << "intVector5: ";
	for (size_t i = 0; i < intVector5.size(); ++i)
		std::cout << intVector5[i] << " ";
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	intVector5.pop_back();
	intVector5.pop_back();

	std::cout << "intVector5: ";
	for (size_t i = 0; i < intVector5.size(); ++i)
		std::cout << intVector5[i] << " ";
	std::cout << std::endl;

	std::cout << BLUE << "$>> intVector5 = intVector4" << NORMAL << std::endl;
	
	intVector5 = intVector4;

	ft::vector<int>::pointer	prt6 = intVector5.data();
	if (!prt6)
		std::cout << "prt6 = intVector5.data() == NULL" << std::endl;
	else
		std::cout << "prt6 = intVector5.data() == this->_prt" << std::endl;
	std::cout << "intVector5.capacity() = " << intVector5.capacity() << std::endl;
	std::cout << "intVector5.size() = " << intVector5.size() << std::endl;
	
	std::cout << "intVector5: ";
	for (size_t i = 0; i < intVector5.size(); ++i)
		std::cout << intVector5[i] << " ";
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "intVector5: ";
	for (size_t i = 0; i < intVector5.size(); ++i)
		std::cout << intVector5[i] << " ";
	std::cout << std::endl;

	std::cout << "intVector5.capacity() = " << intVector5.capacity() << std::endl;
	std::cout << "intVector5.size() = " << intVector5.size() << std::endl;

	intVector5.assign(3, 111);

	std::cout << BLUE << "$>> intVector5.assign(3, 111)" << NORMAL << std::endl;
	
	std::cout << "intVector5: ";
	for (size_t i = 0; i < intVector5.size(); ++i)
		std::cout << intVector5[i] << " ";
	std::cout << std::endl;

	std::cout << "intVector5.capacity() = " << intVector5.capacity() << std::endl;
	std::cout << "intVector5.size() = " << intVector5.size() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "intVector5: ";
	for (size_t i = 0; i < intVector5.size(); ++i)
		std::cout << intVector5[i] << " ";
	std::cout << std::endl;

	std::cout << "intVector5.capacity() = " << intVector5.capacity() << std::endl;
	std::cout << "intVector5.size() = " << intVector5.size() << std::endl;

	intVector5.assign(7, 99);

	std::cout << BLUE << "$>> intVector5.assign(7, 99)" << NORMAL << std::endl;
	
	std::cout << "intVector5: ";
	for (size_t i = 0; i < intVector5.size(); ++i)
		std::cout << intVector5[i] << " ";
	std::cout << std::endl;

	std::cout << "intVector5.capacity() = " << intVector5.capacity() << std::endl;
	std::cout << "intVector5.size() = " << intVector5.size() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<int>	intVector6;

	intVector6.push_back(-11);
	intVector6.push_back(-12);
	intVector6.push_back(-13);
	intVector6.push_back(14);
	intVector6.push_back(15);
	intVector6.push_back(16);

	std::cout << "intVector6: ";
	for (size_t i = 0; i < intVector6.size(); ++i)
		std::cout << intVector6[i] << " ";
	std::cout << std::endl;

	ft::vector<int>	intVector7(2);

	std::cout << "intVector7.capacity() = " << intVector7.capacity() << std::endl;
	std::cout << "intVector7.size() = " << intVector7.size() << std::endl;

	intVector7.assign(intVector6.begin(), intVector6.end());

	std::cout << BLUE << "$>> intVector7.assign(intVector6.begin(), intVector6.end())" << NORMAL << std::endl;

	std::cout << "intVector7: ";
	for (size_t i = 0; i < intVector7.size(); ++i)
		std::cout << intVector7[i] << " ";
	std::cout << std::endl;

	std::cout << "intVector7.capacity() = " << intVector7.capacity() << std::endl;
	std::cout << "intVector7.size() = " << intVector7.size() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "intVector6: ";
	for (size_t i = 0; i < intVector6.size(); ++i)
		std::cout << intVector6[i] << " ";
	std::cout << std::endl;

	ft::vector<int>	intVector8(10);

	std::cout << "intVector8.capacity() = " << intVector8.capacity() << std::endl;
	std::cout << "intVector8.size() = " << intVector8.size() << std::endl;

	intVector8.assign(intVector6.begin(), intVector6.end());

	std::cout << BLUE << "$>> intVector8.assign(intVector6.begin(), intVector6.end())" << NORMAL << std::endl;

	std::cout << "intVector8: ";
	for (size_t i = 0; i < intVector8.size(); ++i)
		std::cout << intVector8[i] << " ";
	std::cout << std::endl;

	std::cout << "intVector8.capacity() = " << intVector8.capacity() << std::endl;
	std::cout << "intVector8.size() = " << intVector8.size() << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;
}

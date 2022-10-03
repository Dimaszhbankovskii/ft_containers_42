#include "ft_vector.hpp"

void	test_iterator_1()
{
	ft::vector<int>	intVector;

	intVector.push_back(1);
	intVector.push_back(2);
	intVector.push_back(3);
	intVector.push_back(4);
	intVector.push_back(5);
	intVector.push_back(6);

	std::cout << "------------------------------------------------------------" << std::endl;
	
	std::cout << "intVector: ";
	for (ft::vector<int>::iterator it = intVector.begin(); it != intVector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

/*************************************************************************************************/
/******************************     MANIPULATIONS FOR ITERATORS     ******************************/
/*************************************************************************************************/

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << CYAN;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "---------------   TEST VECTOR_ITERATOR 1.1   ---------------" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << NORMAL;
	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<int>::iterator	it1, it2;

	it1 = intVector.begin();
	it2 = intVector.end() - 1;

	ft::vector<int>::iterator::iterator_type	p = it1.base();

	std::cout << "*p = it1.base() = " << *p << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "*( it1 = intVector.begin() ) = " << *it1 << std::endl;
	std::cout << "*( it2 = intVector.end() - 1 )= " << *it2 << std::endl;

	ft::vector<int>::iterator	it3(it1);
	ft::vector<int>::iterator	it4 = it1;

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

	ft::vector<int>::iterator	it5 = it1 + 3;
	ft::vector<int>::iterator	it6 = it5 - 2;

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

	ft::vector<int>::iterator	it7 = 2 + it1;

	std::cout << "it7 = 2 + it1 = " << *it7 << std::endl;

/*************************************************************************************************/
/**************************     MANIPULATIONS FOR CONST ITERATORS     ****************************/
/*************************************************************************************************/

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << CYAN;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "---------------   TEST VECTOR_ITERATOR 1.2   ---------------" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << NORMAL;
	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<int>::const_iterator	cIt1, cIt2;

	cIt1 = intVector.begin();
	cIt2 = intVector.end() - 1;

	ft::vector<int>::const_iterator::iterator_type	cP = cIt1.base();

	std::cout << "*cP = it1.base() = " << *cP << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "*( cIt1 = intVector.begin() ) = " << *cIt1 << std::endl;
	std::cout << "*( cIt2 = intVector.end() - 1 )= " << *cIt2 << std::endl;

	ft::vector<int>::const_iterator	cIt3(cIt1);
	ft::vector<int>::const_iterator	cIt4 = cIt1;

	std::cout << "*( cIt3( cIt1 ) ) = " << *cIt3 << std::endl;
	std::cout << "*( cIt4 = cIt1 ) = " << *cIt4 << std::endl;
	std::cout << "cIt1[1] = " << cIt1[1] << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "cIt1 = " << *cIt1 << " --> ++cIt1 = " << *(++cIt1);
	std::cout << " --> cIt1 = " << *cIt1 << std::endl;

	std::cout << "cIt1 = " << *cIt1 << " --> --cIt1 = " << *(--cIt1);
	std::cout << " --> cIt1 = " << *cIt1 << std::endl;

	std::cout << "cIt1 = " << *cIt1 << " --> cIt1++ = " << *(cIt1++);
	std::cout << " --> cIt1 = " << *cIt1 << std::endl;

	std::cout << "cIt1 = " << *cIt1 << " --> cIt1-- = " << *(cIt1--);
	std::cout << " --> cIt1 = " << *cIt1 << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<int>::const_iterator	cIt5 = cIt1 + 3;
	ft::vector<int>::const_iterator	cIt6 = cIt5 - 2;

	std::cout << "cIt5 = cIt1 + 3 = " << *cIt5 << std::endl;
	std::cout << "cIt6 = cIt5 - 2 = " << *cIt6 << std::endl;

	cIt4 += 3;
	std::cout << "cIt4 += 3 = " << *cIt4 << std::endl;
	cIt4 -= 3;
	std::cout << "cIt4 -= 3 = " << *cIt4 << std::endl;

	std::cout << "cIt5 - cIt6 = " << cIt5 - cIt6 << std::endl;
	std::cout << "cIt6 - cIt5 = " << cIt6 - cIt5 << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "cIt1 = " << *cIt1 << std::endl;
	std::cout << "cIt4 = " << *cIt4 << std::endl;

	if (cIt1 == cIt4)
		std::cout << "cIt1 == cIt4 = True" << std::endl;
	else
		std::cout << "cIt1 == cIt4 = False" << std::endl;

	if (cIt1 != cIt4)
		std::cout << "cIt1 != cIt4 = True" << std::endl;
	else
		std::cout << "cIt1 != cIt4 = False" << std::endl;
	
	if (cIt1 > cIt4)
		std::cout << "cIt1 > cIt4 = True" << std::endl;
	else
		std::cout << "cIt1 > cIt4 = False" << std::endl;

	if (cIt1 >= cIt4)
		std::cout << "cIt1 >= cIt4 = True" << std::endl;
	else
		std::cout << "cIt1 >= cIt4 = False" << std::endl;

	if (cIt1 < cIt4)
		std::cout << "cIt1 < cIt4 = True" << std::endl;
	else
		std::cout << "cIt1 < cIt4 = False" << std::endl;

	if (cIt1 <= cIt4)
		std::cout << "cIt1 <= cIt4 = True" << std::endl;
	else
		std::cout << "cIt1 <= cIt4 = False" << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "cIt1 = " << *cIt1 << std::endl;
	std::cout << "cIt5 = " << *cIt5 << std::endl;

	if (cIt1 == cIt5)
		std::cout << "cIt1 == cIt5 = True" << std::endl;
	else
		std::cout << "cIt1 == cIt5 = False" << std::endl;

	if (cIt1 != cIt5)
		std::cout << "cIt1 != cIt5 = True" << std::endl;
	else
		std::cout << "cIt1 != cIt5 = False" << std::endl;
	
	if (cIt1 > cIt5)
		std::cout << "cIt1 > cIt5 = True" << std::endl;
	else
		std::cout << "cIt1 > cIt5 = False" << std::endl;

	if (cIt1 >= cIt5)
		std::cout << "cIt1 >= cIt5 = True" << std::endl;
	else
		std::cout << "cIt1 >= cIt5 = False" << std::endl;

	if (cIt1 < cIt5)
		std::cout << "cIt1 < cIt5 = True" << std::endl;
	else
		std::cout << "cIt1 < cIt5 = False" << std::endl;

	if (cIt1 <= cIt5)
		std::cout << "cIt1 <= cIt5 = True" << std::endl;
	else
		std::cout << "cIt1 <= cIt5 = False" << std::endl;
	
	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<int>::const_iterator	cIt7 = 2 + cIt1;

	std::cout << "cIt7 = 2 + cIt1 = " << *cIt7 << std::endl;

/*************************************************************************************************/
/*******************     MANIPULATIONS FOR ITERATORS && CONST ITERATORS      *********************/
/*************************************************************************************************/

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << CYAN;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "---------------   TEST VECTOR_ITERATOR 1.3   ---------------" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << NORMAL;
	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<int>::const_iterator	it_to_cIt_1(it1);
	ft::vector<int>::const_iterator	it_to_cIt_2 = it1;

	std::cout << "*( const_iterator    it_to_cIt_1( it1 ) ) = " << *it_to_cIt_1 << std::endl;
	std::cout << "*( const_iterator    it_to_cIt_2 = it1 ) = " << *it_to_cIt_2 << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "it1 = " << *it1 << std::endl;
	std::cout << "cIt4 = " << *cIt4 << std::endl;

	if (it1 == cIt4)
		std::cout << "it1 == cIt4 = True" << std::endl;
	else
		std::cout << "it1 == cIt4 = False" << std::endl;

	if (it1 != cIt4)
		std::cout << "it1 != cIt4 = True" << std::endl;
	else
		std::cout << "it1 != cIt4 = False" << std::endl;
	
	if (it1 > cIt4)
		std::cout << "it1 > cIt4 = True" << std::endl;
	else
		std::cout << "it1 > cIt4 = False" << std::endl;

	if (it1 >= cIt4)
		std::cout << "it1 >= cIt4 = True" << std::endl;
	else
		std::cout << "it1 >= cIt4 = False" << std::endl;

	if (it1 < cIt4)
		std::cout << "it1 < cIt4 = True" << std::endl;
	else
		std::cout << "it1 < cIt4 = False" << std::endl;

	if (it1 <= cIt4)
		std::cout << "it1 <= cIt4 = True" << std::endl;
	else
		std::cout << "it1 <= cIt4 = False" << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "cIt1 = " << *cIt1 << std::endl;
	std::cout << "it5 = " << *it5 << std::endl;

	if (cIt1 == it5)
		std::cout << "cIt1 == it5 = True" << std::endl;
	else
		std::cout << "cIt1 == it5 = False" << std::endl;

	if (cIt1 != it5)
		std::cout << "cIt1 != it5 = True" << std::endl;
	else
		std::cout << "cIt1 != it5 = False" << std::endl;
	
	if (cIt1 > it5)
		std::cout << "cIt1 > it5 = True" << std::endl;
	else
		std::cout << "cIt1 > it5 = False" << std::endl;

	if (cIt1 >= it5)
		std::cout << "cIt1 >= it5 = True" << std::endl;
	else
		std::cout << "cIt1 >= it5 = False" << std::endl;

	if (cIt1 < it5)
		std::cout << "cIt1 < it5 = True" << std::endl;
	else
		std::cout << "cIt1 < it5 = False" << std::endl;

	if (cIt1 <= it5)
		std::cout << "cIt1 <= it5 = True" << std::endl;
	else
		std::cout << "cIt1 <= it5 = False" << std::endl;
	
	std::cout << "------------------------------------------------------------" << std::endl;
}

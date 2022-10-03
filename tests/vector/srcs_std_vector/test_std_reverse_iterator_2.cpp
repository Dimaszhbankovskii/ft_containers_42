#include "std_vector.hpp"

static std::ostream&	operator<<(std::ostream& outstream, const Fixed& fixed)
{
	return outstream << "(" << fixed.getX() << " ; " << fixed.getY() << ")";
}

void	test_reverse_iterator_2()
{
	std::vector<Fixed>	fixedVector;

	fixedVector.push_back(Fixed(1, 1.5f));
	fixedVector.push_back(Fixed(2, 2.5f));
	fixedVector.push_back(Fixed(3, 3.5f));
	fixedVector.push_back(Fixed(4, 4.5f));
	fixedVector.push_back(Fixed(5, 5.5f));
	fixedVector.push_back(Fixed(6, 6.5f));

	std::cout << "------------------------------------------------------------" << std::endl;
	
	std::cout << "fixedVector: ";
	for (std::vector<Fixed>::reverse_iterator it = fixedVector.rbegin(); it != fixedVector.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

/*************************************************************************************************/
/**************************     MANIPULATIONS FOR REVERSE_ITERATORS     **************************/
/*************************************************************************************************/

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << CYAN;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "-----------   TEST VECTOR_REVERSE_ITERATOR 1.1   -----------" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << NORMAL;
	std::cout << "------------------------------------------------------------" << std::endl;

	std::vector<Fixed>::reverse_iterator	it1, it2;

	it1 = fixedVector.rbegin();
	it2 = fixedVector.rend() - 1;

	std::cout << "*( it1 = fixedVector.rbegin() ) = " << *it1 << std::endl;
	std::cout << "*( it2 = fixedVector.rend() - 1 )= " << *it2 << std::endl;

	std::vector<Fixed>::reverse_iterator	it3(it1);
	std::vector<Fixed>::reverse_iterator	it4 = it1;

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

	std::vector<Fixed>::reverse_iterator	it5 = it1 + 3;
	std::vector<Fixed>::reverse_iterator	it6 = it5 - 2;

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

	std::vector<Fixed>::reverse_iterator	it7 = 2 + it1;

	std::cout << "it7 = 2 + it1 = " << *it7 << std::endl;

/*************************************************************************************************/
/**********************     MANIPULATIONS FOR CONST REVERSE_ITERATORS     ************************/
/*************************************************************************************************/

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << CYAN;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "-----------   TEST VECTOR_REVERSE_ITERATOR 1.2   -----------" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << NORMAL;
	std::cout << "------------------------------------------------------------" << std::endl;

	std::vector<Fixed>::const_reverse_iterator	cIt1, cIt2;

	cIt1 = fixedVector.rbegin();
	cIt2 = fixedVector.rend() - 1;

	std::cout << "*( cIt1 = fixedVector.rbegin() ) = " << *cIt1 << std::endl;
	std::cout << "*( cIt2 = fixedVector.rend() - 1 ) = " << *cIt2 << std::endl;

	std::vector<Fixed>::const_reverse_iterator	cIt3(cIt1);
	std::vector<Fixed>::const_reverse_iterator	cIt4 = cIt1;

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

	std::vector<Fixed>::const_reverse_iterator	cIt5 = cIt1 + 3;
	std::vector<Fixed>::const_reverse_iterator	cIt6 = cIt5 - 2;

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

	std::vector<Fixed>::const_reverse_iterator	cIt7 = 2 + cIt1;

	std::cout << "cIt7 = 2 + cIt1 = " << *cIt7 << std::endl;

/*************************************************************************************************/
/*******************     MANIPULATIONS FOR ITERATORS && CONST ITERATORS      *********************/
/*************************************************************************************************/

	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << CYAN;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "-----------   TEST VECTOR_REVERSE_ITERATOR 1.3   -----------" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << NORMAL;
	std::cout << "------------------------------------------------------------" << std::endl;

	std::vector<Fixed>::const_reverse_iterator	it_to_cIt_1(it1);
	std::vector<Fixed>::const_reverse_iterator	it_to_cIt_2 = it1;

	std::cout << "*( const_reverse_iterator    it_to_cIt_1( it1 ) ) = " << *it_to_cIt_1 << std::endl;
	std::cout << "*( const_reverse_iterator    it_to_cIt_2 = it1 ) = " << *it_to_cIt_2 << std::endl;

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

#include "ft_vector.hpp"

static std::ostream&	operator<<(std::ostream& outstream, const Fixed& fixed)
{
	return outstream << "(" << fixed.getX() << " ; " << fixed.getY() << ")";
}

void	test_iterator_2()
{
	ft::vector<Fixed>			fixedVector;
	ft::vector<Fixed>::iterator	it1, it2;

	fixedVector.push_back(Fixed(1, 1.5f));
	fixedVector.push_back(Fixed(2, 2.5f));
	fixedVector.push_back(Fixed(3, 3.5f));
	fixedVector.push_back(Fixed(4, 4.5f));
	fixedVector.push_back(Fixed(5, 5.5f));
	fixedVector.push_back(Fixed(6, 6.5f));

	std::cout << "------------------------------------------------------------" << std::endl;

	it1 = fixedVector.begin();
	it2 = fixedVector.end() - 1;
	
	std::cout << "fixedVector: ";
	for (ft::vector<Fixed>::iterator it = fixedVector.begin(); it != fixedVector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	ft::vector<Fixed>::iterator::iterator_type	p = it1.base();

	std::cout << "*p = it1.base() = " << *p << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;

	std::cout << "*( it1 = fixedVector.begin() ) = " << *it1 << std::endl;
	std::cout << "*( it2 = fixedVector.end() - 1 )= " << *it2 << std::endl;

	ft::vector<Fixed>::iterator	it3(it1);
	ft::vector<Fixed>::iterator	it4 = it1;

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

	ft::vector<Fixed>::iterator	it5 = it1 + 3;
	ft::vector<Fixed>::iterator	it6 = it5 - 2;

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

	ft::vector<Fixed>::iterator	it7 = 2 + it1;

	std::cout << "it7 = 2 + it1 = " << *it7 << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl;
}

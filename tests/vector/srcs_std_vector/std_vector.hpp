#ifndef STD_VECTOR_HPP
# define STD_VECTOR_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <cmath>

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

void	test_iterator_1();
void	test_iterator_2();
void	test_reverse_iterator_1();
void	test_reverse_iterator_2();

void	test_vector_1();
void	test_vector_1_element_access();
void	test_vector_1_iterators();
void	test_vector_1_capacity();
void	test_vector_1_modifiers();

class Fixed
{
private:
	int		_x;
	float	_y;

public:
	Fixed() { this->_x = 0; this->_y = 0.0f; }
	Fixed(int x, float y) { this->_x = x; this->_y = y; }
	Fixed(Fixed const &src) { *this = src; }
	~Fixed() {}

	Fixed&	operator=(Fixed const &src)
	{
		if (this == &src)
			return (*this);
		this->_x = src._x;
		this->_y = src._y;
		return (*this);
	}

	bool	operator<(Fixed const &fixed) const { return this->_x < fixed._x && this->_y < fixed._y; }
	bool	operator>(Fixed const &fixed) const { return this->_x > fixed._x && this->_y > fixed._y; }
	bool	operator<=(Fixed const &fixed) const { return this->_x <= fixed._x && this->_y <= fixed._y; }
	bool	operator>=(Fixed const &fixed) const { return this->_x >= fixed._x && this->_y >= fixed._y; }
	bool	operator==(Fixed const &fixed) const { return this->_x == fixed._x && this->_y == fixed._y; }
	bool	operator!=(Fixed const &fixed) const { return this->_x != fixed._x && this->_y != fixed._y; }

	int		getX() const { return this->_x; }
	float	getY() const { return this->_y; }

};

#endif
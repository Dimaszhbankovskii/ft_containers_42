#include <iostream>
#include <iomanip>
# include "./../../../includes/type_traits.hpp"

#define SHOW(...) std::cout << std::setw(50) << #__VA_ARGS__ << " == " << __VA_ARGS__ << "\n";

struct A
{
	int		x;
	double	y;
};

int	main()
{
	std::cout << std::boolalpha;

	SHOW( ft::is_integral<bool>::value );

	SHOW( ft::is_integral<char>::value );
	SHOW( ft::is_integral<signed char>::value );
	SHOW( ft::is_integral<unsigned char>::value );
	SHOW( ft::is_integral<wchar_t>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( ft::is_integral<short int>::value );
	SHOW( ft::is_integral<unsigned short int>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( ft::is_integral<int>::value );
	SHOW( ft::is_integral<unsigned int>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( ft::is_integral<long int>::value );
	SHOW( ft::is_integral<unsigned long int>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( ft::is_integral<long long int>::value );
	SHOW( ft::is_integral<unsigned long long int>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( ft::is_integral<float>::value );
	SHOW( ft::is_integral<double>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( ft::is_integral<std::string>::value );
	SHOW( ft::is_integral<A>::value );
	
	std::cout << std::ends;

	return 0;
}

#include <iostream>
#include <iomanip>
#include <type_traits>

#define SHOW(...) std::cout << std::setw(50) << #__VA_ARGS__ << " == " << __VA_ARGS__ << "\n";

struct A
{
	int		x;
	double	y;
};

int	main()
{
	std::cout << std::boolalpha;

	SHOW( std::is_integral<bool>::value );

	SHOW( std::is_integral<char>::value );
	SHOW( std::is_integral<signed char>::value );
	SHOW( std::is_integral<unsigned char>::value );
	SHOW( std::is_integral<wchar_t>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( std::is_integral<short int>::value );
	SHOW( std::is_integral<unsigned short int>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( std::is_integral<int>::value );
	SHOW( std::is_integral<unsigned int>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( std::is_integral<long int>::value );
	SHOW( std::is_integral<unsigned long int>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( std::is_integral<long long int>::value );
	SHOW( std::is_integral<unsigned long long int>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( std::is_integral<float>::value );
	SHOW( std::is_integral<double>::value );
	std::cout << "------------------------------------------------------------" << std::endl;
	SHOW( std::is_integral<std::string>::value );
	SHOW( std::is_integral<A>::value );
	std::cout << std::ends;

	return 0;
}

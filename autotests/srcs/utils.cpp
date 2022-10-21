#include "./../includes/autotests.hpp"

void	print_header(std::string str)
{
	int margin = (40 - str.length()) / 2;
	int width = (margin * 2 + str.length()) + 2;
	std::cout << BLUE << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << "*" << std::string(margin, ' ') << str << std::string(margin, ' ') << "*" << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << RESET;
}

void	check(std::string name, bool good)
{
	std::string margin(38 - name.length(), ' ');
	if (good)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << FAIL << std::endl;
}

// template <typename T>
// void	check1(std::string name, T a, T b)
// {
// 	std::string margin(38 - name.length(), ' ');
// 	if (a == b)
// 		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
// 	else
// 		std::cout << name << ": " << margin << FAIL << std::endl;
// }


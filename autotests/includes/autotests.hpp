#ifndef AUTOTESTS_HPP
# define AUTOTESTS_HPP

# include <iostream>

# include <vector>
# include <stack>

# include "./../../includes/iterator.hpp"
# include "./../../includes/type_traits.hpp"

# include "./../../includes/vector.hpp"
# include "./../../includes/stack.hpp"

# ifdef __linux__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
# endif

# ifdef __APPLE__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
# endif

# define GOOD "✅"
# define FAIL "❌"

void	test_vector(void);
void	test_stack(void);

void    print_header(std::string str);

// template <typename T>
// void	check1(std::string name, T a, T b);

void	check(std::string name, bool good);

template <typename T>
bool	operator==(ft::vector<T> &a, std::vector<T> &b);

#endif
#include "./../includes/autotests.hpp"

template <typename T>
static void print_vector(T vec, std::string type)
{
	typename T::iterator it;

	std::cout << BOLD << type << ", size: " << vec.size() << ", empty: " << vec.empty() << ", capacity: " << vec.capacity() << RESET << std::endl;
	it = vec.begin();
	while (it != vec.end())
	{
		std::cout << "'" <<*it << "'";
		if (it + 1 != vec.end())
			std::cout << " - ";
		++it;
	}
	std::cout << std::endl;
}

template <typename T>
static void print_vector_reverse(T vec, std::string type)
{
	typename T::iterator it;

	std::cout << BOLD << type << ", size: " << vec.size() << ", empty: " << vec.empty() << ", capacity: " << vec.capacity() << RESET << std::endl;
	it = vec.rbegin();
	while (it != vec.rend())
	{
		std::cout << *it;
		if (it + 1 != vec.rend())
			std::cout << " - ";
		++it;
	}
	std::cout << std::endl;
}

template <typename T>
static bool	operator==(ft::vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
}

static void default_constructor()
{
	print_header("Default  constructor");
	{
		ft::vector<int>		intV1;
		std::vector<int>	intV2;
		check("intV1 == intV2", intV1 == intV2);
		for (size_t i = 0; i < 10; ++i)
		{
			intV1.push_back(i);
			intV2.push_back(i);
		}
		check("intV1 == intV2", intV1 == intV2);
	}
	{
		ft::vector<std::string>		strV1(2);
		std::vector<std::string>	strV2(2);
		check("strV1 == strV2", strV1 == strV2);
		for (size_t i = 1; i < 6; ++i)
		{
			strV1.push_back("test");
			strV2.push_back("test");
		}
		check("strV1 == strV2", strV1 == strV2);
	}
}

static void	copy_constructor()
{
	print_header("Copy constructor");
	{
		ft::vector<int>		intV1;
		std::vector<int>	intV2;
		for (int i = -5 ; i < 6; ++i)
		{
			intV1.push_back(i);
			intV2.push_back(i);
		}
		ft::vector<int> 	copyIntV1(intV1);
		std::vector<int> 	copyIntV2(intV2);
		intV1.push_back(42);
		intV2.push_back(42);
		check("intV1 == intV2", (intV1 == intV2));
		check("copyIntV1 == copyIntV2", (copyIntV1 == copyIntV2));
		check("intV1 != copyIntV1", (intV1 != copyIntV1));
		check("intV2 != copyIntV2", (intV2 != copyIntV2));
	}
	{
		ft::vector<std::string>		strV1;
		std::vector<std::string>	strV2;
		for (size_t i = 0 ; i < 4; ++i)
		{
			strV1.push_back("str");
			strV2.push_back("str");
		}
		ft::vector<std::string> 	copyStrV1(strV1);
		std::vector<std::string> 	copyStrV2(strV2);
		strV1.push_back("newStr");
		strV2.push_back("newStr");
		check("strV1 == strV2", (strV1 == strV2));
		check("copyStrV1 == copyStrV2", (copyStrV1 == copyStrV2));
		check("strV1 != copyStrV1", (strV1 != copyStrV1));
		check("strV2 != copyStrV2", (strV2 != copyStrV2));
	}
}

static void access_operator()
{
	print_header("at(),  operator []");
	ft::vector<int>		intV1;
	std::vector<int> 	intV2;
	for (int i = 1; i < 6; ++i)
	{
		intV1.push_back(i);
		intV2.push_back(i);
	}
	try
	{
		std::cout << "intV1.at(100): " << intV1.at(100) << ": " << FAIL << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "error" << ": " << std::string(18, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
	try
	{
		std::cout << "intV2.at(100): " << intV2.at(100) << ": " << FAIL << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "error" << ": " << std::string(18, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
	try
	{
		std::cout << "intV1.at(2): " << intV1.at(2) << ": " << std::string(24, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << ": " << FAIL << std::endl;
	}
	try
	{
		std::cout << "intV2.at(2): " << intV2.at(2) << ": " << std::string(24, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << ": " << FAIL << std::endl;
	}		
	try
	{
		std::cout << "intV1.at(-1): " << intV1.at(-1) << ": " << FAIL << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "error" << ": " << std::string(19, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
	try
	{
		std::cout << "intV2.at(-1): " << intV2.at(-1) << ": " << FAIL << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "error" << ": " << std::string(19, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
	check("intV1[0] == intV2[0]", intV1[0] == intV2[0]);
	check("intV1[1] == intV2[1]", intV1[1] == intV2[1]);
	check("intV1[2] == intV2[2]", intV1[2] == intV2[2]);
}

static void access_front_back_data()
{
	print_header("Front / Back / Data");
	ft::vector<int> 	intV1;
	std::vector<int>	intV2;
	for (int i = 1; i < 11; ++i)
	{
		intV1.push_back(i);
		intV2.push_back(i);
	}
	check("intV1.front() == intV2.front()", intV1.front() == intV2.front());
	check("intV1.back() == intV2.back()", intV1.back() == intV2.back());
	ft::vector<int>::const_reference	cRefIntV1_front = intV1.front();
	std::vector<int>::const_reference	cRefIntV2_front = intV2.front();
	ft::vector<int>::const_reference	cRefIntV1_back = intV1.back();
	std::vector<int>::const_reference	cRefIntV2_back = intV2.back();
	check("cRefIntV1_front == cRefIntV2_front", cRefIntV1_front == cRefIntV2_front);
	check("cRefIntV1_back == cRefIntV2_back", cRefIntV1_back == cRefIntV2_back);
	ft::vector<int>::pointer		prtIntV1 = intV1.data();
	std::vector<int>::pointer		prtIntV2 = intV2.data();
	ft::vector<int>::const_pointer	cPrtIntV1 = intV1.data();
	std::vector<int>::const_pointer	cPrtIntV2 = intV2.data();
	check("intV1.data() == intV2.data()", *prtIntV1 == *prtIntV2);
	check("cPrtIntV1_data == cPrtIntV2_data", *cPrtIntV1 == *cPrtIntV2);
}

static void	capacity()
{
	print_header("Capacity");
	{
		ft::vector<int> 	intV1;
		std::vector<int>	intV2;
		check("intV1.empty() == intV2.empty()", intV1.empty() == intV2.empty());
		check("intV1.size() == intV2.size()", intV1.size() == intV2.size());
		check("intV1.max_size() == intV2.max_size()", intV1.max_size() == intV2.max_size());
		check("intV1.capacity() == intV2.capacity()", intV1.capacity() == intV2.capacity());
		for (int i = 1; i < 11; ++i)
		{
			intV1.push_back(i);
			intV2.push_back(i);
		}
		check("intV1.empty() == intV2.empty()", intV1.empty() == intV2.empty());
		check("intV1.size() == intV2.size()", intV1.size() == intV2.size());
		check("intV1.max_size() == intV2.max_size()", intV1.max_size() == intV2.max_size());
		check("intV1.capacity() == intV2.capacity()", intV1.capacity() == intV2.capacity());
	}
	std::cout << std::endl;
	{
		ft::vector<std::string>		strV1;
		std::vector<std::string>	strV2;
		check("strV1.empty() == strV2.empty()", strV1.empty() == strV2.empty());
		check("strV1.size() == strV2.size()", strV1.size() == strV2.size());
		check("strV1.max_size() == strV2.max_size()", strV1.max_size() == strV2.max_size());
		check("strV1.capacity() == strV2.capacity()", strV1.capacity() == strV2.capacity());
		for (size_t i = 0; i < 11; ++i)
		{
			strV1.push_back("test");
			strV2.push_back("test");
		}
		check("strV1.empty() == strV2.empty()", strV1.empty() == strV2.empty());
		check("strV1.size() == strV2.size()", strV1.size() == strV2.size());
		check("strV1.max_size() == strV2.max_size()", strV1.max_size() == strV2.max_size());
		check("strV1.capacity() == strV2.capacity()", strV1.capacity() == strV2.capacity());
	}
}

static void	insert()
{
	print_header("Insert");
	ft::vector<int>		srcV1;
	std::vector<int>	srcV2;
	ft::vector<int>		intV1;
	std::vector<int>	intV2;
	for (int i = 0; i < 11; ++i)
	{
		srcV1.push_back(i);
		srcV2.push_back(i);
	}
	intV1.insert(intV1.begin(), 42);
	intV2.insert(intV2.begin(), 42);
	intV1.insert(intV1.end(), 21);
	intV2.insert(intV2.end(), 21);
	intV1.insert(intV1.begin(), 999);
	intV2.insert(intV2.begin(), 999);
	intV1.insert(intV1.begin() + 1, 3, 777);
	intV2.insert(intV2.begin() + 1, 3, 777);
	intV1.insert(intV1.begin(), srcV1.begin(), srcV1.end());
	intV2.insert(intV2.begin(), srcV2.begin(), srcV2.end());
	check("intV1 == intV2", intV1 == intV2);
}

// static void resize(void)
// {
// 	print_header("Resize");
// 	ft::vector<std::string> v1;
// 	std::vector<std::string> v2;
// 	v1.resize(10, "test");
// 	v2.resize(10, "test");
// 	check("v1 == v2", (v1 == v2));
// 	v1.resize(2, "42");
// 	v2.resize(2, "42");
// 	check("v1 == v2", (v1 == v2));
// }

// static void assign(void)
// {
// 	print_header("Assign");
// 	std::string test[] = {"Hey", "what's", "up", "?"};
// 	ft::vector<std::string> v1;
// 	std::vector<std::string> v2;
// 	v1.assign(test, test + 4);
// 	v2.assign(test, test + 4);
// 	check("v1 == v2", v1 == v2);
// 	v1.assign(10, "?");
// 	v2.assign(10, "?");
// 	check("v1 == v2", v1 == v2);
// }

// static void erase(void)
// {
// 	print_header("Erase / Clear");
// 	std::string test[] = {"Hey", "what's", "up", "?"};
// 	ft::vector<std::string> v1;
// 	std::vector<std::string> v2;
// 	v1.assign(test, test + 4);
// 	v2.assign(test, test + 4);
// 	v1.erase(v1.begin() + 2);
// 	v2.erase(v2.begin() + 2);
// 	check("v1 == v2", v1 == v2);
// 	v1.clear();
// 	v2.clear();
// 	check("v1 == v2", v1 == v2);
// }

// static void swap(void)
// {
// 	print_header("Swap");
// 	ft::vector<int> v1;
// 	std::vector<int> v2;
// 	ft::vector<int> v3;
// 	std::vector<int> v4;
// 	v1.push_back(1);
// 	v1.push_back(2);
// 	v1.push_back(3);
// 	v2.push_back(1);
// 	v2.push_back(2);
// 	v2.push_back(3);
// 	v3.push_back(42);
// 	v3.push_back(43);
// 	v4.push_back(42);
// 	v4.push_back(43);
// 	v1.swap(v3);
// 	v2.swap(v4);
// 	check("v1 == v2", v1 == v2);
// 	check("v3 == v4", v3 == v4);
// }

// static void operators(void)
// {
// 	print_header("Operators");
// 	ft::vector<int> v1;
// 	std::vector<int> v2;
// 	ft::vector<int> v3;
// 	std::vector<int> v4;
// 	v1.push_back(1);
// 	v1.push_back(2);
// 	v1.push_back(3);
// 	v2.push_back(1);
// 	v2.push_back(2);
// 	v2.push_back(3);
// 	v3 = v1;
// 	v4 = v2;
// 	check("v1 == v2", (v1 == v3), (v2 == v4));
// 	check("v1 != v2", (v1 != v3), (v2 != v4));
// 	check("v1 > v2", (v1 > v3), (v2 > v4));
// 	check("v1 < v2", (v1 < v3), (v2 < v4));
// 	check("v1 >= v2", (v1 >= v3), (v2 >= v4));
// 	check("v1 <= v2", (v1 <= v3), (v2 <= v4));
// 	v1.push_back(42);
// 	v2.push_back(42);
// 	check("v1 == v2", (v1 == v3), (v2 == v4));
// 	check("v1 != v2", (v1 != v3), (v2 != v4));
// 	check("v1 > v2", (v1 > v3), (v2 > v4));
// 	check("v1 < v2", (v1 < v3), (v2 < v4));
// 	check("v1 >= v2", (v1 >= v3), (v2 >= v4));
// 	check("v1 <= v2", (v1 <= v3), (v2 <= v4));
// 	v3.push_back(43);
// 	v4.push_back(43);
// 	check("v1 == v2", (v1 == v3), (v2 == v4));
// 	check("v1 != v2", (v1 != v3), (v2 != v4));
// 	check("v1 > v2", (v1 > v3), (v2 > v4));
// 	check("v1 < v2", (v1 < v3), (v2 < v4));
// 	check("v1 >= v2", (v1 >= v3), (v2 >= v4));
// 	check("v1 <= v2", (v1 <= v3), (v2 <= v4));
// }

void	test_vector(void)
{
	print_header("Vector");

	default_constructor();
	copy_constructor();
	access_operator();
	access_front_back_data();
	capacity();

	insert();


	// assign();
	// erase();
	// resize();
	// swap();
	// operators();
}
#include "./../includes/autotests.hpp"

// template <typename T>
// static void print_vector(T vec, std::string type)
// {
// 	typename T::iterator it;

// 	std::cout << BOLD << type << ", size: " << vec.size() << ", empty: " << vec.empty() << ", capacity: " << vec.capacity() << RESET << std::endl;
// 	it = vec.begin();
// 	while (it != vec.end())
// 	{
// 		std::cout << "'" <<*it << "'";
// 		if (it + 1 != vec.end())
// 			std::cout << " - ";
// 		++it;
// 	}
// 	std::cout << std::endl;
// }

// template <typename T>
// static void print_vector_reverse(T vec, std::string type)
// {
// 	typename T::iterator it;

// 	std::cout << BOLD << type << ", size: " << vec.size() << ", empty: " << vec.empty() << ", capacity: " << vec.capacity() << RESET << std::endl;
// 	it = vec.rbegin();
// 	while (it != vec.rend())
// 	{
// 		std::cout << *it;
// 		if (it + 1 != vec.rend())
// 			std::cout << " - ";
// 		++it;
// 	}
// 	std::cout << std::endl;
// }

template <typename T>
static bool	operator==(ft::vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return false;
	if (a.empty() != b.empty())
		return false;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
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
	{
		ft::vector<double>	doubleSrcV1;
		std::vector<double>	doubleSrcV2;
		check("doubleSrcV1 == doubleSrcV2", doubleSrcV1 == doubleSrcV2);
		for (size_t i = 0; i < 10; ++i)
		{
			doubleSrcV1.push_back(i * 1.1);
			doubleSrcV2.push_back(i * 1.1);
		}
		check("doubleSrcV1 == doubleSrcV2", doubleSrcV1 == doubleSrcV2);
		ft::vector<double>	doubleV1(doubleSrcV1.begin() + 1, doubleSrcV1.end() - 2);
		std::vector<double>	doubleV2(doubleSrcV2.begin() + 1, doubleSrcV2.end() - 2);
		check("doubleV1 == doubleV2", doubleV1 == doubleV2);
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

static void	assignment_operator()
{
	print_header("Assignment  operator");
	{
		ft::vector<int>		intV1;
		std::vector<int>	intV2;
		for (int i = -5 ; i < 6; ++i)
		{
			intV1.push_back(i);
			intV2.push_back(i);
		}
		ft::vector<int> 	copyIntV1 = intV1;
		std::vector<int> 	copyIntV2 = intV2;
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
		ft::vector<std::string> 	copyStrV1 = strV1;
		std::vector<std::string> 	copyStrV2 = strV2;
		strV1.push_back("newStr");
		strV2.push_back("newStr");
		check("strV1 == strV2", (strV1 == strV2));
		check("copyStrV1 == copyStrV2", (copyStrV1 == copyStrV2));
		check("strV1 != copyStrV1", (strV1 != copyStrV1));
		check("strV2 != copyStrV2", (strV2 != copyStrV2));
	}
}

static void	assign()
{
	print_header("Assign");
	{
		ft::vector<int>		intV1;
		std::vector<int>	intV2;
		for (int i = -5 ; i < 6; ++i)
		{
			intV1.push_back(i);
			intV2.push_back(i);
		}
		ft::vector<int> 	copyIntV1 = intV1;
		std::vector<int> 	copyIntV2 = intV2;
		check("intV1 == intV2", (intV1 == intV2));
		check("copyIntV1 == copyIntV2", (copyIntV1 == copyIntV2));
		intV1.assign(5, 11);
		intV2.assign(5, 11);
		check("intV1 == intV2", (intV1 == intV2));
		intV1.assign(copyIntV1.begin(), copyIntV1.end());
		intV2.assign(copyIntV2.begin(), copyIntV2.end());
		check("intV1 == intV2", (intV1 == intV2));
	}
	{
		ft::vector<std::string>		strV1;
		std::vector<std::string>	strV2;
		for (int i = -5 ; i < 6; ++i)
		{
			strV1.push_back("str");
			strV2.push_back("str");
		}
		ft::vector<std::string> 	copyStrV1 = strV1;
		std::vector<std::string> 	copyStrV2 = strV2;
		check("strV1 == strV2", (strV1 == strV2));
		check("copyStrV1 == copyStrV2", (copyStrV1 == copyStrV2));
		strV1.assign(5, "new_str");
		strV2.assign(5, "new_str");
		check("strV1 == strV2", (strV1 == strV2));
		strV1.assign(copyStrV1.begin(), copyStrV1.end());
		strV2.assign(copyStrV2.begin(), copyStrV2.end());
		check("strV1 == strV2", (strV1 == strV2));
	}
}

static void access_operator()
{
	print_header("Access: at(),  operator []");
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

static void	clear()
{
	print_header("Clear ");
	{
		ft::vector<int>		intV1;
		std::vector<int>	intV2;
		for (int i = 0; i < 11; ++i)
		{
			intV1.push_back(i);
			intV2.push_back(i);
		}
		check("intV1 == intV2", intV1 == intV2);
		check("intV1.size() == intV2.size()", intV1.size() == intV2.size());
		check("intV1.capacity() == intV2.capacity()", intV1.capacity() == intV1.capacity());
		intV1.clear();
		intV2.clear();
		check("intV1 == intV2", intV1 == intV2);
		check("intV1.size() == intV2.size()", intV1.size() == intV2.size());
		check("intV1.capacity() == intV2.capacity()", intV1.capacity() == intV1.capacity());
	}
	{
		ft::vector<std::string>		strV1;
		std::vector<std::string>	strV2;
		for (int i = 0; i < 11; ++i)
		{
			strV1.push_back("str");
			strV2.push_back("str");
		}
		check("strV1 == strV2", strV1 == strV2);
		check("strV1.size() == strV2.size()", strV1.size() == strV2.size());
		check("strV1.capacity() == strV2.capacity()", strV1.capacity() == strV2.capacity());
		strV1.clear();
		strV2.clear();
		check("strV1 == strV2", strV1 == strV2);
		check("strV1.size() == strV2.size()", strV1.size() == strV2.size());
		check("strV1.capacity() == strV2.capacity()", strV1.capacity() == strV2.capacity());
	}
}

static void	insert()
{
	print_header("Insert");
	{
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
		intV1.insert(intV1.end(), 2, 666);
		intV2.insert(intV2.end(), 2, 666);
		intV1.insert(intV1.begin(), srcV1.begin(), srcV1.end());
		intV2.insert(intV2.begin(), srcV2.begin(), srcV2.end());
		check("intV1 == intV2", intV1 == intV2);
	}
	{
		ft::vector<std::string>		srcV1;
		std::vector<std::string>	srcV2;
		ft::vector<std::string>		strV1;
		std::vector<std::string>	strV2;
		for (int i = 0; i < 11; ++i)
		{
			srcV1.push_back("str");
			srcV2.push_back("str");
		}
		strV1.insert(strV1.begin(), "42");
		strV2.insert(strV2.begin(), "42");
		strV1.insert(strV1.end(), "21");
		strV2.insert(strV2.end(), "21");
		strV1.insert(strV1.begin(), "999");
		strV2.insert(strV2.begin(), "999");
		strV1.insert(strV1.begin() + 1, 3, "777");
		strV2.insert(strV2.begin() + 1, 3, "777");
		strV1.insert(strV1.end(), 2, "666");
		strV2.insert(strV2.end(), 2, "666");
		strV1.insert(strV1.begin(), srcV1.begin(), srcV1.end());
		strV2.insert(strV2.begin(), srcV2.begin(), srcV2.end());
		check("strV1 == strV2", strV1 == strV2);
	}
}

static void erase()
{
	print_header("Erase ");
	{
		ft::vector<int>		intV1;
		std::vector<int>	intV2;
		for (int i = 0; i < 11; ++i)
		{
			intV1.push_back(i);
			intV2.push_back(i);
		}
		check("intV1 == intV2", intV1 == intV2);
		intV1.erase(intV1.begin() + 1);
		intV2.erase(intV2.begin() + 1);
		intV1.erase(intV1.begin() + 5);
		intV2.erase(intV2.begin() + 5);
		intV1.erase(intV1.begin() + 2, intV1.end() - 4);
		intV2.erase(intV2.begin() + 2, intV2.end() - 4);
		check("intV1 == intV2", intV1 == intV2);
	}
	{
		ft::vector<std::string>		strV1;
		std::vector<std::string>	strV2;
		for (int i = 0; i < 11; ++i)
		{
			strV1.push_back("str");
			strV2.push_back("str");
		}
		check("strV1 == strV2", strV1 == strV2);
		strV1.erase(strV1.begin() + 1);
		strV2.erase(strV2.begin() + 1);
		strV1.erase(strV1.begin() + 5);
		strV2.erase(strV2.begin() + 5);
		strV1.erase(strV1.begin() + 2, strV1.end() - 4);
		strV2.erase(strV2.begin() + 2, strV2.end() - 4);
		check("strV1 == strV2", strV1 == strV2);
	}
	{
		ft::vector<std::string>		strV1;
		std::vector<std::string>	strV2;
		strV1.push_back("str");
		strV2.push_back("str");
		check("strV1 == strV2", strV1 == strV2);
		strV1.erase(strV1.begin());
		strV2.erase(strV2.begin());
		check("strV1 == strV2", strV1 == strV2);
	}
	{
		ft::vector<std::string>		strV1;
		std::vector<std::string>	strV2;
		strV1.push_back("str");
		strV2.push_back("str");
		check("strV1 == strV2", strV1 == strV2);
		strV1.erase(strV1.begin(), strV1.begin());
		strV2.erase(strV2.begin(), strV2.begin());
		check("strV1 == strV2", strV1 == strV2);
	}
	// {
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
}

static void	push_back_pop_back()
{
	print_header("Push_back Pop_back");
	{
		ft::vector<int>		intV1;
		std::vector<int>	intV2;
		for (int i = -5; i < 6; ++i)
		{
			intV1.push_back(i);
			intV2.push_back(i);
		}
		check("intV1 == intV2", intV1 == intV2);
		check("intV1.size() == intV2.size()", intV1.size() == intV2.size());
		check("intV1.capacity() == intV2.capacity()", intV1.capacity() == intV2.capacity());
		for (int i = 0; i < 6; ++i)
		{
			intV1.pop_back();
			intV2.pop_back();
		}
		check("intV1 == intV2", intV1 == intV2);
		check("intV1.size() == intV2.size()", intV1.size() == intV2.size());
		check("intV1.capacity() == intV2.capacity()", intV1.capacity() == intV2.capacity());
	}
	{
		ft::vector<std::string>		strV1;
		std::vector<std::string>	strV2;
		for (int i = -5; i < 6; ++i)
		{
			strV1.push_back("str");
			strV2.push_back("str");
		}
		check("strV1 == strV2", strV1 == strV2);
		check("strV1.size() == strV2.size()", strV1.size() == strV2.size());
		check("strV1.capacity() == strV2.capacity()", strV1.capacity() == strV2.capacity());
		for (int i = 0; i < 6; ++i)
		{
			strV1.pop_back();
			strV2.pop_back();
		}
		check("strV1 == strV2", strV1 == strV2);
		check("strV1.size() == strV2.size()", strV1.size() == strV2.size());
		check("strV1.capacity() == strV2.capacity()", strV1.capacity() == strV2.capacity());
	}
}

static void resize()
{
	print_header("Resize");
	{
		ft::vector<std::string>		strV1;
		std::vector<std::string>	strV2;
		strV1.resize(10, "test");
		strV2.resize(10, "test");
		check("strV1 == strV2", strV1 == strV2);
		check("strV1.size() == strV2.size()", strV1.size() == strV2.size());
		check("strV1.capacity() == strV2.capacity()", strV1.capacity() == strV2.capacity());
		strV1.resize(2, "42");
		strV2.resize(2, "42");
		check("strV1 == strV2", strV1 == strV2);
		check("strV1.size() == strV2.size()", strV1.size() == strV2.size());
		check("strV1.capacity() == strV2.capacity()", strV1.capacity() == strV2.capacity());
	}
}

static void	swap()
{
	print_header("Swap");
	{
		ft::vector<int>		v1, v3;
		std::vector<int>	v2, v4;
		for (int i = 1; i < 6; ++i)
		{
			v1.push_back(i);
			v2.push_back(i);
		}
		for (int i = 144; i < 160; ++i)
		{
			v3.push_back(i);
			v4.push_back(i);
		}
		check("v1 == v2", v1 == v2);
		check("v3 == v4", v3 == v4);
		v1.swap(v3);
		v2.swap(v4);
		check("v1 == v2", v1 == v2);
		check("v3 == v4", v3 == v4);
	}
}

static void operators()
{
	print_header("Operators");
	{
		ft::vector<int>		v1, v3;
		std::vector<int>	v2, v4;
		for (int i = 1; i < 4; ++i)
		{
			v1.push_back(i);
			v2.push_back(i);
		}
		v3 = v1;
		v4 = v2;
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		v1.push_back(142);
		v2.push_back(142);
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		v3.push_back(1443);
		v4.push_back(1443);
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
	}
	{
		ft::vector<std::string>		v1, v3;
		std::vector<std::string>	v2, v4;
		v1.push_back("str1");
		v2.push_back("str1");
		v3 = v1;
		v4 = v2;
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		v1.push_back("142");
		v2.push_back("142");
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		v3.push_back("1443");
		v4.push_back("1443");
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
	}
}

static void	ft_std_swap()
{
	print_header("Std_swap");
	{
		ft::vector<int>		v1, v3;
		std::vector<int>	v2, v4;
		for (int i = 1; i < 6; ++i)
		{
			v1.push_back(i);
			v2.push_back(i);
		}
		for (int i = 144; i < 160; ++i)
		{
			v3.push_back(i);
			v4.push_back(i);
		}
		check("v1 == v2", v1 == v2);
		check("v3 == v4", v3 == v4);
		ft::swap(v1, v3);
		std::swap(v2, v4);
		check("v1 == v2", v1 == v2);
		check("v3 == v4", v3 == v4);
	}
}

void	test_vector()
{
	print_header("Vector");

	default_constructor();
	copy_constructor();
	assignment_operator();
	assign();
	access_operator();
	access_front_back_data();
	capacity();
	clear();
	insert();
	erase();
	push_back_pop_back();
	resize();
	swap();
	operators();
	ft_std_swap();
}
#include "./../includes/autotests.hpp"

static void	default_constructor()
{
	print_header("Constructor");
	{
		ft::stack<int>  intS1;
		std::stack<int> intS2;
		check("intS1.size() == intS2.size()", intS1.size() == intS2.size());
		check("intS1.empty() == intS2.empty()", intS1.empty() == intS2.empty());
    }
	{
		ft::stack<std::string>	srcS1;
		std::stack<std::string>	srcS2;
		srcS1.push("one");
		srcS1.push("two");
		srcS1.push("three");
		srcS2.push("one");
		srcS2.push("two");
		srcS2.push("three");
		ft::stack<std::string>	strS1(srcS1);
		std::stack<std::string>	strS2(srcS2);
		ft::stack<std::string>	strS3 = srcS1;
		std::stack<std::string>	strS4 = srcS2;
		check("strS1 == srcS1", strS1 == srcS1);
		check("strS3 == srcS1", strS3 == srcS1);
		check("strS2 == srcS2", strS2 == srcS2);
		check("strS4 == srcS2", strS4 == srcS2);
	}
}

static void	top_push_back()
{
	print_header("Top / Push / Pop");
	{
		ft::stack<int>	intS1;
		std::stack<int>	intS2;
		for (int i = 0; i < 4; ++i)
		{
			intS1.push(i);
			intS2.push(i);
		}
		check("intS1.size() == intS2.size()", intS1.size() == intS2.size());
		check("intS1.empty() == intS2.empty()", intS1.empty() == intS2.empty());
		check("intS1.top() == intS2.top()", intS1.top() == intS2.top());
		intS1.pop();
		intS2.pop();
		check("intS1.size() == intS2.size()", intS1.size() == intS2.size());
		check("intS1.top() == intS2.top()", intS1.top() == intS2.top());
		intS1.pop();
		intS2.pop();
		check("intS1.size() == intS2.size()", intS1.size() == intS2.size());
		check("intS1.top() == intS2.top()", intS1.top() == intS2.top());
	}
}

static void operators()
{
	print_header("Operators");
	{
		ft::stack<int>	v1, v3;
		std::stack<int>	v2, v4;
		for (int i = 1; i < 4; ++i)
		{
			v1.push(i);
			v2.push(i);
		}
		v3 = v1;
		v4 = v2;
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		v1.push(142);
		v2.push(142);
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		v3.push(1443);
		v4.push(1443);
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
	}
	{
		ft::stack<std::string>	v1, v3;
		std::stack<std::string>	v2, v4;
		v1.push("str1");
		v2.push("str1");
		v3 = v1;
		v4 = v2;
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		v1.push("142");
		v2.push("142");
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		v3.push("1443");
		v4.push("1443");
		check("v1 == v2", (v1 == v3) == (v2 == v4));
		check("v1 != v2", (v1 != v3) == (v2 != v4));
		check("v1 > v2", (v1 > v3) == (v2 > v4));
		check("v1 < v2", (v1 < v3) == (v2 < v4));
		check("v1 >= v2", (v1 >= v3) == (v2 >= v4));
		check("v1 <= v2", (v1 <= v3) == (v2 <= v4));
	}
}

void test_stack(void)
{
	print_header("Stack ");

	default_constructor();
	top_push_back();
	operators();
}

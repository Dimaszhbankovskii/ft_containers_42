#include "./../includes/autotests.hpp"

int	main(int argc, char **argv)
{
	std::string	nameTest;

	if (argc != 2)
	{
		std::cout << "No test given, testing vector." << std::endl;
		nameTest = "vector";
	}
	else
		nameTest = std::string(argv[1]);

	if (nameTest == "vector")
		test_vector();
	else
		std::cout << "No test for " << nameTest << std::endl;

	// else if (choice == "list")
	// 	test_list();
	// else if (choice == "map")
	// 	test_map();
	// else if (choice == "stack")
	// 	test_stack();
	// else if (choice == "queue")
	// 	test_queue();
	// else if (choice == "all")
	// {
	// 	test_vector();
	// 	// test_list();
	// 	// test_map();
	// 	// test_stack();
	// 	// test_queue();
	// }
	// else
	// 	std::cout << "No test for " << choice << std::endl;

	return (0);
}

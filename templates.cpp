#include <iostream>
#include "Sources/templates.hpp"
#include <string>

int main(int argc, char **argv)
{
	std::cout << sfy::compare(1, 0) << std::endl;

	std::string s1 = "hello", s2 = "no hello";
	std::cout << sfy::compare(s1, s2) << std::endl;

	return EXIT_SUCCESS;
}

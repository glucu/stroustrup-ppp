#include <iostream>
#include <string>
#include <exception>

/* Chapter 17: exercise 3
 *
 * Write a function, void to_lower(char* s), that replaces all uppercase 
 * characters in the C-style string s with their lowercase equivalents. For 
 * example, Hello, World! becomes hello, world!. Do not use any standard library 
 * functions. A C-style string is a zero-terminated array of characters. So if you 
 * find a char with the value 0 you are at the end.
 */

void to_lower(char *s)
{ // converts all uppercase characters to lowercase
  // pre-condition: s must not be null.
  
	if (!s) return;

	for (int i{}; s[i]; ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;
		}
	}
}

const std::string kQuit{ "quit" };

int main() 
{
	try {

		std::cout << "Enter words followed by \'" << kQuit << "\' to quit.\n";
		std::string test;
		while (std::getline(std::cin,test) && test != kQuit) {

			to_lower(&test[0]);
			std::cout << test << '\n';
		}
		
		return 0;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		std::cerr << "someting went wrong.\n";
		return 2;
	}
}
#include "../include/std_lib_facilities.h"

/* Chapter 10: exercise 11
 *
 * Write a program that produces the sum of all the whitespace-separated
 * integers in a text file. For example, "bears: 17 elephants 9 end" should
 * output 26.
 */ 

int sum(std::istream &ist) {

	int total{};
	int i{};
	char ch{' '};
	std::string word;
	while(ist >> ch) {
		if(std::isdigit(ch)) {
			ist.unget();

			if(ist >> i) {
				if (ist.eof() || ist.get(ch) && std::isspace(ch)) {
					total += i;
				}
				else {
					ist.unget();
					ist >> word;
				}
			}
			else {
				error("Did not enter an integer");
			}
		}
		else {
			ist.unget();
            ist >> word;
		}
	}

	return total;
}

int read_file(const std::string &file_name) {

	std::ifstream ist{file_name};
	if(ist.fail()) error("can't open file, ", file_name);
	ist.exceptions(ist.exceptions() | std::ios_base::badbit);

	int total{ sum(ist) };
	return total;
}

int main() {

	try {

		const std::string file_name{"exercise11_input"};

		int total{ read_file(file_name) };

		std::cout << "The sum of integers is: " << total << '\n';

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Exception: something went wrong\n";
        return 2;
    }
}
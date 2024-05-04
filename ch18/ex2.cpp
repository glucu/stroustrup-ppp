#include <cstring>
#include <iostream>
#include <limits>
#include <stdexcept>

/*
 * COMMENT:
 * Shall we practice pointer arithmetic here? Of course...
 */

char* findx(const char *s, const char *x)
// return the first occurrence of x in s
// pre-condition: return NULL if s or x are nullptr
{
	if(!x || !s) return nullptr;

	for(size_t i{}; *(s+i); ++i) {
		if(*(s+i) == *x) {
			size_t k{1};
			for(size_t j{i+1}; *(s+j) && *(x+k); ++j) {
				char ch1 = *(s+j);
				char ch2 = *(x+k);
				if(ch1 != ch2) break;
				++k;
			}
			if(!(*(x+k))) {
				char *x_cpy = new char[k+1];
				for(size_t ii{i}, kk{}; *(x+kk); ++ii, ++kk)
					*(x_cpy+kk) = *(s+ii);
				*(x_cpy+k) = '\0';
				return x_cpy;
			}
		}
	}
	return nullptr;
}

void ignore_line()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

const std::string kQuit{"q!"};

int main()
{
    try {

		std::cout << "Please enter the main string (s) followed by a substring "
			      << "to find (x) (Enter " << kQuit << " to quit):\n";
		while(true) {
			std::string haystack, needle;
			std::getline(std::cin, haystack);
			if(haystack == kQuit) break;
			std::cin >> needle;

			const char *s = haystack.c_str();
			const char *x = needle.c_str();

			char *result = findx(s,x);

			if(result) {
				std::cout << "substring " << result << " found in position " << (std::strstr(s, x) - s + 1) << '\n';
			}
			else {
				std::cout << "substring " << x << " not found in main string s.\n";
			}

			std::cout << "\nTry again:\n";

			delete[] result;
			ignore_line(); // to discard the newline cin leaves in the buffer
		}

        return 0;
    }
    catch(const std::exception &e) {
		std::cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
		std::cerr << "Oops: something went wrong\n";
        return 2;
    }
} 

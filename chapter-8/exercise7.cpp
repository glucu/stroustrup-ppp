#include "../include/std_lib_facilities.h"

/* Chapter 8: exercise 7
 *
 * Read five names into a vector<string> name, then prompt the user for the
 * ages of the people named and store the ages in a vector<double> age. Then
 * print out the five (name[i],age[i]) pairs. Sort the names (sort(name.begin(),
 * name.end())) and print out the (name[i],age[i]) pairs. The tricky part here
 * is to get the age vector in the correct order to match the sorted name
 * vector. Hint: Before sorting age, take a copy and use that to make a copy of
 * age in the right order after sorting age. Then, do that exercise again but allowing an arbitrary number of names. 
 */

constexpr int max_name{5};

bool is_in(std::vector<std::string> &vs, const std::string &name) {
// checks if string name is already in  vector vs

    for(const auto &n : vs) {
        if(n == name) return true;
    }
    return false;
}

void read_names(std::vector<std::string> &name) {
// prompts the user to enter five names
// checks to see if name already exits.

    std::string n;
    for(int start{}; start < max_name; ++start) {
        std::cout << ">> ";
        std::cin >> n;
        if(is_in(name, n)) {
            std::cout << "Sorry, " << n << " is already present. Try again:\n";
            --start;
        }
        else {
            name.push_back(n);
        }
    }
}

void ignoreLine() {

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void read_ages(const std::vector<std::string> &name, std::vector<double> &age) {
// reads in the ages for each person in name

    for(size_t i{}; i < name.size(); ++i) {
        std::cout << name[i] << " age: ";
        double a{};
        std::cin >> a;
        if(std::cin.fail()) {
            std::cin.clear();
            ignoreLine();
            std::cout << "Sorry, " << a << " is not an age. Try again:\n";
            --i;
        }
        else {
            age.push_back(a);
        }

    }
}

void sort_names(std::vector<std::string> &name, std::vector<double> &age) {
// sorts the name and age vectors so the age vector is in the right order
// after sorting names.

    std::vector<std::string> temp_names{ name };
	std::vector<double> temp_ages{ age };

	std::sort(name.begin(), name.end());
	
	for (size_t i{}; i < name.size(); ++i) {
		for (size_t j{}; j < name.size(); ++j) {

			if (name[i] == temp_names[j])
				age[i] = temp_ages[j];
		}
	}
}

void print_pairs(const std::vector<std::string> &name, const std::vector<double> &age) {
// prints the name of the person followed by their age in a seperate line.

    for(size_t i{}; i < name.size(); ++i) {
        std::cout << name[i] << " is " << age[i]
                  << " years old.\n";
    }
}

int main() {

    try {

        std::cout << "Please enter five names.\n";
        std::vector<std::string> name;
        read_names(name);

        std::vector<double> age;
        read_ages(name, age);

        std::cout << "\nHere are the name and age pair in unsorted order:\n";
        print_pairs(name, age); std::cout << '\n';

        std::cout << "Now, here are the names in sorted order:\n";
        sort_names(name, age);
        print_pairs(name, age);

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
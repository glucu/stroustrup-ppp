#include "../include/std_lib_facilities.h"

/* Chapter 8: exercise 8
 *
 * Then, do exercise 7 again but allowing an arbirary number of names
 */

const std::string quit{"quit"};

bool is_in(std::vector<std::string> &vs, const std::string &name) {
// checks if string name is already in  vector vs

    for(const auto &n : vs) {
        if(n == name) return true;
    }
    return false;
}

void read_names(std::vector<std::string> &name) {
// prompts the user to enter an arbitary number of names
// checks to see if name already exits.

    std::string n;
    while(true) {

        std::cout << ">> ";
        std::cin >> n;
        if(n == quit) return;

        if(is_in(name, n)) {
            std::cout << "Sorry, " << n << " is already present. Try again:\n";
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

        std::cout << "Please enter the names of people.\n";
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
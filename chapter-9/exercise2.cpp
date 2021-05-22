#include "../include/std_lib_facilities.h"

/* Chapter 9: exercise 2
 *
 * Design and implement a Name_pairs class holding (name,age) pairs where
 * name is a string and age is a double. Represent that as a vector<string>
 * (called name) and a vector<double> (called age) member. Provide an
 * input operation read_names() that reads a series of names. Provide a
 * read_ages() operation that prompts the user for an age for each name.
 * Provide a print() operation that prints out the (name[i],age[i]) pairs (one
 * per line) in the order determined by the name vector. Provide a sort() operation 
 * that sorts the name vector in a1phabetical order and reorganizes the age vector to match. 
 * Implement all "operations" as member functions. Test the class (of course: test early and often).
 */

class Name_pairs {
public:
  // the default copy operations are fine

  const std::vector<std::string>& get_name() const { return name; }
  const std::vector<double>& get_age() const { return age; };

  void read_names();                         // reads a series of names
  void read_ages();                          // reads an age for each name
  void print() const;                        // print (name,age) pairs
  void sort();                               // sorts the name vector in alphabetical order

private:
  const std::string quit{"quit"};
  std::vector<std::string> name;
  std::vector<double> age;

  bool is_in(const std::string &n) const;    // is n already in name? 
};

bool Name_pairs::is_in(const std::string &n) const {
// checks to see if n is already in name vector

  for(const auto &s: name) {
    if(n == s) return true;
  }

  return false;
}

void Name_pairs::read_names() {
// reads a series of names into name vector
// until user enters "quit" to stop.
// condition: No duplicates are to exist.

  std::cout << "Read a series of names (followed by quit to stop).\n";
  std::cout << ">>";
  for(std::string n; std::cin >> n && n != quit;) {

    if(is_in(n)) {
      std::cout << "Sorry, " << n << " is already entered. Try again:\n";
    }    
    else {
      name.push_back(n);
    }

    std::cout << ">>";
  }
}

void ignoreLine() {
  
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Name_pairs::read_ages() {
// reads an age for each name in name vector

  for(size_t i{}; i < name.size(); ++i) {

    std::cout << "Enter " << name[i] << "'s age: ";
    double a{};
    std::cin >> a;
    if(std::cin.fail()) {
      std::cin.clear();
      ignoreLine();
      std::cout << "Sorry, but " << a << " is not an age. Try again:\n";
      --i;
    }
    else {
      age.push_back(a);
    }
  }
}

void Name_pairs::sort() {
// sort name vector alphabetically with matching age
// pre-condition: vectors must be the same size

  std::vector<std::string> tmp_n{ name };
	std::vector<double> tmp_d{ age };

	std::sort(tmp_n.begin(), tmp_n.end());

	for(size_t i{}; i < name.size(); ++i) {

		for(size_t n{}; n < age.size(); ++n) {

			if(tmp_n[i] == name[n])
				tmp_d[i] = age[n];
		}
	}
  
  name = tmp_n;
	age  = tmp_d;
}

void Name_pairs::print() const {
// prints out the name-age pairs in
// (name,age) format.

  for(size_t i{}; i < name.size(); ++i) {
    std::cout << '(' << name[i] << ',' << age[i] << ")\n";
  }
}

int main() {

  try {

    Name_pairs pairs{};
    pairs.read_names();
    pairs.read_ages();

    std::cout << "\nHere are the names unsorted:\n";
    pairs.print();

    pairs.sort();
    std::cout << "\nHere are the names sorted:\n";
    pairs.print();

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
#include "../include/std_lib_facilities.h"

/* Chapter 9: exercise 3
 *
 * Replace Name_pair::print() with a (globa1) operator<< and define ==
 * and != for Name_pairs.
 */

class Name_pairs {
public:
  // the default copy operations are fine

  const std::vector<std::string>& get_name() const { return name; }
  const std::vector<double>& get_age() const { return age; };

  void read_names();                         // reads a series of names
  void read_ages();                          // reads an age for each name
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

   if(name.size() != age.size()) {
     error("Name_pairs::sort(): pre-condition violated");
   }

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

// helper functions
std::ostream& operator<<(std::ostream &os, const Name_pairs &pairs) {

    for(size_t i{}; i < pairs.get_name().size(); ++i) {
      os << '(' << pairs.get_name()[i] << ',' << pairs.get_age()[i]
         << ')';
    }

    return os;
}

bool operator==(const Name_pairs &a, const Name_pairs &b) {

    return (a.get_name() == b.get_name() && a.get_age() == b.get_age());
}

bool operator!=(const Name_pairs &a, const Name_pairs &b) {

    return !(a == b);
}

int main() {

  try {

    Name_pairs pairs{};
    pairs.read_names();
    pairs.read_ages();

    std::cout << "\nHere are the names unsorted:\n";
    std::cout << pairs << '\n';

    pairs.sort();
    std::cout << "\nHere are the names sorted:\n";
    std::cout << pairs << "\n\n";

    Name_pairs other{};
    other.read_names();
    other.read_ages();
    other.sort();
    
    std::cout << ((pairs == other) ? "\nThe same kind of people!\n" : "\nThese are new faces I see!\n");

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
#include "std_lib_facilities.h"

class Name_pairs {
public:
    Name_pairs() {}

    void read_names();
    void read_ages();
    void sort();
    void print() const;

private:
    bool is_dup(const string &n) const;
    size_t name_idx(const string &n) const;

private:
    static const string kQuit;

private:
    vector<string> names;
    vector<double> ages;
};

const string Name_pairs::kQuit{"NoName"};

bool Name_pairs::is_dup(const string &name) const
// checks if n is already in names
{
    for(const string &n : names) {
        if(name == n) return true;
    }
    return false;
}

void Name_pairs::read_names()
// reads a series of names
{
    cout << "Please enter a series of names. Type \'" << Name_pairs::kQuit << "\' when you are done:\n";
    for(string name; cin >> name && name != Name_pairs::kQuit;) {
        if(is_dup(name)) cout << name << " already exits. Please enter a different name.\n";
        else {
            names.push_back(name);
        }
    }

    if(cin.eof()) error("read_names: End of file reached");
}

void Name_pairs::read_ages()
// reads a series of ages of each name read in names
// pre-condition: the size of names is not empty
{
    if(names.size() == 0) error("read_ages: no names were read in order to read ages");

    double age{};
    for(const string &n : names) {
        cout << "Enter the age for " << n << ": ";
        cin >> age;
        if(!cin) {
            if(cin.eof()) error("read_ages: End of file reached");
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You did not read a digit for an age. Please try again.\n";
        }
        else {
            ages.push_back(age);
        }
    }
}

size_t Name_pairs::name_idx(const string &n) const
// return the corresponding age index for n
{
    for(size_t i = 0; i != names.size(); ++i) {
        if(n == names[i]) return i;
    }
    error("name_idx: name not found", n);
}

void Name_pairs::sort()
// sort the names in alphabetical order and reorganizes ages
{
    if(names.size() != ages.size()) error("sort: names and ages must be the same sizes");

    vector<string> names_cpy(names);
    vector<double> ages_cpy;

    std::sort(names_cpy.begin(), names_cpy.end());

    for(size_t i = 0; i != names_cpy.size(); ++i) {
        ages_cpy.push_back(ages[name_idx(names_cpy[i])]);

    }
    ages = ages_cpy;
    names = names_cpy;
}

void Name_pairs::print() const
// print the (names[i], ages[i]) pairs
// pre-condition: names.size() == ages.size()
{
    if(names.size() != ages.size()) error("print: names and ages are not the same size");
    for(size_t i = 0; i != names.size(); ++i) {
        cout << '(' << names[i] << ',' << ages[i] << ")\n";
    }
}

int main()
{
    try {
        
        Name_pairs np{};
        np.read_names();
        np.read_ages();
        cout << "Before sorted:\n";
        np.print();

        cout << "After sorted:\n";
        np.sort();
        np.print();
         
        return 0;
    }
    catch(runtime_error &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 

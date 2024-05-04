#include "std_lib_facilities.h"

void drill2(int birth_year)
{
    cout << birth_year << ' ' 
         << hex << birth_year << ' ' 
         << oct << birth_year << '\n';
}

void drill3(int birth_year) 
{
    cout << showbase << dec
         << birth_year << ' '
         << hex << birth_year << ' '
         << oct << birth_year << '\n';
}

void drill4(int birth_year)
{
    cout << showbase << dec 
         << "decimal:\t" << birth_year << '\n'
         << "hexadecimal:\t" << hex << birth_year << '\n'
         << "octal:\t\t" << oct << birth_year << '\n';
}

void drill5(int age)
// interesting. oct still "sticks" in-between
// function calls as well.
{
    cout << age << '\n';
}

void drill67(int age)
{
    cout << showbase << dec 
         << "decimal:\t" << age << '\n'
         << "hexadecimal:\t" << hex << age << '\n'
         << "octal:\t\t" << oct << age << dec << '\n';
}

void drill8()
// input: decimal, octal, followed by two hexadecimal
// output: cout by default coverts and outputs in decimal
{
    int a, b, c, d;
    cin >> dec >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
}

void drill9()
// input: 1234567.89
//
// defaultfloat: might output in scientific notation instead
// fixed: 1234567.890000
// scientific: 1.234568e+06
// It depends on the context. scientific notation is great
// for very large (or very small) numbers that can be better expressed
// in a compact form that is easier to read. The mass of the Earth in kilograms
// is a very "large" number that is better suited to be read in scientific notation. 
// On the other hand, fixed precision (precision is the number of digits after the decimal point)
// is a good choice if precision (the number of digits) matters when it comes to an accurate representation
{
    double d = 1234567.89;
    cout << defaultfloat << d << '\n'
         << fixed << d << '\n'
         << scientific << d << '\n';
}

void drill10()
{
    vector<string> last_names{"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis"};
    vector<string> first_names{"John", "Emma", "Michael", "Sophia", "Matthew", "Olivia"};
    vector<string> phone_numbers{"123-456-7890", "234-567-8901", "345-678-9012", "456-789-0123", "567-890-1234", "678-901-2345"};
    vector<string> email_addresses{"john.smith@example.com", "emma.johnson@example.com", "michael.williams@example.com", "sophia.jones@example.com", "matthew.brown@example.com", "olivia.davis@example.com"};

    cout << setw(15) << "Last Name" << setw(15) << "First Name" << setw(15) << "Telephone" << setw(30) << "Email Address" << '\n';
    cout << setfill('-') << setw(75) << "" << setfill(' ') << '\n';

    for(size_t i{}; i != last_names.size(); ++i) {
        cout << setw(15) << last_names[i] << setw(15) << first_names[i] << setw(15) << phone_numbers[i] << setw(30) << email_addresses[i] << '\n';
    }
}

int main()
{
    try {

        // drill 1
        cout << "Birth Year:\n";
        int birth_year{1996};

        // drill2(birth_year);
        // drill3(birth_year);
        drill4(birth_year);

        cout << "\nAge:\n";

        int age{27};
        // drill5(age);
        drill67(age);

        drill8();
        
        cout << '\n';

        drill9();

        cout << '\n';

        drill10();

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

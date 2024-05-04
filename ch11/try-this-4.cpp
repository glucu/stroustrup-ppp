#include "std_lib_facilities.h"

int main()
{
    try {

        vector<string> last_names{"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis"};
        vector<string> first_names{"John", "Emma", "Michael", "Sophia", "Matthew", "Olivia"};
        vector<string> phone_numbers{"123-456-7890", "234-567-8901", "345-678-9012", "456-789-0123", "567-890-1234", "678-901-2345"};
        vector<string> email_addresses{"john.smith@example.com", "emma.johnson@example.com", "michael.williams@example.com", "sophia.jones@example.com", "matthew.brown@example.com", "olivia.davis@example.com"};

        cout << setw(15) << "Last Name" << setw(15) << "First Name" << setw(15) << "Telephone" << setw(30) << "Email Address" << '\n';
        cout << setfill('-') << setw(75) << "" << setfill(' ') << '\n';

        for(size_t i{}; i != last_names.size(); ++i) {
            cout << setw(15) << last_names[i] << setw(15) << first_names[i] << setw(15) << phone_numbers[i] << setw(30) << email_addresses[i] << '\n';
        }

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

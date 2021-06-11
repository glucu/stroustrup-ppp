#include "../../include/std_lib_facilities.h"

/* Drill 10:
 *
 * Make a simple table including last name, first name, telephone number,
 * and email address for yourself and at least five of your friends. Experiment 
 * with different field widths until you are satisfied that the table is well presented.
 */

struct Contact {

    std::string last_name;
    std::string first_name;
    std::string phone_number;
    std::string email;
};

std::ostream& operator<<(std::ostream &os, const std::vector<Contact> &contacts) {

    using std::setw;
    for(const auto &c : contacts) {
        os << setw(7) << "Name:"  << setw(3)  << "" << c.first_name << " " << c.last_name << "\n"
           << setw(7) << "Phone:" << setw(3)  << "" << c.phone_number << "\n"
           << setw(7) << "Email:" << setw(3)  << "" << c.email        << "\n\n";
    }

    return os;
}

int main() {

    std::vector<Contact> c {
        {"Strickland", "Hamzah", "(???) ???-????", "hamzah.strickland@ppp.com"},
        {"Mejia", "Courtney", "(???) ???-????", "courtney.mejia@ppp.com"},
        {"Palmer", "Theo", "(???) ???-????", "theo.palmer@ppp.com"},
        {"Alexander", "Eugene", "(???) ???-????", "eugene.alexander@ppp.com"},
        {"Mann", "Victor", "(???) ???-????", "victor.mann@ppp.com"}
    };

    std::cout << c << '\n';

    return 0;
}
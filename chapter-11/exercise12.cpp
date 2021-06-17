#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 12
 *
 * Reverse the order of characters in a text file. For example, asdfghjkl becomes lkjhgfdsa.
 * Warning: There is no really good, portable, and efficient way of reading a file backwards.
 */

/* COMMENT:
 * Stroustrup did mention, "Whenever you can, just read and write files from beginning to the end. That's the easiest
 * and least error-prone way." I agree, simply because there is a risk when using file positioning. The fact there is
 * no run-time checking when positioning beyond the end of a file, it is considered an undefined behavior. Operating
 * systems also vary in what happens.
 *
 * So, I will read in the characters from start to end, reverse the characters (using a vector), and write it back
 * to a new file containing the reversed characters.
 */

void reverse_chars(std::vector<char> &vc) {
// reverses the character in vc in-place.

    for(size_t start{}, end{vc.size()-1}; start < end; ++start, --end) {
        char temp{ vc[start] };
        vc[start] = vc[end];
        vc[end] = temp;
    }
}

void write_file(const std::vector<char> &vc, const std::string &oname) {

    std::ofstream ofs{oname.c_str()};
    if(ofs.rdstate() != 0) error("can't open file, ", oname);

    for(const char &ch : vc) {
        ofs << ch;
    }
}

void read_file(std::vector<char> &vc, const std::string &iname) {
// reads in from a file one character at a time into vc

    std::ifstream ifs{iname.c_str()};
    if(ifs.rdstate() != 0) error("can't open file, ", iname);

    char ch{' '};
    while(!ifs.eof() && ifs.get(ch)) {
        vc.push_back(ch);
    }

    if(ifs.eof()) ifs.clear();
    if(ifs.fail()) error("read_file(): failed to extract character.");
}

int main() {

    try {

        std::cout << "Please enter input file name: ";
        std::string iname;
        std::cin >> iname;

        std::vector<char> vc;
        read_file(vc, iname);
        reverse_chars(vc);

        std::cout << "Please enter output file name: ";
        std::string oname;
        std::cin >> oname;

        write_file(vc, oname);

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
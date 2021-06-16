#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 9
 *
 * Split the binary I/O program from §11.3.2 into two: one program that converts an ordinary text file 
 * into binary and one program that reads bi­nary and converts it to text. 
 * Test these programs by comparing a text file with what you get by converting it to binary and back. 
 */

const std::string oname{"exercise9-output.txt"};

void to_binary(const std::string &iname) {
// converts iname file into binary.

    std::ifstream ifs{iname};
    if(ifs.rdstate() != 0) error("can't open file,", iname);
    std::ofstream ofs{oname, std::ios_base::binary};
    if(ofs.rdstate() != 0) error("can't open file,", oname);

    for(char ch; ifs.get(ch);)
        ofs.write(as_bytes(ch), sizeof(ch));
}

std::vector<char> from_binary() {
// reads from binary and converts it to text.

    std::ifstream ifs{oname, std::ios_base::binary};
    if(ifs.rdstate() != 0) error("can't open file,", oname);

    std::vector<char> temp;
    for(char ch; ifs.read(as_bytes(ch), sizeof(ch));)
        temp.push_back(ch);

    return temp;
}

int main() {

    try {

        std::cout << "Please enter input file name: ";
        std::string iname;
        std::cin >> iname;

        to_binary(iname);
        auto vc = from_binary();

        for(const auto &ch : vc) {
            std::cout << ch;
        }

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
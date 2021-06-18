#include "../include/std_lib_facilities.h"

/* Chapter 11: exercise 13
 *
 * Reverse the order of words (defined as whitespace-separated strings) in a file. 
 * For example, Norwegian Blue parrot becomes parrot Blue Norwegian. You are allowed to 
 * assume that all the strings from the file will fit into memory at once.
 */

std::vector<std::string> read_file(const std::string &iname) {

    std::ifstream ifs{iname.c_str()};
    if(ifs.rdstate() != 0) error("can't open file, ", iname);

    std::vector<std::string> temp;
    std::string word;
    while(!ifs.eof()) {

        ifs >> word;
        temp.push_back(word);
    }

    if(ifs.eof()) ifs.clear();
    if(ifs.fail()) error("read_file(): something happen with formatting");

    return temp;
}

void write_file(const std::string &oname, const std::vector<std::string> &vs) {

    std::ofstream ofs{oname.c_str()};
    if(ofs.rdstate() != 0) error("can't open file, ", oname);

    for(size_t i{vs.size()-1}; i >= 0; --i) {
        if(i % 10 == 0) ofs << '\n';
        
        ofs << vs[i] << ' ';
    }
}

int main() {

    try {

        std::cout << "Please enter input file name: ";
        std::string iname;
        std::cin >> iname;

        std::vector<std::string> vs{ read_file(iname) };

        std::cout << "Please enter output file name: ";
        std::string oname;
        std::cin >> oname;

        write_file(oname, vs);

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
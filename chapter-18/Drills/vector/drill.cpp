#include <iostream>
#include <vector>
#include <cstddef>
#include <exception>

/* Chapter 18: vector drill
 *
 */

// #1
std::vector<int> gv{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

// #2
void f(const std::vector<int> &vi) {
// #3

    std::vector<int> lv(vi.size(),0);
    lv = gv;
    for(const auto &val : lv) {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    std::vector<int> lv2{vi};
    for(const auto &val : lv2) {
        std::cout << val << ' ';
    }
    std::cout << '\n';

}

int main() {

    try {

        // #4
        f(gv);

        std::vector<int> vv;
        vv.push_back(1);
        for(std::size_t i{1}; i != 10; ++i)
            vv.push_back((i+1)*vv[i-1]);
        f(vv);

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Something went wrong.\n";
        return 2;
    }
}

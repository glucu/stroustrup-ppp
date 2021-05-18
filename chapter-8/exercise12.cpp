#include "../include/std_lib_facilities.h"

/* Chapter 8: exercise 12
 *
 * Improve print_until_s() from §8.5.2. Test it. What makes a good set of
 * test cases? Give reasons. Then, write a print_until_ss() that prints until it
 * sees a second occurrence of its quit argument.
 * 
 * void print_until_s(vector<string> v, string quit)
 * { 
 *      for(int s : v) {
 *          if(s == quit) return;
 *          cout << s << '\n';
 *      }
 */

/* COMMNET:
 * Improvements:
 * 1. Sice the function only prints the contents of vector v,
 *    both the vector and string should be passed by const reference.
 * 2. Inside the for-range loop, auto will deduce to a string that is marked
 *    const for read only. Like how we want it to be.
 */

void print_until_s(const vector<string> &v, const string &quit) {

    std::cout << "{ ";
    for(const auto &s : v) {
        if(s == quit) return;
        cout << s << ' ';
    }
    cout << " }\n";
}

void print_until_ss(const vector<string> &v, const string &quit) {

    int quit_cnt{};
    std::cout << "{ ";
    for(const auto &s : v) {
        if(s == quit) ++quit_cnt;
        if(quit_cnt == 2) return;
        cout << s << ' ';
    }
    cout << " }\n";
}


int main() {

    vector<string> words{"This", "is", "a", "kind", "of", "test", "but", "will", "it", "only",
                          "print", "to", "this", "line?", "quit", "I'm included for print_until_ss() though ;)", "quit"};
    
    print_until_s(words, "quit");
    std::cout << '\n';
    print_until_ss(words, "quit");

    return 0;
}
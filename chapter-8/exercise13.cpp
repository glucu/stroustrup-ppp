#include "../include/std_lib_facilities.h"

/* Chapter 8: exercise 13
 *
 * Write a function that takes a vector<string> argument and returns a
 * vector<int> containing the number of characters in each string. Also find
 * the longest and the shortest string and the lexicographically first and last
 * string. How many separate functions would you use for these tasks?
 * Why? 
 */

/* COMMENT:
 * "FUNCTIONS SHOULD DO ONE THING. THEY SHOULD DO IT WELL. THEY SHOULD DO IT ONLY" - Robert C. Martin
 * A function should do only one logical thing. For me, That means to have 5 functions for each of the 
 * computations that he listed. 
 */

std::vector<int> get_length_vector(const std::vector<string> &vs) {
// returns a vector<int> containing the number of characters in each string

    std::vector<int> temp;
    for(const auto &s : vs) {
        temp.push_back(s.size());
    }

    return temp;
}

std::vector<std::string> shortest_str(const std::vector<std::string> &vs) {
// finds the shortest string in vs and returns that string
// pre-condition: size of vector "vs" must be at least one

    if(vs.size() == 0) error("longest_str(): pre-condition violated");

    int min = vs[0].size();
    for(size_t i{1}; i < vs.size(); ++i) {
        if(vs[i].size() < min) min = vs[i].size();
    }

    std::vector<std::string> temp;
    for(const auto &s : vs) {
        if(s.size() == min) temp.push_back(s);
    }

    return temp;
}

std::vector<std::string> longest_str(const std::vector<std::string> &vs) {
// finds the the longest string in "vs" and returns that string
// pre-condition: size of vector vs must be at least one

    if(vs.size() == 0) error("longest_str(): pre-condition violated");

    int max = vs[0].size();
    for(size_t i{1}; i < vs.size(); ++i) {
        if(vs[i].size() > max) max = vs[i].size();
    }

    std::vector<std::string> temp;
    for(const auto &s : vs) {
        if(s.size() == max) temp.push_back(s);
    }

    return temp;
}

std::string lexico_first(const std::vector<std::string> &vs) {
// finds and returns the lexicographically first string
// pre-condition: size of vector vs must be at least one

    if(vs.size() == 0) error("lexico_first(): pre-condition violated");

    std::string first{ vs[0] };
    for(const auto &s : vs) {
        if(first > s) first = s;
    }

    return first;
}

std::string lexico_last(std::vector<std::string> &vs) {
// finds and returns the lexicographically first string
// pre-condition: size of vector vs must be at least one

    if(vs.size() == 0) error("lexico_last(): pre-condition violated");

    std::string last{ vs[0] };
    for(const auto &s : vs) {
        if(s > last) last = s;
    }

    return last;
}

void print(const std::vector<std::string> &vs, const std::string &label) {

    std::cout << label << ": { ";
    for(const auto &s : vs) {
        std::cout << s << ' ';
    }
    std::cout << "}\n";
}

void print(const std::vector<int> &vi, const std::string &label) {

    std::cout << label << ": { ";
    for(const auto &s : vi) {
        std::cout << s << ' ';
    }
    std::cout << "}\n";
}

int main() {

    try {

        std::vector<std::string> words{"zero", "one", "two", "three", "four", "five", "six"};
        print(words, "Sample data");
        print(get_length_vector(words), "Number of characters in each string");
        print(longest_str(words), "Longest string");
        print(shortest_str(words), "Shortest string");
        std::cout << "The string that comes lexicographically first is: " << lexico_first(words) << '\n';
        std::cout << "The string that comes lexicographically last is: " << lexico_last(words) << '\n';

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
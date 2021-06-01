#include "../include/std_lib_facilities.h"

/* Chapter 10: Drill 2
 *
 * Using the code and discussion in §10.4, prompt the user to input seven
 * (x,y) pairs. As the data is entered, store it in a vector of Points called
 * original_points.
 */

struct Point {

    double x;
    double y;
};

std::istream& operator>>(std::istream &is, Point &p) {

    char ch1;
    char ch2;
    char ch3;
    double x;
    double y;
    if(is >> ch1 >> x >> ch2 >> y >> ch3 &&
       ch1 == '(' || ch2 == ',' || ch3 == ')')
       p = Point{x, y};
    else {
        is.clear(std::ios_base::failbit);
    }

    return is;
}

void ignoreLine() {

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


constexpr int kNum_pairs{7};

int main() {

    try {

        std::cout << "Please enter " << kNum_pairs << " (x,y) coordinate points:\n";
        std::vector<Point> original_points;
        for(int i{}; i < kNum_pairs; ++i) {
            Point p;
            if(std::cin >> p) {
                original_points.push_back(p);
            }
            else {
                std::cout << "Oops, that is a incorrect point entered. Try again:\n";
                std::cin.clear();
                ignoreLine();
                --i;
            }
        }

        std::cout << "Her are the " << kNum_pairs << "(x,y) points:\n";
        for(const auto &i : original_points) {
            std::cout << '(' << i.x << ',' << i.y << ")\n";
        }
        
        return 0; 
    }
    catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std:: cerr << "Exception: something went wrong.\n";
        return 2;
    }
}
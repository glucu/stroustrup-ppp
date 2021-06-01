#include "../include/std_lib_facilities.h"

/* Chapter 10: Drill 6
 *
 * Print the data elements from both vectors. 
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

std::ostream& operator<<(std::ostream& os, const std::vector<Point> &p) {

    for(const auto &i : p) {
        os << '(' << i.x << ',' << i.y << ")\n";
    }

    return os;
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
        
        std::cout << "Please enter name of output file:\n";
        std::string oname;
        std::cin >> oname;
        std::ofstream ost{oname};
        if(ost.fail()) error("can't open file ", oname);

        for(const auto &i : original_points) {
            ost << '(' << i.x << ',' << i.y << ")\n";
        }
        ost.close();

        std::ifstream ist{oname};
        if(ist.fail()) error("can't open file ", oname);
        std::vector<Point> processed_points;
        for(Point p; ist >> p;) {
            processed_points.push_back(p);
        }
        std::cout << '\n';

        std::cout << "Original points: " << original_points << '\n';
        std::cout << "processed points: " <<  processed_points << '\n';
        
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
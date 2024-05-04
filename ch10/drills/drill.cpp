#include "std_lib_facilities.h"

struct Point {
    int x;
    int y;
};

istream& operator>>(istream &in, Point &p) 
// read in a point that represents an x and y coordinate
// format: (x,y)
{
    char ch1, ch2, ch3;
    int x, y;
    in >> ch1;
    if(ch1 != '(') {
        in.unget();
        in.clear(ios_base::failbit);
        return in;
    }

    in >> x >> ch2 >> y >> ch3;
    if(!in || ch2 != ',' || ch3 != ')') error("Bad Read for Point");

    p.x = x;
    p.y = y;
    return in;
}

bool operator==(Point p1, Point p2)
// are the x and y coordinates of both p1 
// and p2 the same?
{
    return p1.x == p2.x && 
           p1.y == p2.y;
}

void read_in_points(vector<Point> &points, const string &message)
// read in a series of Points that represent an x and y coordinate
{
    cout << message << ":\n";
    for(size_t i{}; i != points.size(); ++i) {
        Point p;
        cin >> p;
        points[i] = p;
    }
}

void print_points(const vector<Point> &points, const string &output)
{
    cout << output << ":\n";
    for(Point p : points) {
        cout << '(' << p.x << ',' << p.y << ')' << '\n';
    }
}

void write_to_file(const vector<Point> &points, const string &name)
{
    ofstream ost{name};
    if(!ost) error("Could not open file for writing ", name);
    for(size_t i{}; i != points.size(); ++i) {
        ost << '(' << points[i].x << ',' << points[i].y << ")\n";
    }
}

void read_from_file(vector<Point> &points, const string &name)
{
    ifstream in{name};
    if(!in) error("Failed to open file ", name);
    for(Point p; in >> p;) {
        points.push_back(p);
        p = Point{};
    }
}

void compare_points(const vector<Point> &lhs, const vector<Point> &rhs)
{
    if(lhs.size() != rhs.size()) error("Something is wrong!");
    for(size_t i{}; i != lhs.size(); ++i) {
        if(!(lhs[i] == rhs[i])) error("Something is wrong!");
    }
}

const string prompt{"Please enter seven (x,y) pairs that denotes a Point"};

int main()
{
    try {
        
        vector<Point> original_points(7);
        read_in_points(original_points, prompt); 

        cout << "Please enter output file name: \n";
        string oname;
        cin >> oname;

        write_to_file(original_points, oname);


        cout << "Please enter input file name: \n";
        string iname;
        cin >> iname;
        vector<Point> processed_points;
        read_from_file(processed_points, iname);

        print_points(original_points, "original points");
        print_points(processed_points, "processed points");

        compare_points(original_points, processed_points);
        cout << "Pairs match!\n";

        
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

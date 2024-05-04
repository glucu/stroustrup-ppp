#include "Simple_window.h"
#include "Graph.h"

#include <vector>

void f(std::vector<Shape*> &v)
{
    for(const auto x : v) {
        x->print();
    }
}

int main()
{
    std::vector<Shape> vs;
    std::vector<Circle> vc{Circle{Point{100,200}, 55}};
    vs = vc;

}

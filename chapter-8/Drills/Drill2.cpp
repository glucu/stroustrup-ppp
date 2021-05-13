#include "../../include/std_lib_facilities.h"

/* Chapter 8: Drill 2
 *
 * Write three functions swap_v(int,int), swap_r(int&,int&), and swap_cr(const
 * int&, const int&). Each should have the body
 * 
 * { int temp; temp = a, a=b; b=temp; }
 * 
 * where a and b are the names of the arguments.
 * Try calling each swap like this
 * 
 * int x= 7;
 * int y =9;
 * swap_?(x,y); II replace ? by v, r, or cr
 * swap_?(7,9);
 * const int ex = 7;
 * const int cy = 9;
 * swap_?(cx,cy);
 * swap_?(7.7,9.9);
 * double dx = 7.7;
 * double dy = 9.9;
 * swap_?(dx,dy);
 * swap_?(dx,dy);
 * 
 * Which calls compiled, and why? After each swap that compiled, print
 * the value of the arguments after the call to see if they were actually
 * swapped. If you are surprised by a result, consult §8.6. 
 */

void swap_v(int a, int b) {

    int temp{a};
    a= b;
    b = temp;
}

void swap_r(int &a, int &b) {

    int temp{a};
    a= b;
    b = temp;
}

void swap_cr(const int &a, const int &b) {

  //  int temp{a};
  //  a = b;
  //  b = temp;
}

int main() {

    int x = 7;
    int y = 9;

    //swap_?(x, y);
    // answer: swap_v(x, y) || swap_r(x, y) || swap_cr(x, y)
    swap_r(x, y);
    std::cout << "x = " << x << ' ' << "y = " << y << '\n';

    //swap_?(7, 9);
    // answer: swap_v(7, 9) || swap_cr(7, 9)
    swap_cr(7, 9);

    const int cx  = 7;
    const int cy = 9;
    // swap_?(cx, yx);
    // answer: swap_v(cx, cy) || swap_cr(cx, cy)
    swap_v(cx, cy);
    std::cout << "cx = " << cx << ' ' << "cy = " << cy << '\n';

    // swap_?(7.7, 9.9);
    // answer: swap_v(7, 9) || swap_cr(7, 9)
    // truncates to 7 and 9 respectively
    swap_cr(7.7, 9.9);

    double dx = 7.7;
    double dy = 9.9;
    // swap_?(dx, dy);
    // answer: swap_v(dx, dy) || swap_v(dx, dy)
    // truncates to 7 and 9 respectively
    swap_cr(dx, dy);

    // swap_?(7.7, 9.9)
    // answer: swap_v(int, int) || swap_cr(const int&, const int&)
    swap_cr(7.7, 9.9);

    return 0;
}
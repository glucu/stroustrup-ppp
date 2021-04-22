#include "../include/std_lib_facilities.h"

int main() {

    std::cout << "Please enter three integer values (followed by 'enter'):\n";
    int val1{}, val2{}, val3{};
    std::cin >> val1 >> val2 >> val3;

    int min{}, mid{}, max{};
    if(val1 < val2) {

        if(val1 < val3) {

            min = val1;
            if(val3 < val2) {

                mid = val3;
                max = val2;
            }
            else {

                max = val3;
                mid = val2;
            }
        }
        else {

            min = val3;
            mid = val1;
            max = val2;
        }
    }
    else if(val2 < val3) {

        min = val2;
        if(val3 < val1) {

            mid = val3;
            max = val1;
        }
        else {

            mid = val1;
            max = val3;
        }
    }
    else {

        min = val3;
        mid = val2;
        max = val1;
    }

    std::cout << min << ", " << mid << ", " << max << '\n';
    return 0;
}
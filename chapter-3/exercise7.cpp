#include "../include/std_lib_facilities.h"

int main() {
    
    std::cout << "Please enter three string values (followed by 'enter'):\n";
    std::string str1, str2, str3;
    std::cin >> str1 >> str2 >> str3;

    std::string min, mid, max;
    if(str1 < str2) {

        if(str1 < str3) {

            min = str1;
            if(str3 < str2) {

                mid = str3;
                max = str2;
            }
            else {

                max = str3;
                mid = str2;
            }
        }
        else {

            min = str3;
            mid = str1;
            max = str2;
        }
    }
    else if(str2 < str3) {

        min = str2;
        if(str3 < str1) {

            mid = str3;
            max = str1;
        }
        else {

            mid = str1;
            max = str3;
        }
    }
    else {

        min = str3;
        mid = str2;
        max = str1;
    }

    std::cout << min << ", " << mid << ", " << max << '\n';
    
    return 0;
}
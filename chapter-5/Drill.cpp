#include "../include/std_lib_facilities.h"

/* Chapter 5: Drill
 *
 * Below arc 25 code fragments. Each is meant to be inserted into this "scaffolding" :
 * #include "std_lib_facilities.h"
 * int main()
 *     try {
 *           <<your code here>>
 *           keep_window_open();
 *           return 0;
 *       catch (exception& e) {
 *           cerr << "error: " << e.what() << '\n';
 *           keep_window _open();
 *           return 1;
 *       }
 *       catch ( ... ) {
 *           cerr << "Oops: unknown exception !\n";
 *           keep_window_open();
 *           return 2;
 *       }
 * 
 * Each has zero or more errors. Your task is to find and remove all errors in each
 * program. When you have removed those bugs, the resulting program will compile, run, and write "Success!" 
 * Even if you think you have spotted an error, you still need to enter the (original, unimproved) program 
 * fragment and test it; you may have guessed wrong about what the error is, or there may be more errors in
 * a fragment than you spotted. Also, one purpose of this drill is to give you a feel
 * for how your compiler reacts to different kinds of errors. Do not enter the scaffolding 25 times - that's a 
 * job for cut and paste or some similar "mechanical"
 * technique . Do not fix problems by simply deleting a statement; repair them by
 * changing, adding, or deleting a few characters . 
 */

int main() {

    try {

        // Drill 1:
        // Cout << "Success!\n"; <-- (compile-time error)
        cout << "Success!\n";

        // Drill 2:
        // cout << "Success!\n; <-- (compile-time error)
        cout << "Success!\n";

        // Drill 3:
        // cout << "Success" << !\n" <-- (compile-time error)
        cout << "Success" << "!\n";

        // Drill 4:
        // cout << success << '\n'; <-- (type error)
        cout << "Success!" << '\n';

        // Drill 5:
        // string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n"; <-- (compile-time error)
        int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";

        // Drill 6:
        // vector<int> v2(10); v(5) = 7; if(v(5) != 7) cout << "Success!\n"; <-- (compile-time error)
        vector<int> v2(10); v[5] = 7; if(v[5] == 7) cout << "Success!\n";

        // Drill 7:
        // if(cond) cout << "Success!\n"; else cout << "Fail!\n"; <-- (compile-time error)
        if(true) cout << "Success!\n"; else cout << "Fail!\n";

        // Drill 8:
        // bool c = false; if(c) cout << "Success!\n"; else cout << "Fail!\n"; <-- (logic error)
        bool c = true; if(c) cout << "Success!\n"; else cout << "Fail!\n";

        // Drill 9:
        // string s = "ape"; boo c = "fool" < s; if(c) cout << "Success!\n"; <--(compile-time error)
        string s = "ape"; bool c2 = "fool" > s; if(c2) cout << "Success!\n";

        // Drill 10:
        // string s2 = "ape"; if(s == "fool") cout << "Success!\n"; <-- (logic error)
        string s2 = "ape"; if(s != "fool") cout << "Success!\n";

        // Drill 11:
        // string s3 = "ape"; if(s == "fool") cout < "Success!\n"; <-- (compile-time error)
        string s3 = "ape"; if(s3 != "fool") cout << "Success!\n";

        // Drill 12: *************
        // string s4 = "ape"; if(s+"fool") cout < "Success!\n"; <-- (compile-time error)
        string s4 = "ape"; if(s4+"fool" == "apefool") cout << "Success!\n";

        // Drill 13:
        // vector<char> v3(5); for(int i = 0; 0 < v3.size(); ++i) ; cout << "Success!\n"; <-- (logic error: infinite loop)
        vector<char> v3(5); for(int i = 0; i < v3.size(); ++i) cout << "Success!\n";

        // Drill 14:
        // vector<char> v4(5); for(int i = 0; i <= v4.size(); ++i) ; cout << "Success!\n"; <-- (runtime error)
        vector<char> v4(5); for(int i = 0; i < v4.size(); ++i) cout << "Success!\n";

        // Drill 15:
        // string s5 = "Success!\n"; for(int i = 0; i < 6; ++i) cout << s5[i]; <-- (logic error)
        string s5 = "Success!\n"; for(int i = 0; i < s5.size(); ++i) cout << s5[i];


        // Drill 16:
        // if(true) then cout << "Success!\n"; else cout << "Fail!\n"; <-- (compile-time error)
        if(true) cout << "Success!\n"; else cout << "Fail!\n";

        // Drill 17:
        // int x = 2000; char c3 = x; if(c3 == 2000) cout << "Success!\n"; <-- (logic error)
        int x = 2000; char c3 = x; if(c3 != 2000) cout << "Success!\n";

        // Drill 18:
        // string s6 = "Success!\n"; for(int i = 0; i < 10; ++i) cout << s6[i]; <-- (runtime error)
        string s6 = "Success!\n"; for(int i = 0; i < s6.size(); ++i) cout << s6[i];


        // Drill 19:
        // vector v5(5); for(int i = 0; i <= v5.size(); ++i) ; cout << "Success!\n"; <-- (compile-time error)
        vector<int> v5(5); for(int i = 0; i < v5.size(); ++i) ; cout << "Success!\n";

        // Drill 20:
        // int i = 0; int j = 9; while(i < 10) ++j; if(j < i) cout << "Success!\n"; <-- (logic error)
        int i = 0; int j = 9; while(i < 10) ++i; --j; if(j < i) cout << "Success!\n";

        // Drill 21:
        // int x = 2; double d = 5/(x-2); if(d == 2*x+0.5) cout << "Success!\n"; <-- (logic error)
        int x2 = 2; double d = 5.0/x2+2; if(d == 2*x2+0.5) cout << "Success!\n";

        // Drill 22:
        // string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i]; <-- (compile-time error)
        string s7 = "Success!\n"; for (int i = 0; i < s7.size(); ++i) cout << s7[i];
  
        // Drill 23:
        // int i = 0; while(i < 10) ++j; if(j < i) cout << "Success!\n"; <-- (logic error: infinite loop)
        int ii = 0; int jj = 0; while(ii < 10) ++ii; if(jj < ii) cout << "Success!\n";

        // Drill 24:
        // int x = 4; double d = 5/(x-2); if(d == 2*x+0.5) cout << "Success!\n"; <-- (logic error)
        int x3 = 4; double d2 = 5.0/(x3-2); if (d2 == x3/2.0+0.5) cout << "Success!\n";

        // Drill 25:
        // cin << "Success!\n"; <-- (compile-time error)
        cout << "Success!\n";

        keep_window_open();
        return 0;
    }
    catch(std::exception &e) {
        std::cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch(...) {
        std::cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}

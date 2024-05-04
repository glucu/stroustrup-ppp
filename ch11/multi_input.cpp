#include "std_lib_facilities.h"

/*
 * COMMENT:
 * I do not account for overflow. I used an ostringstream for the formatting. Although
 * this is my solution, I did check Stroustrup's solution and he didn't do anything special about
 * <b>0xZZ</b> for example. That is a invalid hex value which actually outputs <b>0</b>. I think this is
 * undefined and can be implementation-defined as well? So I did the same.
 */

int parse_prefix(istream &in, char &ch)
// parse prefix for what value to expect
{
    int status_code{-1}; // error
    if(isdigit(ch) && ch == '0') {
        char next{in.peek()};
        
        if(tolower(next) == 'x') {
            status_code = 2; // hexadecimal
        }
        else {
            status_code = 1; // octal
        }
    }
    else if(isdigit(ch)) {
        status_code = 0; // decimal
    }

    in.putback(ch);

    return status_code;
}

void print(ostringstream &buffer)
// print formatted output 
{
    cout << buffer.str() << '\n';
}

int main()
{
    try {

        cin.unsetf(ios::dec);
        cin.unsetf(ios::oct);
        cin.unsetf(ios::hex);
       
        cout << "Enter integers in any combination of octal, decimal, or hexadecimal,"
                 " using the 0 and 0x base suffixes.\n" 
             << "Press Ctrl+D (or Ctrl+Z on Windows) to finish input.\n\n> "; 

        istream &in{cin};
        ostringstream buffer;
        int value{};
        for(char ch; in >> ch && ch != 'q';) {
            int status = parse_prefix(in, ch);
            if(status == 0) {
                in >> value;
                buffer << dec << value << " decimal converts to"
                       << dec << setw(15) << value << " decimal" << '\n';
            }
            else if(status == 2) {
                in >> value;
                buffer << showbase << hex << value << " hexadecimal converts to "
                       << dec << setw(9) << value << " decimal" << '\n';
            }
            else if(status == 1) {
                in >> value; 
                buffer << showbase << oct << value << " octal converts to" << dec << setw(15) << value << " decimal" << '\n';
            }
            else {
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ch << " is not a valid prefix. Try again.\n";
            }

            cout << "> ";
        }

        print(buffer);
                
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

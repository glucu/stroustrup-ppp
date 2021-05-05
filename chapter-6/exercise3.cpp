#include "../include/std_lib_facilities.h"

/* Chapter 6: exercise 3
 * 
 * Add a factorial operator: use a suffiX ! operator to represent "factorial."
 * For example, the expression 7! means 7 * 6 * 5 * 4 * 3 * 2 * 1. Make ! bind
 * tighter than • and /; that is, 7*81 means 7*(8!) rather than (7*8)1. Begin
 * by modifying the grammar to account for a higher-level operator. To
 * agree with the standard mathematical defmition of factorial, let 0! evaluate to 1.  
 */

class Token {
public:
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    
    char kind;        // what kind of token
    double value;     // for numbers: a value
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back

private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{ }

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t) {

    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get() {

    if (full) {       // do we already have a Token ready?
                      // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9': {

        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback()

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

int factI(int n) {

    int result = 1;
    while (n > 0) {
        result *= n;
        --n;
    }

    return result;
}

// deal with numbers and parentheses
double primary() {

    Token t = ts.get();
    switch (t.kind) {
    case '(': {   // handle '(' expression ')' 

        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '8': {              // we use '8' to represent a number 
        Token tt = ts.get();
        switch (tt.kind) {
        case '!': {
            int n = int(t.value);
            n = factI(n);
            return n;
        }

        default:
            ts.putback(tt);
            break;
        }

        return t.value;     // return the number's value
    }

    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term() {

    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
        break;
        case '/': {

            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression() {

    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main() {
    
    try {
        std::cout << "Welcome to our simple calculator!\n";
        std::cout << "*********************************\n\n";
        std::cout << "Please enter expression using floating-point numbers.\n";
        std::cout << "Operators: +, -, *, /, and ! (followed by 'x' to quit or '=' to print):\n";

        double val{};
        while (cin) {
            Token t = ts.get();

            if (t.kind == 'x') break; // 'q' for quit
            if (t.kind == '=')        // ';' for "print now"
                cout << "=" << val << '\n';
            else {
                ts.putback(t);
                val = expression();
            }
        }
        keep_window_open();
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
}
//------------------------------------------------------------------------------
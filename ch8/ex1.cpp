/*
 * Simple Calculator Program
 *
 * This program implements a basic expression calculator.
 * Input from cin; output to cout.
 *
 * ----------GRAMMAR----------
 *
 * Calculation:
 *     Statement
 *     Print
 *     Quit
 *     Help
 *     Calculation Statement
 * Statement:
 *     Declaration
 *     Assignment
 *     Expression
 * Print:
 *     ";"
 *     "\n"
 * Quit:
 *     "quit"
 * Help:
 *     "help"
 * Declaration:
 *     "let" Name "=" Expression
 *     "const" Name "=" Expression
 * Assignment:
 *     Name "=" Expression
 * Assignment:
 *     Name "=" Expression
 * Expression:
 *     Term
 *     Expression "+" Term
 *     Expression "-" Term
 * Term:
 *     Exponent
 *     Term "*" Exponent
 *     Term "/" Exponent
 *     Term "%" Exponent
 * Primary:
 *     Number
 *     "(" Expression ")"
 *     "{" Expression "}"
 *     Name
 *     Name Assignment Expression
 *     "-" Primary
 *     "+" Primary
 * Exponent:
 *     "sqrt" "(" Expression ")"
 *     "pow" "(" Expression "," Expression ")"
 *     HiOp
 * HiOp:
 *     Primary "!"
 * Number:
 *     floating-point literal
 * Name:
 *     "_" Name
 *     Name "_"
 *     [a-zA-Z] [a-zA-Z0-9]*
 */

#include "std_lib_facilities.h"

// constants for Token kinds - In arbitrarily order
const char number = '8';           // t.kind==number means that t is a number Token
const char quit   = 'q';           // t.kind==quit means that t is a quit Token
const char print  = ';';           // t.kind==print means that t is a print Token
const char name   = 'a';           // t.kind==name means that t is a variable Token 
const char underscore = '_';       // Not a Token but used in variable names 

const char let = 'L';              // variable declaration Token
const char stable = 'C';           // const variable Token
const char sqrtt = 'S';            // sqrt Token
const char poww = 'P';             // pow Token
const char help = 'H';             // help Token
const vector<char> token_kinds{let, stable, sqrtt, poww, help};
                
// constant keywords
const string let_key = "let";
const string stable_key = "const";
const string sqrt_key = "sqrt";
const string pow_key = "pow";
const string help_key = "help";
const vector<string> keywords{let_key, stable_key, sqrt_key, pow_key, help_key};

// other constants
const string prompt  = "> ";  
const string result  = "= ";       // used to indicate that what follows is a result

class Token {
// Models a grammar token from input
public:
    Token(char ch)                    : kind{ch}, value{0}   {}
    Token(char ch, double val)        : kind{ch}, value{val} {}
    Token(char ch, const string &n)   : kind{ch}, name{n}    {}

    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;      // for names: name itself
};

class Token_stream {
// Models cin as a Token stream
public: 
    Token_stream(istream &in = cin);           // make a Token_stream that reads from cin
    Token get();                               // get a Token 
    void putback(Token t);                     // put a Token back in the buffer
    void ignore(char c);                       // discard tokens up to an including a c
                              
private:
    bool full;                // does buffer contain a token?
    Token buffer;             // here is where we keep a Token put back using putback()
};

// The default constructor just sets full to indicate that the buffer is empty
Token_stream::Token_stream()
: full{false}, buffer{0}    // no Token in buffer
{ }

void Token_stream::putback(Token t)
// assign t to buffer for later use 
// pre-condition: buffer is not full
{
    if (full) error("putback() into a full buffer");
    buffer = t;       
    full = true;      
}

Token Token_stream::get() 
// read characters from cin and compose a Token
// pre-condition: return buffer instead if full
{
    if (full) {
        full=false;
        return buffer;
    }  

    char ch{};
    while(cin.get(ch) && isspace(ch) && ch != '\n') ; // null statement 
    if (ch == '\n') return Token{print}; 

    switch (ch) {
    case quit:
    case print:
    case '(':
    case ')':
    case '{':
    case '}':
    case '+':
    case '-':
    case '*':
    case '/': 
    case '%':
    case '!':
    case '=':
    case ',':    // comma for argument separation for function like sqrt or pow
        return Token{ch}; // let each character represent itself
    case '.':             // floating-points can start with a . 
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':    
    {
        cin.putback(ch);    // put digit back into the input stream
        double val;
        cin >> val;        // we know its a digit, so lets read it 
        return Token{number,val};
    }
    default:
        if (isalpha(ch) || ch == underscore) { // I allowed variable names to start with an underscore (valid in C++ anyways)
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == underscore)) s+=ch;
            cin.putback(ch);
            for(int i = 0; i != keywords.size(); ++i) {
                if(s == keywords[i]) return token_kinds[i];
            }
            return Token{name,s};
        }
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
// c represents the kind of a Token
{
    // first look in buffer
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    // now search input
    char ch = ' ';
    while (cin.get(ch) && ch != '\n')
        if (ch==c) return;
}


class Variable {
// variable (name,value) pair
public:
    Variable() {}
    Variable (string n, double v, bool is_c = true) :name(n), value(v), is_const{is_c}  { }

    string name;
    double value;
    bool is_const;
};

class Symbol_table {
public:
    double get_value(const string &s);
    void set_value(const string &s, double d);
    double define_name(const string &var, double val, bool is_c);

private:
    bool is_declared(const string &var);
private:
    vector<Variable> var_table;
};

Symbol_table sym_table;


double Symbol_table::get_value(const string &s)
// return the value of the Variable names s
{
    for (const Variable &v : var_table)
        if (v.name  == s) return v.value;
    error("get: undefined variable ", s);
}

void Symbol_table::set_value(const string &s, double d)
// set the Variable named s to d. const variables cannot be assigned.
{
    for (Variable &v : var_table) {
        if (v.name == s && !v.is_const) {
            v.value = d;
            return;
        }
        if(!v.is_const) error("cannot modifiy a const variable ", s); // to assure user knows what occurred
    }

    error("set: undefined variable ", s);
}

bool Symbol_table::is_declared(const string &var)
// return true if var is declared; otherwise false 
{
    for (const Variable &v : var_table)
        if (v.name == var) return true;
    return false;
}

double Symbol_table::define_name(const string &var, double val, bool is_c)
// add (var,val) to var_table
{
    if (is_declared(var)) error(var," declared twice");
    var_table.push_back(Variable{var, val, is_c});
    return val;
}

// function prototypes
double expression(Token_stream &ts); 
double primary(Token_stream &ts);

int factorial(int n)
// compute the factorial of n (n!) recursively
// pre-condition: n must be a non-negative integer
//                return 1 for 0!
{
    if(n < 0) error("cannot compute the factorial of a negative number", n);
    if(n == 0) return 1;
    return n * factorial(n-1);
}

double hiOp(Token_stream &ts)
// deal with factorial function
{
    double left = primary(ts);
    Token t = ts.get();
    switch(t.kind) {
    case '!':
        return factorial(int(left));
    default:
        ts.putback(t);
        return left; 
    }
}


double exponent(Token_stream &ts)
// deal with square root, and computes the value of base raised to the power of exp
{
    Token t = ts.get();
    switch(t.kind) {
    case sqrtt:
        {
            t = ts.get();
            if(t.kind != '(') error("\'(\' expected after sqrt keyword");
            double d = expression(ts);
            t = ts.get();
            if(t.kind != ')') error("\')\' expected after the argument");
            return sqrt(d);
        }
    case poww:
        {
            t = ts.get();
            if(t.kind != '(') error("\'(\' expected after pow keyword");
            double base = expression(ts);
            t = ts.get();
            if(t.kind != ',') error("\',\' expected after base");
            int exp = expression(ts); // compilier might warn about this
            t = ts.get();
            if(t.kind != ')') error("\')\' expected after exp");
            return pow(base, exp);    
        }
    default:
        ts.putback(t);
        return hiOp(ts); 
    }
}

double primary(Token_stream &ts)
// deal with numbers, parentheses, variables, and unary minus and plus
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':           // handle '(' expression ')'
        {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '{':          // handle '{' expression '}'
        {
            double d = expression(ts);
            t = ts.get();
            if(t.kind != '}') error("'}' expected");
            return d;
        }
    case number:    
        return t.value;    // return the number's value
    case name:
        {
            Token next = ts.get();
            if(next.kind == '=') {
                double d = expression(ts);
                sym_table.set_value(t.name, d);
            }
            else 
                ts.putback(next);
            return sym_table.get_value(t.name); // return the variable's value
        }
    case '-':
        return - primary(ts);
    case '+':
        return primary(ts); // it made sense to add unary + too.
    default:
        error("primary expected");
    }
}

double term(Token_stream &ts)
// deal with *, /, and %
{
    double left = exponent(ts);
    Token t = ts.get(); // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= exponent(ts);
            t = ts.get();
            break;
        case '/':
            {    
                double d = exponent(ts);
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        case '%':
            {    
                double d = term(ts);
                if(d == 0) error("divide by zero");
                left = fmod(left, d); 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);        // put t back into the token stream
            return left;
        }
    }
}


double expression(Token_stream &ts)
// deal + and -
{
    double left = term(ts);      // read and evaluate a Term
    Token t = ts.get();          // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term(ts);    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(ts);    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);      // put t back into the token stream
            return left;        // finally: no more + or -: return the answer
        }
    }
}

double declaration(char kind, Token_stream &ts)
// declare a variable called "name" with the initial value "expression"
{
    Token t = ts.get();
    if (t.kind != name) error ("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression(ts);
    sym_table.define_name(var_name, d, kind == stable);
    return d;
}

double statement(Token_stream &ts)
// declare a variable or process an expression
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
    case stable:
        return declaration(t.kind, ts); 
    default:
        ts.putback(t);
        return expression(ts);
    }
}


void clean_up_mess(Token_stream &ts)
{ 
    ts.ignore(print);
}

void help_guide()
{
         cout << "********** Calculator Help Guide **********\n\n"
              << "Supported Operators:\n"
              << "   +  -  *  /  %  sqrt(n)  pow(b, e)  !  ()  {}\n\n"
              << "Pre-defined Constants:\n"
              << "   k = 100  PI = 3.14159\n\n"
              << "Variable Declaration:\n"
              << "   Using 'let' keyword: let Name = Number;\n"
              << "   Constant Variable: const Name = Number;\n\n"
              << "Special Commands:\n"
              << "   Press 'Enter' key to print result\n"
              << "   Type 'q' or 'quit' to exit the calculator\n";
}



void calculate(Token_stream &ts)
{
    cout << "Welcome to our simple calculator.\n"
		 << "Please enter expressions using floating-point numbers (followed by " << print << " to print) and "
		 << "enter " << quit << " to quit.\n"
         << "(Enter \'help\' for instructions:\n";

    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print) t=ts.get();                            // first discard all "prints"
            if (t.kind == quit) return;                                    // quit
            if (t.kind == help) {
                help_guide();                                              // help guide
                ts.ignore(print);                                          // ignore whatever comes after the command
            }
            else {
                ts.putback(t);
                cout << result << setprecision(12) << statement(ts) << '\n'; // cout defaults to 6 precision, so we increase the
                                                                           // significant digits to 12
            }
        }
        catch (const exception& e) {
            cerr << "exception: " << e.what() << '\n';                     // write error message
            clean_up_mess(ts);
        }
    }
}

int main()
{
    try {
        // pre-defined constants
        sym_table.define_name("pi", 3.1415926535, true); // The ratio of a circle's circumference to its diameter.
        sym_table.define_name("k", 1000, true);
        sym_table.define_name("e", 2.7182818284, true); // Euler's number, the base of natural logarithms.

        Token_stream ts{};
        calculate(ts);

        return 0;
    }
    catch (const exception& e) {
        cerr << "exception: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "exception. something went wrong\n";
        return 2;
    }
}

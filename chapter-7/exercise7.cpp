

/* Chapter 7: exercise 7
 *
 *  Change the q and h commands to be quit and help, respectively.
 */ 

#include "../include/std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;
	std::string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, std::string name) :kind(ch), name(name) { }
};

class Token_stream {
public:
	//Token_stream() :full(0), buffer(0) { }

	Token get();
	void putback(Token t) { buffer.push_back(t); }
	void ignore(char);

private:
	vector<Token> buffer;
};

class Variable {
public:
	

	std::string name;
	double value;
	bool constant;
};

class Symbol_table {
public:
	double get(string s);
    void set(string s, double d);
    bool is_declared(string s);
    void declare(string s, double d, bool c);

private:
	vector<Variable> var_table;
};

const char let{ '#' };
const char quit{ 'Q' };
const char print{ ';' };
const char help{'h'};
const char number{ '8' };
const char name{ 'a' };
const char constant{'C'};
const char underscore{'_'};
const char sqrtt{ 's' };
const char poww{ 'p' };

// Built-in function names
const std::string let_key{"let"};
const std::string quit_key{"exit"};
const string const_key{"const"};
const std::string sqrt_key{"sqrt"};
const std::string pow_key{"pow"};

Token Token_stream::get() {

	if (!buffer.empty()) { Token t = buffer.back(); buffer.pop_back(); return t; }
	char ch{' '};
	while (isspace(ch) && ch != '\n')
        ch = cin.get();

	switch (ch) {

    case 'h':
    case 'H':
        return Token{help};
        
	case ';':
	case '\n':
		return Token{print};

	case '(': case ')': case '+': case '-':
	case '*': case '/': case '%': case '=':
		return Token(ch);

	case '.': case '0': case '1': case '2':
	case '3': case '4': case '5': case '6':
	case '7': case '8': case '9': {

		std::cin.putback(ch);
		double val;
		std::cin >> val;
		return Token(number, val);
	}
	default:
		if (std::isalpha(ch)) {
			std::string s;
			s += ch;
			while (std::cin.get(ch) && (std::isalpha(ch) || std::isdigit(ch) || ch == underscore)) s += ch;
			cin.putback(ch);
			if (s == let_key)   return Token(let);
			if (s == quit_key)  return Token(quit);
			if (s == const_key)  return Token{constant};
			if (s == sqrt_key)  return Token(sqrtt);
			if (s == pow_key)   return Token(poww);
								return Token(name, s);
		}

		error("Bad token");
	}
}

void Token_stream::ignore(char c) {

	while (!buffer.empty() && buffer.back().kind != c)
        buffer.pop_back();
    
    if (!buffer.empty()) return;

   
	char ch{' '};
    while (ch != c && ch != '\n')
        ch = cin.get();
    return;
}



double Symbol_table::get(string s) {

	for (const Variable& v : var_table)
	    if (v.name == s) return v.value;
	error("get: undefined name ", s);
}

void Symbol_table::set(string s, double d) {

    for (Variable& v : var_table)
        if (v.name == s) {
            if (v.constant) error(s, " is a constant");
            v.value = d;
            return;
        }

	error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s) {

	for (const Variable& v : var_table)
	    if (v.name == s) return true;
	return false;
}

void Symbol_table::declare(string s, double d, bool c) {

    if (is_declared(s)) error(s, "is declared twice");
    var_table.push_back(Variable{s, d, c});
}

Symbol_table symbols;
Token_stream ts;

double expression();

double square_root() {

	Token t = ts.get();
	switch (t.kind) {

	case '(': {

		double d = expression();
	
		if (d <= 0) error(std::to_string(d), " cannot be square routed. Enter ';' to continue");

		t = ts.get();
		if (t.kind != ')') error(" ')' was expected. Enter ';' to continue");

		return sqrt(d);
	}
	default:
		error(" '(' was expected. Enter ';' to continue");
	}
}

double raise_pow() {

	Token t = ts.get();
	switch (t.kind) {

	case '(': {

		double d = expression();

		t = ts.get();
		if (t.kind != ',')
			error(" ',' was expected. Enter ';' to continue");

		double d2 = expression();

		t = ts.get();
		if (t.kind != ')')
			error(" ')' was expected. Enter ';' to continue");

		return pow(d, d2);
	}
	default:
		error(" '(' was expected. Enter ';' to continue");
	}
}

double primary() {

	Token t{ ts.get() };
	switch (t.kind) {

	case '(': {	
		double d{ expression() };
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '-':
		return -primary();

	case '+':
		return primary();

	case number:
		return t.value;

	case name:
		return symbols.get(t.name);

	case sqrtt:
		return square_root();

	case poww:
		return raise_pow();

	default:
		error("primary expected");
	}
}

double term() {

	double left{ primary() };
	while (true) {

		Token t{ ts.get() };
		switch (t.kind) {

		case '*':
			left *= primary();
			break;

		case '/': {	
			double d{ primary() };
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}

		case '%': {
			int i1{ narrow_cast<int>(left) };
			int i2{ narrow_cast<int>(primary()) };
			if(i2 == 0) error("%: divide by zero");
			left = i1 % i2;
			t = ts.get();
			break;
		}

		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression() {

	double left{ term() };
	while (true) {

		Token t{ ts.get() };
		switch (t.kind) {
		case '+':
			left += term();
			break;

		case '-':
			left -= term();
			break;

		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration() {

	bool is_const = false;
    Token t = ts.get();
    if (t.kind == constant) is_const = true;

	Token t2{ ts.get() };
	if (t2.kind != name) error("name expected in declaration");

	std::string name{ t2.name };
	if (symbols.is_declared(name)) error(name, " declared twice");

	Token t3{ ts.get() };
	if (t3.kind != '=') error("= missing in declaration of ", name);

	double d{ expression() };
	symbols.declare(name, d, is_const);

	return d;
}

double assignment() {

    Token t = ts.get();
    string var_name = t.name;
    if (!symbols.is_declared(var_name)) error(var_name, " has not been declared");

    ts.get();
    double d = expression();
    symbols.set(var_name, d);
    return d;
}

double statement() {

	Token t{ ts.get() };
	switch (t.kind) {
	case let:
	case constant:
		ts.putback(t);
		return declaration();
	case 'name': {
		Token t2 = ts.get();
	    
        ts.putback(t2);
        ts.putback(t);
	    if (t2.kind == '=') {
	        return assignment();
	    }

		return expression();
	}

	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess() {

	ts.ignore(print);
}

void help_me() {

    cout << "**********************************************************************" << '\n';
	cout << "Available operators:: {}, (), +, -, /, *, %" << '\n';
	cout << "Pre-defined names: sqrt() || pow()" << '\n';
	cout << "Define your own names using " << let_key << " name = number;" << '\n';
	cout << "Define const names using " << let_key << " const name = number;" << '\n';
	cout << "use enter to print and 'exit' to quit" << '\n';
	cout << "************************************************************************" << '\n';
}

const std::string prompt{ "> " };
const std::string result{ "= " };

void calculate() {

	while (true) {
		try {

			std::cout << prompt;
			Token t = ts.get();
			while (t.kind == print) t = ts.get();
			if (t.kind == quit) return;
            if(t.kind == help) {
                help_me();
                ts.ignore(print);
            }
            else {
			    ts.putback(t);
			    std::cout << result << statement() << '\n';
            }
		}
		catch (runtime_error& e) {
			std::cerr << e.what() << '\n';
			clean_up_mess();
		}
	}
}

int main() {
	
	try {
		
		symbols.declare("k", 1000, false);
		calculate();
		return 0;
	}
	catch (exception& e) {
		std::cerr << "exception: " << e.what() << '\n';
		char c{' '};
		while (std::cin >> c && c != ';') ;
		return 1;
	}
	catch (...) {
		std::cerr << "exception\n";
		char c{' '};
		while (std::cin >> c && c != ';') ;
		return 2;
	}
}
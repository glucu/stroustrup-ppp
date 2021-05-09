
/* Chapter 7: exercise 2
 *
 * Provide an assignment operator, =, so that you can change the value of a
 * variable after you introduce it using let.
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
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void putback(Token t) { buffer = t; full = true; }

	void ignore(char);

private:
	bool full;
	Token buffer;
};

const char let{ '#' };
const char quit{ 'Q' };
const char print{ ';' };
const char number{ '8' };
const char name{ 'a' };
const char sqrtt{ 's' };
const char poww{ 'p' };

// Built-in function names
const std::string let_key{"let"};
const std::string quit_key{"exit"};
const std::string sqrt_key{"sqrt"};
const std::string pow_key{"pow"};

Token Token_stream::get() {

	if (full) { full = false; return buffer; }
	char ch{' '};
	std::cin >> ch;
	switch (ch) {
	case '(': case ')': case '+': case '-':
	case '*': case '/': case '%': case ';':
	case '=':
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
			while (std::cin.get(ch) && (std::isalpha(ch) || std::isdigit(ch) || ch == '_')) s += ch;
			cin.putback(ch);
			if (s == let_key)   return Token(let);
			if (s == quit_key)  return Token(quit);
			if (s == sqrt_key)  return Token(sqrtt);
			if (s == pow_key)   return Token(poww);
								return Token(name, s);
		}

		error("Bad token");
	}
}

void Token_stream::ignore(char c) {

	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (std::cin >> ch)
		if (ch == c) return;
}

class Variable {
public:
	Variable(std::string n, double v) :name(n), value(v) { }

	std::string name;
	double value;
};

vector<Variable> names;

double get_value(std::string s) {

	for (const Variable &v : names)
		if (v.name == s) return v.value;
	error("get: undefined name ", s);
}

void set_value(std::string s, double d) {


	for (Variable &v : names)
		if (v.name == s) {
			v.value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(std::string s) {

	for (const Variable &v : names)
		if (v.name == s) return true;
	return false;
}

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

	case number:
		return t.value;

	case name:
		return get_value(t.name);

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

	Token t{ ts.get() };
	if (t.kind != 'a') error("name expected in declaration");

	std::string name{ t.name };
	if (is_declared(name)) error(name, " declared twice");

	Token t2{ ts.get() };
	if (t2.kind != '=') error("= missing in declaration of ", name);

	double d{ expression() };
	names.push_back(Variable(name, d));

	return d;
}

double statement() {

	Token t{ ts.get() };
	switch (t.kind) {
	case let:
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

double assignment() {

    Token t = ts.get();
    string var_name = t.name;
    if (!is_declared(var_name)) error(var_name, " has not been declared");

    ts.get();
    double d = expression();
    set_value(var_name, d);
    return d;
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
			ts.putback(t);
			std::cout << result << statement() << '\n';
		}
		catch (runtime_error& e) {
			std::cerr << e.what() << '\n';
			clean_up_mess();
		}
	}
}

int main() {
	
	try {
		
		names.push_back(Variable{"k", 1000});
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

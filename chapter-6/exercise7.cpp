
/* Chapter 6: exercise 7
 *
 * Write a grammer for logical expressions. A logical expression is much
 * like an arithmetic expression except that the operators are ! (not) , -
 * (complement), & (and), I (or) , and " (exclusive or) . ! and - are prefix
 * unary operators. A" binds tighter than a I Gust as * binds tighter than +)
 * so that xly"z means xl(y"z) rather than (xly)"z. The & operator binds
 * tighter than " so that x"y&z means x"(y&z).
 */


/*
        Third term:
	        Second Term
	        Third Term "|" Second Term
        Second Term:
	        First Term
	        Second Term "^" First Term
        First Term:
	        Primary
	        First Term "&" Primary
        Primary:
	        Number
	        "!" Number
	        "~" Number
        Number:
	        Floating-Point-Literal
*/      
#include "Link.hpp"

/*
 * Could the “list of gods” example from §17.10.1 have been written using a singly-linked list; that is, could we have left
 * the prev member out of Link? Why might we want to do that? For what kind of examples would it make sense to use a
 * singly-linked list? Re-implement that example using only a singly-linked list.
 *
 * Yes, the example can be written using a singly-linked list instead. This would require slight modification to the member functions.
 * For example: advance(int n) can only move forward (not bi-traversal), so removing the logic to move backwards is not present in the
 * singly-linked list. Why might we want to do that? Singly-linked list has less memory overhead compared to the doubly-linked list, because
 * it carries only one pointer rather than two. You might not need that extra prev pointer, so Singly-linked list may seem favourable and less complicated.
 */

void print_all(Link *p)
{
	cout << "{ ";
	while(p) {
		cout << p->value;
		if(p = p->next()) cout << ", ";
	}
	cout << " }";
}

int main()
{
	Link* norse_gods = new Link("Thor");
	norse_gods = norse_gods->insert(new Link{"Odin"});
	norse_gods = norse_gods->insert(new Link{"Zeus"});
	norse_gods = norse_gods->insert(new Link{"Freia"});

	Link* greek_gods = new Link("Hera");
	greek_gods = greek_gods->insert(new Link{"Athena"});
	greek_gods = greek_gods->insert(new Link{"Mars"});
	greek_gods = greek_gods->insert(new Link{"Poseidon"});

	Link *p = greek_gods->find("Mars");
	if(p) {
		p->value = "Ares";
	}

	p = norse_gods->find("Zeus");
	if(p) {
		if(p == norse_gods) norse_gods = norse_gods->erase(p); 
		else                norse_gods = norse_gods->erase(p);

		greek_gods = greek_gods->insert(new Link{"Zeus"});
	}

	cout << "NORSE GODS:\n";
	print_all(norse_gods); cout << "\n\n";

	cout << "GREEK GODS:\n";
	print_all(greek_gods); cout << "\n\n";

	return 0;
}


	

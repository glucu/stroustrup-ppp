# Exercise 12
> Why did we define two versions of `find()`?

We defined two `find()` member functions for different needs. The non-const `find()` lets us find a particular value in the doubly-linked list and modify it.
The const version of `find()` prevents us from doing such a thing, but rather it lets us `read` the value, but not change it.

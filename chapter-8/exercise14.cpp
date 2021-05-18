

/* Chapter 8: exercise 14
 *
 * Can we declare a non-reference function argument const (e.g., void f(const int);)? 
 * What might that mean? Why might we want to do that?
 * Why don't people do that often? Try it; write a couple of small programs
 * to see what works. 
 */



 /* Q: Can we declare a non-reference function argument const?
  * A: Yes, C++ will permit it and is completly legal and valid.
  *
  * Q: What might that mean?
  * A: The parameter will be initialized by the argument passed to the function
  *    as a COPY, but with the attribute const which tells the function it cannot modify
  *    it and only for reading purposes.
  * 
  * Q: Why might we want to do that? 
  * A: If the argument we want to pass does not have an overhead (cost to do the copy), and
  *    we also don't want the function to change the value, we make sure of that with the const keyword.
  * 
  * Q: Why don't people do that often?
  * A: I would say it's not common. Most situations are done as either passing things by value,
  *    const-reference, or reference.
  */
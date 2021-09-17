# Exercise 2
> How many bytes are there in an int? In a double? In a bool? Do not use sizeof except to verify your answer.

The C++ standard _guarantees a minimum size_ for the built-in types: Therefore, to say that an *int* is 32 bits may not be 32 bits on other implementations, thus is is known
as implementation defined.

Type | Minimum Size
---- | -------------
int  | 16 bits
double | 10 significant digits
bool | 8 bits

```c++
std::cout << "size of int == "    << sizeof(int) << '\n';         // 4 bytes (32 bits)
std::cout << "size of double == " << sizeof(double) << '\n';      // 8 bytes (64 bits)
std::cout << "size of bool ==   " << sizeof(bool) << '\n';        // 1 byte (8 bits)
```

#include <iostream>
#include <stdexcept> 

/*
 * COMMENT:
 * The results do in fact look "unreasonable." In fact,
 * <b>const char ca1[] = {'C', '+', '+'};</b> is stored in the
 * .rodata segment when it is a const global array. But on my machine
 * is stored adjacent to the const string literal <b>exception</b> meaning,
 * the output is: C++exception. Really weird. Here's the output:
 *
 * > g++ -g0 -O0 ex4.cpp
 * > objdump -s -j .rodata a.out
 *
 * Here is the first line:
 * Contents of section .rodata:
   2000 01000200 432b2b65 78636570 74696f6e  ....C++exception
 *
 * 432b2b65: 43 2b 2b --> C++
 * 65 .... --> exception
 *
 * As for storing it in as a local variable, dunno. I think the compilier 
 * does some kind of optimization that prevents you from seeing it even with
 * objdump or hexdump...
 *
 *
 *
 */

char* strdup(const char *s)
{
    if(!s) return nullptr;

    std::size_t n{};
    while(*(s+n)) ++n;

    char *s_cpy = new char[n+1];

    std::size_t i{};
    while(i != n) {
        *(s_cpy+i) = *(s+i);
        ++i;
    }

    *(s_cpy+i) = 0;

    return s_cpy;
}

char* findx(const char *s, const char *x)
// return the first occurrence of x in s
// pre-condition: return NULL if s or x are nullptr
{
	if(!x || !s) return nullptr;

	for(size_t i{}; *(s+i); ++i) {
		if(*(s+i) == *x) {
			size_t k{1};
			for(size_t j{i+1}; *(s+j) && *(x+k); ++j) {
				char ch1 = *(s+j);
				char ch2 = *(x+k);
				if(ch1 != ch2) break;
				++k;
			}
			if(!(*(x+k))) {
				char *x_cpy = new char[k+1];
				for(size_t ii{i}, kk{}; *(x+kk); ++ii, ++kk)
					*(x_cpy+kk) = *(s+ii);
				*(x_cpy+k) = '\0';
				return x_cpy;
			}
		}
	}
	return nullptr;
}

int size(const char *s)
{
    int cnt{};
    while(*s++) ++cnt;
    return cnt;
}

int strcmp(const char *s1, const char *s2)
{
    if(!s1 || !s2) throw std::invalid_argument{"strcmp: one or more arguments are null pointers"};

    const int s1_n = size(s1);
    const int s2_n = size(s2);
    if(s1_n == s2_n) {
        while(*s1) {
            if(*s1 != *s2) {
                if(*s1 < *s2) return -1;
                else          return 1;
            }
            ++s1;
            ++s2;
        }
        return 0;
    }
    else {
        int n = (s1_n < s2_n) ? s1_n : s2_n;
        for(int i{}; i != n; ++i) {
            if(*s1 != *s2) {
                if(*s1 < *s2) return -1;
                else          return 1;
            }
            ++s1;
            ++s2;
        }
        if(s1_n < s2_n) return -1;
        return 1;
    }
}


void print(const char *s)
{
    while(*s) {
        std::cout << *s;
        ++s;
    }
    std::cout << '\n';
}

void strdup_test()
{
    const char ca1[] = {'C','+','+'};
    const char *ca2 = new const char[3]{'C','+','+'};

    char *dup1 = strdup(ca1);
    char *dup2 = strdup(ca2);
    print(dup1);
    print(dup2);

    delete[] ca2;
    delete[] dup1;
    delete[] dup2;
}

void findx_test()
{
    /* 
     * segmentation fault
     *
    char s[] = {'C', '+', '+', ' ', 'i', 's', ' ', 'a', 'w', 'e', 's', 'o', 'm', 'e'};
    char x[] = {'a', 'w', 'e'};
    char *ss = new char[10]  {'f', 'i', 'b', 'o', 'n', 'a', 'c', 'c', 'i'};
    char *xx = new char[4]  {'f', 'i', 'b'};

    char *res1 = findx(s, x);
    char *res2 = findx(ss, xx);
    print(res1);
    print(res2);

    delete[] ss;
    delete[] xx;
    */
}

void strcmp_test()
{
    // works fine
    const char s1[] {'a', 'p', 'p', 'l', 'e'};
    const char s2[] {'b', 'a', 'n', 'a', 'n', 'a'};
    std::cout << strcmp(s1,s2) << '\n';
}

int main()
{
    try {
       
        strdup_test();
        findx_test();
        strcmp_test();

        return 0;
    }
    catch(std::exception &e) {
        std::cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Oops: something went wrong\n";
        return 2;
    }
} 

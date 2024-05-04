#include <iostream>
#include <stdexcept>

/*
 * COMMENT:
 * I compiled my source file with: g++ -O0 ex9.cpp
 * We do not want the compiler to do anything clever
 * with optimization here.
 *
 * static storage:
 * the memory addresses increases (towards higher addresses)
 * Here is the .data segment (where global/static variables are allocated)
 * that also shows the growth using <b>objdump -s -j .data a.out</b>:
 *
 * a.out:     file format elf64-x86-64
 * Contents of section .data:
    4000 00000000 00000000 08400000 00000000  .........@......
    4010 00000000 00000000 00000000 00000000  ................
    4020 01000000 00000000 00000000 00000000  ................
    4030 00000000 00000000 00000000 00000000  ................
    4040 00000000 00000000 00000000 00000000  ................
    4050 00000000 00000000 00000000 00000000  ................
    4060 00000000 00000000 00000000 00000000  ................
    4070 00000000 00000000 00000000 00000000  ................
    4080 00000000 00000000 00000000 00000000  ................
    4090 00000000 00000000 00000000 00000000  ................
    40a0 00000000 00000000 00000000 00000000  ................
    40b0 00000000 00000000 00000000 00000000  ................
    40c0 00000000 00000000 00000000 00000000  ................
    40d0 00000000 00000000 00000000 00000000  ................
    40e0 00000000 00000000 00000000 00000000  ................
    40f0 00000000 00000000 00000000 00000000  ................
    4100 00000000 00000000 00000000 00000000  ................
    4110 00000000 00000000 00000000 00000000  ................
    4120 00000000 00000000 00000000 00000000  ................
    4130 00000000 00000000 00000000 00000000  ................
    4140 00000000 00000000 00000000 00000000  ................
    4150 00000000 00000000 00000000 00000000  ................
    4160 00000000 00000000 00000000 00000000  ................
    4170 00000000 00000000 00000000 00000000  ................
    4180 00000000 00000000 00000000 00000000  ................
    4190 00000000 00000000 00000000 00000000  ................
    41a0 00000000 00000000 00000000 00000000  ................
    41b0 00000000 00000000 00000000 00000000  ................

 */

bool is_up = false;

void hoo(int *xp)
{
    int x;
    std::cout << "hoo:\t" << &x << '\n';
    if(&x < &*xp) bool is_up = false;
    else          bool is_up = true;
}

void goo(int *xp)
{
    int x;
    std::cout << "goo:\t" << &x << '\n';
    if(&x < &*xp) bool is_up = false;
    else          bool is_up = true;
    hoo(&x);
}

void foo(int *xp)
{
    int x;
    std::cout << "foo:\t" << &x << '\n';
    if(&x < &*xp) bool is_up = false;
    else          bool is_up = true;
    goo(&x);
}

int gai[100] = {1};

int main()
{
    try {
       
        // static (global) storage growth:
        std::cout << "STATIC STORAGE GROWTH:\n";
        for(int i{}; i != 100; ++i) {
            std::cout << &gai[i] << ' ';
            if(i != 0 && i % 4 == 0) std::cout << '\n';
        }
        std::cout << "\n\n";

        // stack storage growth:
        std::cout << "STACK GROWTH\n";
        int x;
        std::cout << "main:\t" << &x << '\n';
        foo(&x);
        if(is_up) std::cout << "Stack grows UP\n\n";
        else      std::cout << "Stack grows DOWN\n\n";

        // Free store (heap) growth:
        std::cout << "HEAP GROWTH\n";
        int *pai = new int[100]{1};
        for(int i{}; i != 100; ++i) {
            std::cout << &pai[i] << ' ';
            if(i != 0 && i % 4 == 0) std::cout << '\n';
        }

        delete[] pai;

        return 0;
    }
    catch(const std::exception &e) {
        std::cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        std::cerr << "Oops: something went wrong\n";
        return 2;
    }
} 

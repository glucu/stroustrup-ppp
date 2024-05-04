#include "counted_ptr.hpp"

#include <cassert>
#include <iostream>

int main() {
    // Test default constructor
    counted_ptr<int> ptr;
    assert(ptr.use_count() == 0);
    assert(ptr.operator->() == nullptr);

    // Test value constructor
    int value = 5;
    counted_ptr<int> ptr2(value);
    assert(ptr2.use_count() == 1);
    assert(*ptr2 == value);

    // Test copy constructor
    counted_ptr<int> ptr3(ptr2);
    assert(ptr2.use_count() == 2);
    assert(ptr3.use_count() == 2);

    // Test copy assignment
    counted_ptr<int> ptr4;
    ptr4 = ptr3;
    assert(ptr3.use_count() == 3);
    assert(ptr4.use_count() == 3);

    // Test move constructor
    counted_ptr<int> ptr5(std::move(ptr4));
    assert(ptr4.use_count() == 0); // After moving, the original object should have no use count.
    assert(ptr5.use_count() == 3);

    // Test move assignment
    counted_ptr<int> ptr6;
    ptr6 = std::move(ptr5);
    assert(ptr5.use_count() == 0); // After moving, the original object should have no use count.
    assert(ptr6.use_count() == 3);

    // Test dereferencing operator
    counted_ptr<int> ptr7(10);
    assert(*ptr7 == 10);

    // Test arrow operator
    struct Test {
        int value;
        Test(int v) : value(v) {}
    };
    counted_ptr<Test> ptr8(Test{5});
    assert(ptr8->value == 5);

    // Test use count
    counted_ptr<int> ptr9(10);
    counted_ptr<int> ptr10(ptr9);
    {
        counted_ptr<int> ptr11(ptr9);
        assert(ptr9.use_count() == 3);
        assert(ptr10.use_count() == 3);
        assert(ptr11.use_count() == 3);
    }
    assert(ptr9.use_count() == 2); // After ptr11 goes out of scope, the count should decrement.

    std::cout << "All tests passed!\n";

    return 0;
}

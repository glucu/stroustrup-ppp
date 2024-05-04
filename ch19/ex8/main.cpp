#include "Allocator.hpp"

#include <iostream>
#include <vector>

int main()
{
    constexpr std::size_t size{5};

    Allocator<int> allocator;

    int *arrayPtr = allocator.allocate(size);

    for (std::size_t i = 0; i < size; ++i) {
        allocator.construct(arrayPtr + i, i * 10);
    }

    std::cout << "Array values: ";
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arrayPtr[i] << " ";
    }
    std::cout << std::endl;

    for (std::size_t i = 0; i < size; ++i) {
        allocator.destroy(arrayPtr + i);
    }

    allocator.deallocate(arrayPtr, size);

    return 0;
}


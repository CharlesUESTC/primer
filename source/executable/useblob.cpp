#include <iostream>

#include "pmdynamicmemory/strblob.h"

int main()
{
    using namespace pmdynamicmemory;

    StrBlob b1;

    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        std::cout << b2.size() << std::endl;
    }
    std::cout << b1.size() << std::endl;
    std::cout << b1.front() << " " << b1.back() << std::endl;

    const StrBlob b3 = b1;
    std::cout << b3.front() << " " << b3.back() << std::endl;

    for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
    {
        std::cout << it.deref() << std::endl;
    }

    return 0;
}

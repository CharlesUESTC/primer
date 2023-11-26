#include <ios>
#include <iostream>

#include "pmcopycontrol/hasptrval.h"

HasPtrVal f(HasPtrVal hp) // HasPtr passed by value, so it is copied
{
    HasPtrVal ret = hp; // copies the given HasPtr
    // process ret
    return ret; // ret and hp are destroyed
}

int main()
{
    HasPtrVal h("hi mom!"); // allocates a new copy of "hi mom!"
    std::cout << std::boolalpha << (h.getPtr() == &*h) << "\n";
    std::cout << (f(h).getPtr() == h.getPtr()) << std::noboolalpha << std::endl; // copy constructor copies h in the call to f

    HasPtrVal h2(h);
    HasPtrVal h3 = h; // acting like values, h2, h3 points to different strings from h
    h2 = "hi dad!";
    h3 = "hi son!";
    std::cout << "h: " << *h << std::endl;
    std::cout << "h2: " << *h2 << std::endl;
    std::cout << "h3: " << *h3 << std::endl;

    // that copy is destroyed when f exits
    // h is destroyed on exit, which destroys its allocated memory
    return 0;
}

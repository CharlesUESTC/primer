#include <ios>
#include <iostream>

#include "pmcopycontrol/hasptr.h"

HasPtr f(HasPtr hp) // HasPtr passed by value, so it is copied
{
    HasPtr ret = hp; // copies the given HasPtr
    // process ret
    return ret; // ret and hp are destroyed
}

int main()
{
    HasPtr h("hi mom!"); // allocates a new copy of "hi mom!"
    std::cout << std::boolalpha << (h.getPtr() == &h.getString()) << "\n";
    std::cout << (f(h).getPtr() == h.getPtr()) << std::noboolalpha << std::endl; // copy constructor copies h in the call to f
                                                                                 // that copy is destroyed when f exits
    // h is destroyed on exit, which destroys its allocated memory
    return 0;
}

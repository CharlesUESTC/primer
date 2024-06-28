#include <ios>
#include <iostream>
#include <utility>

#include "pmcopycontrol/hasptrcnt.h"
#include "pmcopycontrol/hasptrval.h"

namespace
{
using namespace pmcopycontrol;

HasPtrVal f(HasPtrVal hp) // HasPtr passed by value, so it is copied
{
    HasPtrVal ret = hp; // copies the given HasPtr
    // process ret
    return ret; // ret and hp are destroyed
}

HasPtrCnt f(HasPtrCnt hp) // HasPtr passed by value, so it is copied
{
    HasPtrCnt ret;
    ret = hp; // assignment copies the given HasPtr
    // process ret
    return ret; // ret and hp are destroyed
}

void swapHasPtrObjs(HasPtrVal &obj1, HasPtrVal &obj2)
{
    using std::swap;
    swap(obj1, obj2);
}
} // namespace

int main()
{
    using namespace pmcopycontrol;

    HasPtrVal hv("hi mom!"); // allocates a new copy of "hi mom!"
    std::cout << std::boolalpha << (hv.getPtr() == &*hv) << "\n";
    std::cout << (f(hv).getPtr() == hv.getPtr()) << std::noboolalpha << std::endl; // copy constructor copies h in the call to f
    // that copy is destroyed when f exits
    // h is destroyed on exit, which destroys its allocated memory

    HasPtrVal hv2(hv);
    HasPtrVal hv3 = hv; // acting like values, h2, h3 points to different strings from h
    hv2 = "hi dad!";
    hv3 = "hi son!";
    std::cout << "h: " << *hv << std::endl;
    std::cout << "h2: " << *hv2 << std::endl;
    std::cout << "h3: " << *hv3 << std::endl;
    swapHasPtrObjs(hv2, hv3);
    std::cout << "h2: " << *hv2 << std::endl;
    std::cout << "h3: " << *hv3 << std::endl;

    std::cout << "\n";

    HasPtrCnt hc("hi dad!");
    std::cout << std::boolalpha << (hc.getPtr() == &*hc) << "\n";
    std::cout << (f(hc).getPtr() == hc.getPtr()) << std::noboolalpha << std::endl;

    HasPtrCnt hc2 = hc; // no new memory is allocated, h and h2 share the same underlying string
    hc = "hi mom!";
    std::cout << "h: " << *hc << std::endl;
    std::cout << "h2: " << *hc2 << std::endl;

    return 0;
}

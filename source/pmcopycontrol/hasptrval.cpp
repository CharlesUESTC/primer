#include "pmcopycontrol/hasptrval.h"

#include <string>

namespace pmcopycontrol
{

HasPtrVal &HasPtrVal::operator=(const HasPtrVal &rhs)
{
    auto newp = new std::string(*rhs.ps); // copy the underlying string;
    // Note: if delete ps first, we cannot handle self-assignment
    delete ps; // free the old memory
    ps = newp; // copy data from rhs into this object
    i = rhs.i;
    return *this; // return this object
}

void swap(HasPtrVal &a, HasPtrVal &b)
{
    a.swap(b);
}

} // namespace pmcopycontrol

namespace std
{

using pmcopycontrol::HasPtrVal;

template <>
void swap<HasPtrVal>(HasPtrVal &lhs, HasPtrVal &rhs)
{
    lhs.swap(rhs);
}

} // namespace std

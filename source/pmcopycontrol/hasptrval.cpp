#include "pmcopycontrol/hasptrval.h"

#include <string>

HasPtrVal &HasPtrVal::operator=(const HasPtrVal &rhs)
{
    auto newp = new std::string(*rhs.ps); // copy the underlying string;
    // Note: if delete ps first, we cannot handle self-assignment
    delete ps; // free the old memory
    ps = newp; // copy data from rhs into this object
    i = rhs.i;
    return *this; // return this object
}

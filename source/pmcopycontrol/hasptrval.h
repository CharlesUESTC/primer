#ifndef HASPTRVAL_H_
#define HASPTRVAL_H_

#include <string>
#include <utility>

namespace pmcopycontrol
{

// value-like implementation of HasPtr
class HasPtrVal
{
public:
    HasPtrVal(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }

    // each HasPtr has its own copy of the string to which it points
    HasPtrVal(const HasPtrVal &p): ps(new std::string(*p.ps)), i(p.i) { }

    HasPtrVal &operator=(const HasPtrVal &rhs);

    HasPtrVal &operator=(const std::string &s)
    {
        *ps = s;
        return *this;
    }

    ~HasPtrVal()
    {
        delete ps;
    }

    std::string *getPtr() const
    {
        return ps;
    }

    const std::string &operator*() const
    {
        return *ps;
    }

    std::string &operator*()
    {
        return const_cast<std::string &>(*static_cast<const HasPtrVal &>(*this));
    }

    void swap(HasPtrVal &other)
    {
        using std::swap;
        swap(ps, other.ps); // swap the pointers, not the string data
        swap(i, other.i);   // swap the int members
    }

private:
    std::string *ps;
    int i;
};

void swap(HasPtrVal &a, HasPtrVal &b);

} // namespace pmcopycontrol

namespace std
{
using pmcopycontrol::HasPtrVal;

template <>
void swap<HasPtrVal>(HasPtrVal &lhs, HasPtrVal &rhs);

} // namespace std

#endif // HASPTRVAL_H_

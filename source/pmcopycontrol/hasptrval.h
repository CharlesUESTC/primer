#ifndef HASPTRVAL_H_
#define HASPTRVAL_H_

#include <string>
#include <utility>

// value-like implementation of HasPtr
class HasPtrVal
{
    friend void swap(HasPtrVal &lhs, HasPtrVal &rhs);

public:
    HasPtrVal(const std::string &s = std::string()): ps(new std::string(s)), i(0)
    {
    }

    // each HasPtr has its own copy of the string to which it points
    HasPtrVal(const HasPtrVal &p): ps(new std::string(*p.ps)), i(p.i)
    {
    }

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

private:
    std::string *ps;
    int i;
};

inline void swap(HasPtrVal &lhs, HasPtrVal &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    swap(lhs.i, rhs.i);   // swap the int members
}

#endif // HASPTRVAL_H_

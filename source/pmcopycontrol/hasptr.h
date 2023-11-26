#ifndef HASPTR_H_
#define HASPTR_H_

#include <string>
#include <utility>

// value-like implementation of HasPtr
class HasPtr
{
    friend void swap(HasPtr &lhs, HasPtr &rhs);

public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0)
    {
    }

    // each HasPtr has its own copy of the string to which it points
    HasPtr(const HasPtr &p): ps(new std::string(*p.ps)), i(p.i)
    {
    }

    HasPtr &operator=(const HasPtr &rhs);
    HasPtr &operator=(const std::string &s)
    {
        *ps = s;
        return *this;
    }

    ~HasPtr()
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
        return const_cast<std::string &>(*static_cast<const HasPtr &>(*this));
    }

private:
    std::string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
    swap(lhs.i, rhs.i);   // swap the int members
}

#endif // HASPTR_H_

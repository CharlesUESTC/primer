#ifndef HASPTRCNT_H_
#define HASPTRCNT_H_

// reference counted version of HasPtr
#include <cstddef>
#include <string>

class HasPtrCnt
{
public:
    // constructor allocates a new string and and a new counter, which it sets to 1
    HasPtrCnt(const std::string &s = std::string()): ps(new std::string(s)), i(0), use(new std::size_t(1))
    {
    }

    // copy constructor copies all three data members and increments the counter
    HasPtrCnt(const HasPtrCnt &p): ps(p.ps), i(p.i), use(p.use)
    {
        ++*use;
    }

    HasPtrCnt &operator=(const HasPtrCnt &rhs);

    HasPtrCnt &operator=(const std::string &s)
    {
        *ps = s;
        return *this;
    }

    ~HasPtrCnt();

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
        return const_cast<std::string &>(*static_cast<const HasPtrCnt &>(*this));
    }

private:
    std::string *ps;
    int i;
    std::size_t *use; // member to keep track of how many objects share *ps
};

#endif // HASPTRCNT_H_

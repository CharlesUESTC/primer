#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <cstddef>

// forward declaration needed for friend declaration in StrBlob
class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;

    // constructors
    StrBlob(): data(std::make_shared<std::vector<std::string>>()) { }
    StrBlob(std::initializer_list<std::string> il);

    // size operations
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    // element access
    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;

    // interface to StrBlobPtr
    StrBlobPtr begin();  // can't be defined until StrBlobPtr is
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};

// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr
{
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz) { }

    std::string &deref() const;
    StrBlobPtr &incr();       // prefix version
    StrBlobPtr &decr();       // prefix version
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string &) const;

    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;      // current position within the array
};

// constructor
inline
StrBlob::StrBlob(std::initializer_list<std::string> il): 
              data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

// begin and end members for StrBlob
inline
StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline
StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();   // is the vector still around?

    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret; // otherwise, return a shared_ptr to the vector
}

std::string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];  // (*p) is the vector to which this object points
}

// prefix: return a reference to the incremented object
StrBlobPtr &StrBlobPtr::incr()
{
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::decr()
{
    // if curr is zero, decrementing it will yield an invalid subscript
    --curr;       // move the current state back one element
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

// named equality operators for StrBlobPtr
bool eq(const StrBlobPtr& lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    // if the underlying vector is the same
    if (l == r)
        // then they're equal if they're both null or
        // if they point to the same element
        return (!r || lhs.curr == rhs.curr);
    else
        return false; // if they point to difference vectors, they're not equal
}

bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs, rhs); 
}

#endif

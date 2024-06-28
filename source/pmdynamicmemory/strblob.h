#ifndef STRBLOB_H_
#define STRBLOB_H_

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

namespace pmdynamicmemory
{

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
    size_type size() const
    {
        return data->size();
    }
    bool empty() const
    {
        return data->empty();
    }

    // add and remove elements
    void push_back(const std::string &t)
    {
        data->push_back(t);
    }
    void pop_back();

    // element access
    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;

    // interface to StrBlobPtr
    StrBlobPtr begin(); // can't be defined until StrBlobPtr is
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
    friend bool neq(const StrBlobPtr &, const StrBlobPtr &);

public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }

    std::string &deref() const;
    StrBlobPtr &incr(); // prefix version
    StrBlobPtr &decr(); // prefix version
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;

    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; // current position within the array
};

// constructor
inline StrBlob::StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) { }

// begin and end members for StrBlob
inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

} // namespace pmdynamicmemory

#endif // STRBLOB_H_

#include "salesdata.h"

#include <iostream>
#include <string>

using std::istream;
using std::ostream;

SalesData::SalesData(istream &is)
{
    // read will read a transaction from is into this object
    read(is, *this);
}

// add the value of the given SalesData into this object
SalesData &SalesData::combine(const SalesData &rhs)
{
    units_sold += rhs.units_sold; // add the members of rhs into
    revenue += rhs.revenue;       // the members of ``this'' object

    return *this; // return the object on which the function was called
}

SalesData add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;  // copy data members from lhs into sum
    sum.combine(rhs);      // add data members from rhs into sum

    return sum;
}

// transactions contain ISBN, number of copies sold, and sales price
istream &read(istream &is, SalesData &item)
{
    double price = 0;

    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;

    return is;
}

ostream &print(ostream &os, const SalesData &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();

    return os;
}

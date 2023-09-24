#ifndef SALESDATA_H_
#define SALESDATA_H_

#include <iostream>
#include <string>

class SalesData
{
    friend SalesData add(const SalesData &, const SalesData &);
    friend std::istream &read(std::istream &, SalesData &);
    friend std::ostream &print(std::ostream &, const SalesData &);

public:
    // constructors
    SalesData() = default;
    SalesData(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n)
    {
    }
    SalesData(const std::string &s): bookNo(s)
    {
    }
    SalesData(std::istream &);

    // operations on SalesData objects
    std::string isbn() const
    {
        return bookNo;
    }
    SalesData &combine(const SalesData &);

private:
    double avg_price() const
    {
        return units_sold ? revenue / units_sold : 0;
    }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// nonmember SalesData interface functions
SalesData add(const SalesData &, const SalesData &);
std::istream &read(std::istream &, SalesData &);
std::ostream &print(std::ostream &, const SalesData &);

#endif // SALESDATA_H_

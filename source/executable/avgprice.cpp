#include <iostream>

#include "pmclasses/salesdata.h"

int main()
{
    using namespace pmclasses;

    SalesData total; // variable to hold data for the next transaction

    // read the first transaction and ensure that there are data to process
    if (read(std::cin, total))
    {
        SalesData trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (read(std::cin, trans))
        {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans); // update the running total
            }
            else
            {
                // print results for the previous book
                print(std::cout, total) << std::endl;
                total = trans; // total now refers to the next book
            }
        }
        print(std::cout, total) << std::endl; // print the last transaction
    }
    else
    {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
    }

    return 0;
}

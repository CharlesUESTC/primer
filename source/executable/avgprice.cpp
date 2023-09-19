#include <iostream>

#include "pmclasses/salesdata.h"

using std::cerr; using std::cin; using std::cout; using std::endl;

int main()
{
    SalesData total; // variable to hold data for the next transaction

    // read the first transaction and ensure that there are data to process
    if (read(cin, total)) {
        SalesData trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (read(cin, trans)) {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn())
                total.combine(trans); // update the running total
            else {
                // print results for the previous book
                print(cout, total) << endl;
                total = trans;  // total now refers to the next book
            }
        }
        print(cout, total) << endl; // print the last transaction
    }
    else {
        // no input! warn the user
        cerr << "No data?!" << endl;
    }

    return 0;
}

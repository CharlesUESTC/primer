#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "pmdynamicmemory/queryresult.h"
#include "pmdynamicmemory/textquery.h"

void runQueries(std::ifstream &infile)
{
    using namespace pmdynamicmemory;

    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile); // store the file and build the query map
    // interact with the user: prompt a word to find and print results
    for (;;)
    {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(std::cin >> s) || s == "q")
        {
            break;
        }
        // run the query and print the results
        print(std::cout, tq.query(s)) << std::endl;
    }
}

// program takes single argument specifying the file to query
int main(int argc, char **argv)
{
    // open the file from which user will query words
    std::ifstream infile;
    // open returns void, so we use the comma operator XREF(commaOp)
    // to check the state of infile after the open
    if (argc < 2 || !(infile.open(argv[1]), infile))
    {
        std::cerr << "No input file!" << std::endl;
        return EXIT_FAILURE;
    }
    runQueries(infile);
    return 0;
}

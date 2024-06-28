#ifndef QUERYRESULT_H_
#define QUERYRESULT_H_

#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

namespace pmdynamicmemory
{

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
        : keyword(s), lines(p), file(f)
    {
    }

private:
    std::string keyword;                            // word this query represents
    std::shared_ptr<std::set<line_no>> lines;       // lines it's on
    std::shared_ptr<std::vector<std::string>> file; // input file
};

std::ostream &print(std::ostream &os, const QueryResult &qr);

} // namespace pmdynamicmemory

#endif // QUERYRESULT_H_

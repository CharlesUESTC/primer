#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "pmdynamicmemory/queryresult.h"

namespace pmdynamicmemory
{

class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &is);
    QueryResult query(const std::string &keyword) const;

private:
    static std::string cleanupStr(const std::string &word);

    std::shared_ptr<std::vector<std::string>> file; // input file
    // map each word to teh set of the lines in which that word appears
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

} // namespace pmdynamicmemory

#endif // TEXTQUERY_H_

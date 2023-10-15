#include "pmdynamicmemory/textquery.h"

#include <cctype>
#include <fstream>
#include <memory>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "pmdynamicmemory/queryresult.h"
#include "pmfunctions/makeplural.h"

TextQuery::TextQuery(std::ifstream &is): file(std::make_shared<std::vector<std::string>>())
{
    std::string text;
    line_no ln = 0;
    while (std::getline(is, text)) // for each line in the file
    {
        file->push_back(text);         // remember this line of text
        std::istringstream line(text); // separate the line into words
        std::string word;
        while (line >> word) // for each word in that line
        {
            word = cleanupStr(word);
            // if word isn't already in wm, subscripting adds a new entry
            auto &lines = wm[word]; // lines is a shared_ptr
            if (lines == nullptr)   // that pointer is null the first time we see word
            {
                lines.reset(new std::set<line_no>()); // allocate a new set
            }
            lines->insert(ln); // insert this line number
        }
        ++ln; // the next line number
    }
}

QueryResult TextQuery::query(const std::string &keyword) const
{
    // we'll return a pointer to this set if we don't find keyword
    static std::shared_ptr<std::set<line_no>> no_data(std::make_shared<std::set<line_no>>());

    // use find and not a subscript to avoid adding words to wm!
    if (auto res = wm.find(cleanupStr(keyword)); res != wm.end())
    {
        return QueryResult(keyword, res->second, file);
    }
    else
    {
        return QueryResult(keyword, no_data, file);
    }
}

// not covered in the book -- cleanupStr removes
// punctuation and converts all text to lowercase so that
// the queries operate in a case insensitive manner
std::string TextQuery::cleanupStr(const std::string &word)
{
    std::string ret;
    for (auto it = word.cbegin(); it != word.cend(); ++it)
    {
        if (!std::ispunct(*it) || *it == '\'')
        {
            ret += static_cast<char>(std::tolower(*it));
        }
    }
    return ret;
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.keyword << " occurs " << qr.lines->size() << " " << makePlural(qr.lines->size(), "time", "s") << std::endl;

    // print each line in which the word appeared
    for (auto num : *qr.lines) // for every element in the set
    {
        // don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") " << *(qr.file->cbegin() + num) << std::endl;
    }

    return os;
}

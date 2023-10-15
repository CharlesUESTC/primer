#ifndef MAKEPLURAL_H_
#define MAKEPLURAL_H_

#include <cstddef>
#include <string>

// return the plural version of word if ctr is greater than 1
inline std::string makePlural(std::size_t ctr, const std::string &word, const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

#endif // MAKEPLURAL_H_

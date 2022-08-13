#ifndef INCLUDED_PRIVILEGEDONE_
#define INCLUDED_PRIVILEGEDONE_

#include <iostream>
#include <vector>
#include <memory>

#include "noentry.h"

class PrivilegedOne
{
    std::vector<std::unique_ptr<NoEntry>> d_noEntry;

    public:
        PrivilegedOne(std::string const &fname);

        void print()
        {
            for (size_t idx = 0; idx < d_noEntry.size(); ++idx)
                std::cout << d_noEntry[idx]->name() << '\n';
        }

    private:
        NoEntry nextEntry(std::istream &in);    // empty name: all were read
};

#endif
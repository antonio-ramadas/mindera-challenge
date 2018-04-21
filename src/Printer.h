#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <utility>
#include <vector>
#include <set>

using namespace std;

typedef unsigned int uint;
typedef vector<vector<int> > vecint2d;

class Printer {
    public:
        void static printGroups(const vector<set<pair<uint, uint> > > &groups);
};

#endif
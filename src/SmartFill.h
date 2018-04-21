#ifndef SMART_FILL_H
#define SMART_FILL_H

#include <utility>
#include <vector>
#include <set>
#include <map>

#include "Algorithm.h"

using namespace std;

typedef unsigned int uint;
typedef vector<vector<int> > vecint2d;

class SmartFill : public Algorithm {
    public:
        SmartFill(const vecint2d &grid);
        vector<set<pair<uint, uint> > > solve();
};

#endif
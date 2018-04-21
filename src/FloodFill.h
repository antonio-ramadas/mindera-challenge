#ifndef FLOOD_FILL_H
#define FLOOD_FILL_H

#include <utility>
#include <vector>
#include <set>

#include "Algorithm.h"

using namespace std;

typedef unsigned int uint;
typedef vector<vector<int> > vecint2d;

class FloodFill : public Algorithm {
    private:
        void fill(vecint2d &grid, uint i, uint j, set<pair<uint, uint> > &group);
    public:
        FloodFill(const vecint2d &grid);
        vector<set<pair<uint, uint> > > solve();
};

#endif
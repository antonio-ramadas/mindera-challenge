#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <utility>
#include <vector>
#include <set>

using namespace std;

typedef unsigned int uint;
typedef vector<vector<int> > vecint2d;

class Algorithm {
    protected:
        vecint2d grid;
    public:
        Algorithm(const vecint2d &grid);
        virtual vector<set<pair<uint, uint> > > solve() = 0;
};

#endif
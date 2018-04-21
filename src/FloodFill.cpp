#include "FloodFill.h"

FloodFill::FloodFill(const vecint2d &grid) : Algorithm(grid) {}

// From https://en.wikipedia.org/wiki/Flood_fill
// Temporal complexity: (n^4) * n * log(n)
vector<set<pair<uint, uint> > > FloodFill::solve() {
    vector<set<pair<uint, uint> > > groups;
    
    for (uint i = 0; i < grid.size(); i++) {
        for (uint j = 0; j < grid.at(i).size(); j++) {
            if (0 >= grid.at(i).at(j)) {
                continue;
            }
            
            set<pair<uint, uint> > group;
            fill(grid, i, j, group);
            if (group.size() > 1) {
                groups.push_back(group);
            }
        }
    }
    return groups;
}

void FloodFill::fill(vecint2d &grid, uint i, uint j, set<pair<uint, uint> > &group) {
    if (i >= grid.size() || j >= grid.at(i).size() || 0 >= grid.at(i).at(j)) {
        return;
    }
    
    grid.at(i).at(j) *= -1;
    
    group.insert(make_pair(i, j));
    
    fill(grid, i, j-1, group);
    fill(grid, i, j+1, group);
    fill(grid, i-1, j, group);
    fill(grid, i+1, j, group);
}
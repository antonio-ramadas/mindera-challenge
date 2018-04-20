#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

typedef unsigned int uint;
typedef vector<vector<int> > vecint2d;

vecint2d readGrid(const string &filename) {
    vecint2d grid;

    ifstream gridFile;
    gridFile.open ("grids/" + filename);

    string line;

    while (getline(gridFile, line)) {
        vector<int> row;
        for (char cell : line) {
            if ('0' == cell || '1' == cell) {
                row.push_back(cell - '0');
            }
        }
        if (row.size() > 0) {
            grid.push_back(row);
        }
    }

    gridFile.close();

    return grid;
}

vecint2d getGrid(const int &option = 0) {
    switch (option) {
        case 0:
            return {
                    {0,0,0,1,0,0,1,1},
                    {0,0,1,1,1,0,1,1},
                    {0,0,0,0,0,0,1,0},
                    {0,0,0,1,0,0,1,1},
                    {0,0,0,1,0,0,1,1}
                   };
        case 1:
            return readGrid("100x100.json");
        case 2:
            return readGrid("1000x1000.json");
        case 3:
            return readGrid("10000x10000.json");
        default: //case 4:
            return readGrid("20000x20000.json");
    }
}

void printGroups(const vector<set<pair<uint, uint> > > &groups) {
     for (set<pair<uint, uint> > group : groups) {
        cout << "[";
        
        bool isFirst = true;
        
        for (pair<uint, uint> p : group) {
            if (isFirst) {
                isFirst = false;
            } else {
                cout << ",";
            }
            cout << " [" << p.first << "," << p.second << "]";
        }
        
        cout << " ]" << endl;
    }
}

void fill(vecint2d &grid, uint i, uint j, set<pair<uint, uint> > &group) {
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

// From https://en.wikipedia.org/wiki/Flood_fill
// Temporal complexity: (n^4) * n * log(n)
vector<set<pair<uint, uint> > > floodFill(vecint2d grid) {
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

vector<set<pair<uint, uint> > > smartFill(vecint2d grid) {
    int counter = -1;

    map<int, set<pair<uint, uint> > > buckets;
    map<int, int> mappedGroups;

    for (uint i = 0; i < grid.size(); i++) {
        for (uint j = 0; j < grid.at(i).size(); j++) {
            if (0 >= grid.at(i).at(j)) {
                continue;
            }

            const int GROUP_NOT_FOUND = 1;

            int up = GROUP_NOT_FOUND, left = GROUP_NOT_FOUND;

            if (0 < i && 0 > grid.at(i-1).at(j)) {
                up = grid.at(i-1).at(j);
            }

            if (0 < j && 0 > grid.at(i).at(j-1)) {
                left = grid.at(i).at(j-1);
            }

            if (up == GROUP_NOT_FOUND && left == GROUP_NOT_FOUND) {
                grid.at(i).at(j) = --counter;
                buckets[counter] = set<pair<uint, uint> >({make_pair(i,j)});
            } else if (up == GROUP_NOT_FOUND || left == GROUP_NOT_FOUND || up == left) {
                int prevCnt = up == GROUP_NOT_FOUND ? left : up;

                while (mappedGroups.find(prevCnt) != mappedGroups.end()) {
                    prevCnt = mappedGroups[prevCnt];
                }

                grid.at(i).at(j) = prevCnt;

                buckets[prevCnt].insert(make_pair(i,j));
            } else { // both different
                set<pair<uint, uint> > dest;

                for (pair<uint, uint> p : buckets[up]) {
                    dest.insert(p);
                }

                for (pair<uint, uint> p : buckets[left]) {
                    dest.insert(p);
                }
                
                buckets[max(up, left)] = dest;

                buckets[max(up, left)].insert(make_pair(i,j));

                grid.at(i).at(j) = max(up, left);

                buckets.erase(min(up, left));
                mappedGroups[min(up, left)] = max(up, left);
            }
        }
    }

    vector<set<pair<uint, uint> > > groups;

    for (auto it=buckets.crbegin(); it!=buckets.crend(); it++) {
        if ((it->second).size() > 1) {
            groups.push_back(it->second);
        }
    }

    return groups;
}

int main() {
    vecint2d grid = getGrid(2);
    
    //vector<set<pair<uint, uint> > > ff = floodFill(grid);
    vector<set<pair<uint, uint> > > sf = smartFill(grid);

    printGroups(sf);
    
    return 0;
}
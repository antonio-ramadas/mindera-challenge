#include "SmartFill.h"

SmartFill::SmartFill(const vecint2d &grid) : Algorithm(grid) {}

vector<set<pair<uint, uint> > > SmartFill::solve() {
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
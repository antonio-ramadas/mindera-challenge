#include "Printer.h"

void Printer::printGroups(const vector<set<pair<uint, uint> > > &groups) {
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
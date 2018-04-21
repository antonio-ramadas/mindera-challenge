#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <set>

using namespace std;

typedef unsigned int uint;
typedef vector<vector<int> > vecint2d;

#include "Printer.h"
#include "Parser.h"
#include "FloodFill.h"
#include "SmartFill.h"

int main(int argc, char* argv[]) {
    int gridOpt = 0, solver = 0;

    if (argc != 1 && argc != 3) {
        cerr << "Usage: " << argv[0] << " <GRID_OPT> <SOLVER_OPT>" << endl;
        cerr << "\t 0 <= GRID_OPT <= 4" << endl;
        cerr << "\t 0 <= SOLVER_OPT <= 1" << endl;
        return 1;
    }

    if (argc == 1) {
        cout << "Initialized default values:" << endl;
        cout << "\t GRID_OPT = " << gridOpt << endl;
        cout << "\t SOLVER_OPT = " << solver << endl << endl;
    } else {
        sscanf(argv[1], "%d", &gridOpt);
        sscanf(argv[2], "%d", &solver);
    }

    vecint2d grid = Parser(gridOpt).getGrid();

    vector<set<pair<uint, uint> > > groups;

    switch (solver) {
        case 0:
            groups = FloodFill(grid).solve();
            break;
        default: //case 1:
            groups = SmartFill(grid).solve();
            break;
    }

    Printer::printGroups(groups);
    
    return 0;
}
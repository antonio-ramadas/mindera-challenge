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

int main() {
    vecint2d grid = Parser(0).getGrid();

    //vector<set<pair<uint, uint> > > ff = FloodFill(grid).solve();
    vector<set<pair<uint, uint> > > sf = SmartFill(grid).solve();

    Printer::printGroups(sf);
    
    return 0;
}
#include "Parser.h"

Parser::Parser(const int &gridOpt) {
    option = gridOpt;
}

vecint2d Parser::readGrid(const string &filename) {
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

vecint2d Parser::getGrid() {
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
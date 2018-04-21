#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <fstream>

using namespace std;

typedef unsigned int uint;
typedef vector<vector<int> > vecint2d;

class Parser {
    private:
        int option;
        vecint2d readGrid(const string &filename);
    public:
        Parser(const int &gridOpt = 0);
        vecint2d getGrid();
};

#endif
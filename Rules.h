#include <iostream>

using namespace std;

class Rules{

  private:
    int row;
    int column;
    char **grid;
    char **grid_copy;
    float popDensity;
    string temporary;

  public:
    Rules();
    Rules(int row, int column, float popDensity);
    Rules(int row, int column, string temporary);
    ~Rules();

    char** randGen();
    char** fileGen();
    int getRow();
    int getColumn();



};

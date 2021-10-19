/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 3
    Header file for doughnutMode class
    */

    #ifndef DOUGHNUTMODE_H
    #define DOUGHNUTMODE_H

    #include <iostream>

    using namespace std;

    class DoughnutMode{
    private:
    int neighbors;
    int row;
    int column;
    char **grid;
    char **grid_copy;

  //methods
  public:
    DoughnutMode();
    DoughnutMode(int row, int column, char** grid);
    ~DoughnutMode();
    void simulation();
    void makeGrid(int i, int j, int neighbors);
    char** printGrid();
    char** fileOut(string fileInput, int count);
    bool isEqual();

    };




    #endif

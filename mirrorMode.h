/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 3
    header file for mirrorMode class
    */

    #ifndef MIRRORMODE_H
    #define MIRRORMODE_H

    #include <iostream>

    using namespace std;

 class MirrorMode{
    private:
    int neighbors;
    int row;
    int column;
    char **grid;
    char **grid_copy;

  public:
    MirrorMode();
    MirrorMode(int row, int column, char** grid);
    ~MirrorMode();
    void simulation();
    void makeGrid(int i, int j, int neighbors);
    char** printGrid();
    char** fileOut(string fileInput, int count);
    bool isEqual();


    };
    



    #endif

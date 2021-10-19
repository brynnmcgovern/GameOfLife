/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 3
    Header file for class ClassicMode
    */

#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include <iostream>

using namespace std;

class ClassicMode{
private:
    int neighbors;
    int row;
    int column;
    char **grid;
    char **grid_copy;


  
  public:
    ClassicMode();
    ClassicMode(int row, int column, char** grid);
    ~ClassicMode();
    void simulation();
    void makeGrid(int i, int j, int neighbors);
    char** printGrid();
    char** fileOut(string fileInput, int count);
    bool isEqual();


};


#endif

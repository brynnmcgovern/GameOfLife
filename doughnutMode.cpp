/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 3
    Implementation of doughnutMode class
    */

    #include "doughnutMode.h"
    #include <iostream>
    #include <fstream>
    #include <chrono>
    #include <thread>

    using namespace std;
    using namespace std::this_thread;
    using namespace std::chrono;


/**
constructor
*/
DoughnutMode::DoughnutMode(){
  neighbors = 0;
  row = 0;
  column = 0;
}

/**
overloaded constructor
*/
DoughnutMode::DoughnutMode(int r, int c, char** b){
  row = r;
  column  = c;

  grid = b;
  grid_copy = new char *[row];
  	for(int i = 0; i < row ; i++){
  		   grid_copy[i] = new char[column];
  	}
}

//destructor
DoughnutMode::~DoughnutMode(){
  delete grid;
  delete grid_copy;
}
/**
function to make grid
*/
void DoughnutMode::simulation(){

  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){

      neighbors = 0;

      if((i == 0) && (j == 0)){
        if(grid[i][j+1] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j+1] == 'X'){
          neighbors++;
        }
          if(grid[i][j+(column-1)] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j+(column-1)] == 'X'){
          neighbors++;
        }
          if(grid[i + (row-1)][j +(column - 1)] == 'X'){
          neighbors++;
        }
          if(grid[i + (row-1)][j] == 'X'){
          neighbors++;
        }
          if(grid[i + (row-1)][j+1] == 'X'){
          neighbors++;
        }

        makeGrid(i, j, neighbors);
        neighbors = 0;

      }
        else if((i == 0) && (j == (column - 1))){
        if(grid[i][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j] == 'X'){
          neighbors++;
        }
          if(grid[i + (row - 1)][j] == 'X'){
          neighbors++;
        }
          if(grid[i + (row - 1)][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i + (row - 1)][0] == 'X'){
          neighbors++;
        }
          if(grid[i][0] == 'X'){
          neighbors++;
        }
          if(grid[i + 1][0] == 'X'){
          neighbors++;
        }

        makeGrid(i, j, neighbors);
        neighbors = 0;

      }
        else if((i == (row - 1)) && (j == (column - 1))){
          if(grid[i][j-1] == 'X'){
            neighbors++;
          }
          if(grid[i-1][j] == 'X'){
            neighbors++;
          }
          if(grid[i-1][j-1] == 'X'){
            neighbors++;
          }
          if(grid[0][j] == 'X'){
            neighbors++;
          }
          if(grid[0][j-1] == 'X'){
            neighbors++;
          }
          if(grid[0][0] == 'X'){
            neighbors++;
          }
          if(grid[i][0] == 'X'){
            neighbors++;
          }
          if(grid[i-1][0] == 'X'){
            neighbors++;
          }

          makeGrid(i, j, neighbors);
          neighbors = 0;

      }
        else if((i == (row - 1)) && (j == 0)){
        if(grid[i][j+1] == 'X'){
          neighbors++;
        }
          if(grid[i-1][j] == 'X'){
          neighbors++;
        }
          if(grid[i-1][j+1] == 'X'){
          neighbors++;
        }
          if(grid[0][0] == 'X'){
          neighbors++;
        }
          if(grid[0][j+1] == 'X'){
          neighbors++;
        }
          if(grid[0][j+(column - 1)] == 'X'){
          neighbors++;
        }
          if(grid[i][j + (column - 1)] == 'X'){
          neighbors++;
        }
          if(grid[i-1][j + (column - 1)] == 'X'){
          neighbors++;
        }


        makeGrid(i, j, neighbors);
        neighbors = 0;

      }
        else if((!(i == 0) || (!(i == (row - 2)))) && (j == 0)){
        if(grid[i-1][j] == 'X'){
          neighbors++;
        }
          if(grid[i-1][j+1] == 'X'){
          neighbors++;
        }
          if(grid[i][j+1] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j+1] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j] == 'X'){
          neighbors++;
        }
          if(grid[i][j+(column -1)] == 'X'){
          neighbors++;
        }
          if(grid[i-1][j+(column -1)] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j+(column -1)] == 'X'){
          neighbors++;
        }

        makeGrid(i, j, neighbors);
        neighbors = 0;

      }
        else if((0 < i <= (row - 2)) && (j == (column - 1))){
        if(grid[i-1][j] == 'X'){
          neighbors++;
        }
          if(grid[i-1][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j] == 'X'){
          neighbors++;
        }
          if(grid[i][0] == 'X'){
          neighbors++;
        }
          if(grid[i-1][0] == 'X'){
          neighbors++;
        }
          if(grid[i+1][0] == 'X'){
          neighbors++;
        }

        makeGrid(i, j, neighbors);
        neighbors = 0;

      }
        else if((i == 0) && (0 < j <= (column - 2))){
        if(grid[i][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j+1] == 'X'){
          neighbors++;
        }
          if(grid[i][j+1] == 'X'){
          neighbors++;
        }
          if(grid[i+(row - 1)][j] == 'X'){
          neighbors++;
        }
          if(grid[i+(row - 1)][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i+(row - 1)][j+1] == 'X'){
          neighbors++;
        }
        makeGrid(i, j, neighbors);
        neighbors = 0;

      }
        else if((i == (row - 1)) && (0 < j <= (column - 2))){
        if(grid[i][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i-1][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i-1][j] == 'X'){
          neighbors++;
        }
          if(grid[i-1][j+1] == 'X'){
          neighbors++;
        }
          if(grid[i][j+1] == 'X'){
          neighbors++;
        }
          if(grid[0][j] == 'X'){
          neighbors++;
        }
          if(grid[0][j-1] == 'X'){
          neighbors++;
        }
          if(grid[0][j+1] == 'X'){
          neighbors++;
        }

        makeGrid(i, j, neighbors);
        neighbors = 0;

      }
        else{
        if(grid[i-1][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i-1][j] == 'X'){
          neighbors++;
        }
          if(grid[i-1][j+1] == 'X'){
          neighbors++;
        }
          if(grid[i][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i][j+1] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j-1] == 'X'){
          neighbors++;
        }
          if(grid[i+1][j] == 'X'){
          neighbors++;

        }
          if(grid[i+1][j+1] == 'X'){
          neighbors++;
        }

        makeGrid(i, j, neighbors);
        neighbors = 0;
      }
    }
  }
}

//Method for creating copy of grid
void DoughnutMode::makeGrid(int i, int j, int count){

    if(count == 3){
      grid_copy[i][j] = 'X';

    }
    else if(count == 4){
      grid_copy[i][j] = '-';

    }
    else if(count == 1 || count == 0){
      grid_copy[i][j] = '-';

    }
    else if(count == 2){
      grid_copy[i][j] = grid[i][j];
    }
    else{
      grid_copy[i][j] = '-';
    }
}

//Method for printing grid
char** DoughnutMode::printGrid(){

  if(grid == grid_copy){
    cout << "Grids are the same" << endl;

  }
  for(int i = 0; i < row; i++){
    cout << endl;
    for(int j = 0; j < column; j++){
     cout << grid_copy[i][j] << "\t";
    }
  }
  cout << endl;
  return grid_copy;
}

//Printing grid to a file
char** DoughnutMode::fileOut(string fileInput, int count){

  ofstream outputFile;

  outputFile.open(fileInput, fstream::app);

  outputFile << "Grid: " << count << endl;

  for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
       outputFile << grid_copy[i][j] << "\t";
      }
      outputFile << "\n";
    }
    outputFile << endl;
    outputFile.close();
    return grid_copy;
}

//Method for checking if grids are equal
bool DoughnutMode::isEqual(){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
        if (grid[i][j] != grid_copy[i][j]){
            return false;
        }
      }
    }
  return true;
}

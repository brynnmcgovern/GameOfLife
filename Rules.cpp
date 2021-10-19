#include "Rules.h"
#include <iostream>
#include <fstream>

using namespace std;

//default constructor
Rules::Rules(){
  row = 0;
  column  = 0;
  popDensity = 0;
  temporary = "";
}

//constructor for generating random values
Rules::Rules(int r, int c, float p){
  row = r;
  column  = c;
  popDensity = p;
}

//constructor for file 
Rules::Rules(int r, int c, string t){
  row = r;
  column  = c;
  temporary = t;
}

//destructor
Rules::~Rules(){
  delete grid;
}

char** Rules::randGen(){
  srand(time(0)); //to make the rand actually random - README

  grid = new char *[row];
		for(int i = 0; i < row ; i++){
		    grid[i] = new char[column];
		}

  grid_copy = new char *[row];
  	for(int i = 0; i < row ; i++){
  		   grid_copy[i] = new char[column];
  	}

  int mult = row * column;
  int cells = mult * popDensity;
  int i = 0;

  while(i < cells){
      int a =  rand() % row;
      int b =  rand() % column;

      if(grid[a][b] == 'X'){
        continue;
      }
    else{
        grid[a][b] = 'X';
        grid_copy[a][b] = 'X';
        i++;
      }
    }

    cout << "Gen 0" << endl;
    for(int i = 0; i < row; i++){
      cout << endl;
      for(int j = 0; j < column; j++){
        if(!(grid[i][j] == 'X')){
          grid[i][j] = '-'; 
          grid_copy[i][j] = '-';
        }
        cout << grid[i][j] << "\t";
      }
    }
    cout << endl;
    return grid;
  }

  //method for the genration from file input
  char** Rules::fileGen(){

    grid = new char *[row];
  		for(int i = 0; i < row ; i++){
  		    grid[i] = new char[column];
  		}

    grid_copy = new char *[row];
    	for(int i = 0; i < row ; i++){
    		   grid_copy[i] = new char[column];
    	}

      int count = 2;

      cout << "Gen 0" << endl;
        for(int i = 0; i < row; i++){
          cout << endl;
          for(int j = 0; j < column; j++){
              grid[i][j] = char(temporary[count]);
              grid_copy[i][j] = char(temporary[count]);
              count++;

              cout << grid[i][j] << "\t";
            }
        }
        cout << endl;
        return grid;
    }

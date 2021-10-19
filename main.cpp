//used 1 late day
/** Brynn McGovern
    2370579
    bmcgovern@chapman.edu
    CPSC 350 section 1
    Assignment 3
    Main method; asks for user input and which game mode they want, how they want the input,
    and whether they want a randomized starting grid or to use one from a file
    creates pointers for each game mode
    */

#include "Rules.h"
#include "classicMode.h"
#include "doughnutMode.h"
#include "mirrorMode.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (){

  string filePick;
  string gridPick;
  string pause;
  int config  = 0;
  bool loop = true;
  bool mainLoop = true;
  int row;
  int column;
  float popDensity;
  string file;
  string fileInput;
  char** grid;
  char** grid_copy;
  char answer;
  string slow;
  int check = 0;


  while(loop){
    cout << "Do you wish to start with a random configuration, or specify a flatfile configuration" << endl;
    cout << "Enter 1 for random or 2 for flatfile: ";
    cin >> config;

    //random values configuration
    if(config == 1){
      cout << "Please enter the dimenisions for the world" << endl;

      cout << "Enter rows: ";
      cin >> row;
      cout << "Enter columns: ";
      cin >> column;

      cout << "Enter a decimal for the population density (0 - 1): ";
      cin >> popDensity;

      if(0 < popDensity <= 1 ){
        cout << "Not a valid number, please try again: ";
        cin >> popDensity;
      }

      //makes grid, and uses Rules
      Rules* r = new Rules(row, column, popDensity);
      grid = r->randGen();

      loop = false;

    //grid from file
    }
      else if(config == 2){

      string temporary = "";
      string line = "";

      cout << "Enter the file: ";
      cin >> file;

      ifstream inputfile(file);

      if(inputfile.fail()){
        cout << "File doesnt exist, please try again with file that exists" << endl;
        cout << endl;
        continue;
      }

      while(getline(inputfile, line)){
        temporary += line;
      }

      row = int(temporary[0]) - 48;
      column = int(temporary[1]) - 48;

      Rules* r = new Rules(row, column, temporary);
      grid = r->fileGen();

      loop = false;

    //else case, repromtps user
    }
      else{
      cout << "Please enter 1 or 2: " << endl;
      loop = true;
      continue;
    }
  }

  //loop of the simulation with the different modes
  while(mainLoop){

    //user chooses game mode
    cout << "Pick a grid to begin to play: classic (c), doughnut (d), mirror (m): ";
    cin >> gridPick;

    cout << "Would you like the grids mapped to a file (y/n): ";
    cin >> filePick;

    if(filePick == "y"){
      cout << "Enter output file name: ";
      cin >> fileInput;

    }if(filePick == "n"){
      cout << "Would you like automatic pauses between grids or press the key 'y'?" << endl;
      cout << "Press 'y' for automatic pauses and 'n' for using the key: ";
      cin >> pause;
    }

    int count = 0;

    //ClassicMode loop
    if((gridPick == "c") || (gridPick == "classic")){


        if(filePick == "y"){

            ofstream output;

            output.open (fileInput);
            output << "grid 0" << endl;

            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                 output << grid[i][j] << "\t";
                }
                output << "\n";
              }
              output << endl;
              output.close();
              count++;

            while(count < 100){

              ClassicMode* c = new ClassicMode(row, column, grid);

              c->simulation();

              grid = c->fileOut(fileInput, count);
              count++;

              if(c->isEqual()){
                check++;

                if(check == 5){
                  cout << "Grid stablizes or is empty, program will end" << endl;
                  cout << "The output in " << fileInput << endl;
                  break;
                }
              }
                else{
                continue;
              }
            }


      }
        else if (filePick == "n"){

          if(pause == "y"){
            while(count < 1000){

              ClassicMode* c = new ClassicMode(row, column, grid);

              count++;

              c->simulation();

              cout << endl;
              cout << "Generation number: " << count << endl;
              cout << endl;

              grid = c->printGrid();

              for(int i = 0; i < 1000; i++){
                for(int i = 0; i < 70000; i++){
                  slow+=i;
                }
                slow += i;
              }

              if(c->isEqual()){
                check++;

                if(check == 5){
                  cout << "Grid stablizes or is empty, program will end" << endl;
                  break;
                }
              }
                else{
                continue;
              }
            }

          }else if(pause == "n"){

            while(count < 100){

              ClassicMode* c = new ClassicMode(row, column, grid);

              count++;

              //Entering simulation method

              c->simulation();

              cout << endl;
              cout << "Generation number: " << count << endl;
              cout << endl;

              grid = c->printGrid();

              cout << "Press 'y' to continue: ";
              cin >> answer;

              if(c->isEqual()){
                check++;

                if(check == 5){
                  cout << "Grid stablizes or is empty, program will end" << endl;
                  cout << "Press 'y' to quit: ";
                  cin >> answer;
                  if(answer == 'y'){
                    break;
                  }
              }
                  else{
                continue;
              }
            }
          }
        }
      }

      mainLoop = false;

    //Doughnut Mode loop
    }else if((gridPick == "d") || (gridPick == "doughnut")){

      if(filePick == "y"){

      ofstream output;

      output.open (fileInput);
      output << "Generation 0" << endl;

      for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            output << grid[i][j] << "\t";
          }
          output << "\n";
        }
        output << endl;
        output.close();
        count++;

        while(count < 100){

          DoughnutMode* d = new DoughnutMode(row, column, grid);

          d->simulation();

          grid = d->fileOut(fileInput, count);
          count++;

          if(d->isEqual()){
            check++;

            if(check == 5){
              cout << "Grid stablizes or is empty, program will end" << endl;
              cout << "The output in " << fileInput << endl;
              break;
            }
          }
            else{
            continue;
          }
        }

      }
        else if (filePick == "n"){
        if(pause == "y"){

          while(count < 1000){

            DoughnutMode* d = new DoughnutMode(row, column, grid);

            count++;

            d->simulation();

            cout << endl;
            cout << "Generation number: " << count << endl;
            cout << endl;

            grid = d->printGrid();

            for(int i = 0; i < 1000; i++){
              for(int i = 0; i < 70000; i++){
                slow+=i;
              }
              slow += i;
            }

            if(d->isEqual()){
              check++;

              if(check == 5){
                cout << "Grid stablizes or is empty, program will end" << endl;
                break;
              }
            }
              else{
              continue;
            }
          }

      }
        else if(pause == "n"){

        while(count < 100){

          DoughnutMode* d = new DoughnutMode(row, column, grid);

          count++;

          d->simulation();

          cout << endl;
          cout << "Generation number: " << count << endl;
          cout << endl;

          grid = d->printGrid();

          cout << "Press 'y' to continue: ";
          cin >> answer;

          if(d->isEqual()){
            check++;

            if(check == 5){
              cout << "Grid stablizes or is empty, program will end" << endl;
              cout << "Press 'y' to quit: ";
              cin >> answer;
              if(answer == 'y'){
                break;
              }
            }
              else{
              continue;
          }
        }
      }
    }
  }

  mainLoop = false;

  //Mirror Mode loop
  }
      else if((gridPick == "m") || (gridPick == "mirror")){


    if(filePick == "y"){
        ofstream output;

        output.open (fileInput);
        output << "Gen 0" << endl;

        for(int i = 0; i < row; i++){
          for(int j = 0; j < column; j++){
              output << grid[i][j] << "\t";
          }
          output << "\n";
        }
        output << endl;
        output.close();
        count++;

        while(count < 100){

          MirrorMode* m = new MirrorMode(row, column, grid);

          m->simulation();

          grid = m->fileOut(fileInput, count);
          count++;

          if(m->isEqual()){
            check++;

            if(check == 5){
              cout << "Grid stablizes or is empty, program will end" << endl;
              cout << "The output in " << fileInput << endl;
              break;
            }
          }
            else{
            continue;
          }
        }

      }else if (filePick == "n"){
        if(pause == "y"){
          while(count < 1000){

            MirrorMode* m = new MirrorMode(row, column, grid);

            count++;

            m->simulation();

            cout << endl;
            cout << "Generation number: " << count << endl;
            cout << endl;

            grid = m->printGrid();

            for(int i = 0; i < 1000; i++){
              for(int i = 0; i < 70000; i++){
                slow+=i;
              }
              slow += i;
            }

            if(m->isEqual()){
              check++;

              if(check == 5){
                cout << "Grid stablizes or is empty, program will end" << endl;
                break;
              }
            }
              else{
              continue;
            }
          }
        }else if(pause == "n"){

          //Ensures enough loops
          while(count < 100){

            MirrorMode* m = new MirrorMode(row, column, grid);

            count++;

            m->simulation();


            cout << endl;
            cout << "Generation number: " << count << endl;
            cout << endl;

            grid = m->printGrid();

            cout << "Press 'y' to continue: ";
            cin >> answer;

            if(m->isEqual()){
              check++;

              if(check == 5){
                cout << "Grid stablizes or is empty, program will end" << endl;
                cout << "Press 'y' to quit: ";
                cin >> answer;
                if(answer == 'y'){
                  break;
                }
              }
            }
              else{
              continue;
            }
          }
        }
      }
      mainLoop = false;

      }
      else{
        cout << "Did not enter the right mode, please try again" << endl;
        mainLoop = true;
      }
    }
  }

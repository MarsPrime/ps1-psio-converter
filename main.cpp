#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

void parseArguments(int argc, char* argv[]);

void scanDirectory(char* path);

int main(int argc, char* argv[])
{

     parseArguments(argc, argv);

     return 0;
}

// Function that scrape arguments that was enetred on program execution
void parseArguments(int argc, char* argv[])
{

     cout << "argument numbers: " << argc << endl;
     
     for (int i = 0; i < argc; i ++ )
     {
          cout << i << endl;
          cout << "Argument " << i << " - " << argv[i] << endl;
          if (i == 1)
          {
               scanDirectory(argv[i]);
          }
     }
}


// function that scans folder where image exist
void scanDirectory(char* path)
{
     for (const auto& file : directory_iterator(path)) 
     {
          string FileName = file.path().string();
          const char* cString = FileName.c_str();
          cout << cString << endl;
     }
}


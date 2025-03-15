#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void parseArguments(int argc, char* argv[]);


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
          cout << "Argument " << i << " - " << argv[i] << endl;
     }
}

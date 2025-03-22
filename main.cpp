#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <filesystem>
#include <cstring>

using namespace std;
using namespace filesystem;

void parseArguments(int argc, char* argv[]);

void scanDirectory(char* path);

const char* splitString(const char* string, const char* delimiter);

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


// Function that scans folder where image exist
void scanDirectory(char* path)
{
     for (const auto& file : directory_iterator(path)) 
     {
          string FileName = file.path().string();
          const char* cString = FileName.c_str();
          //cout << cString << endl;
          splitString(cString, ".");
     }
}

const char* splitString(const char* string, const char* delimiter)
{
     int dot_index = 0;
     int string_size = strlen(string);

     for (int i = 0; i < string_size; i ++)
     {
          if (string[i] == delimiter[0])
          {
               dot_index = i;
          }
     }

     

     int extension_size = string_size - dot_index;
     char* file_name = new char[dot_index];
     char* file_extension = new char[extension_size];
     int extension_index_count = 0;

     for (int i = 0; i < string_size; i++)
     {

          if (i < dot_index)
          {
               file_name[i] = string[i];
          }

          else if (i > dot_index)
          {
               cout << extension_index_count << endl;
               file_extension[extension_index_count] = string[i];
               extension_index_count ++ ;
          }

     }


     cout << file_name << "\t" << file_extension << endl;

     return string;
     
}

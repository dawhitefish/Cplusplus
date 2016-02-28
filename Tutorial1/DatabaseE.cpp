#include "database.h"
#include <cstring>
#include <iostream>      // for console I/O
#include <fstream>          // for file io
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;



void add_student(std::string name, std::string surname, std::string stdnum, std::string record){
WHTALE008::StudentRecord temp;
temp.name = name;
temp.surname = surname;
temp.stdnum = stdnum;
temp.classRecord = record;


WHTALE008::records.push_back(temp);
}

void get_student(std::string stdnum)
{
    for(int i=0; (unsigned)i <WHTALE008::records.size(); i++){
   if(WHTALE008::records[i].stdnum == stdnum)
   {
       std::cout <<WHTALE008::records[i].name +" " << WHTALE008::records[i].surname +" " << WHTALE008::records[i].classRecord +" " <<std::endl;

   }
}
}

void save_data(std::string filename)
{
   ofstream outfile;
   outfile.open(filename.c_str());
     if (!outfile)
    {
      cout << "Unable to open file " << filename << ";exiting\n";

    }
    for(int i=0; (unsigned)i <WHTALE008::records.size(); i++)
    {
        outfile <<WHTALE008::records[i].stdnum + " " << WHTALE008::records[i].name +" " << WHTALE008::records[i].surname +" " << WHTALE008::records[i].classRecord +" " <<std::endl;
    }
    outfile.close();

}

void read_data(std::string filename)
{
    ifstream ifs(filename.c_str());

    if (!ifs)
    {
      cout << "Unable to open file " << filename << ";exiting\n";

    }
    char array[100];
    while(ifs.getline(array,100))
    {
        std::string input;
         WHTALE008::StudentRecord temp;
         input = array;

        cout << input << endl;
      WHTALE008::make_student(input,temp);
        WHTALE008::records.push_back(temp);


    }
    ifs.close();



}

void WHTALE008::make_student(std::string line, WHTALE008::StudentRecord temp)
{
    istringstream iss(line);
    std::vector<string> parts;




    temp.name = parts[0];
    temp.surname = parts[1];
    temp.stdnum = parts[2];
    for(int i = 3 ; (unsigned)i< parts.size(); i++)
    {
        temp.classRecord = temp.classRecord +" " +parts[i];
    }

}


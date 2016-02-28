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
WHTALE008::StudentRecord temp = WHTALE008::get_student(stdnum);
if(temp.stdnum == "fail")
{

temp.name = name;
temp.surname = surname;
temp.stdnum = stdnum;
temp.classRecord = record;

WHTALE008::records.push_back(temp);
}
else
{
    temp.name = name;
temp.surname = surname;

temp.classRecord = record;
WHTALE008::records.push_back(temp);
}





}

WHTALE008::StudentRecord get_student(std::string stdnum)
{
    for(int i=0; (unsigned)i <WHTALE008::records.size(); i++){
   if(WHTALE008::records[i].stdnum == stdnum)
   {
       std::cout <<WHTALE008::records[i].name +" " << WHTALE008::records[i].surname +" " << WHTALE008::records[i].classRecord +" " <<std::endl;
        return WHTALE008::records[i];
   }


}
cout << "Student not found" << endl;
WHTALE008::StudentRecord fail;
fail.stdnum = "fail";
return fail;
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

void grade_student(std::string stdnum)
{
    WHTALE008::StudentRecord temp = WHTALE008::get_student(stdnum);
    string grades = temp.classRecord;
    int sum = 0;
    int num = 0;
    int value;
    istringstream stream(grades);
    while(!stream.eof())
    {
        num = num+1;
        stream >> value;
        sum = sum + value;

    }
    cout << "The Grade Average : " << sum << endl;
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

void make_student(std::string line, WHTALE008::StudentRecord temp)
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



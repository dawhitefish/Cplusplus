#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    string option;
    for(;;)
    {

        cout<< "0. Add student \n1. Read database \n2. Save database \n3. Display given student data\n4. Grade Student \nq. Quit" << endl;
        cin >> option;
        int numoption = atoi(option.c_str());
        switch(numoption){
        case 0:
            // add student
            cout << "function addStudent() called" << endl;
            break;
        case 1:
            //read database
            cout << "function readDatabase() called" << endl;
            break;
        case 2:
            //save database
            cout << "function saveDatabase() called" << endl;
            break;
        case 3:
            //display given student data
            cout << "function getStudent() called" << endl;
            break;
        case 4:
            //grade student
            cout << "function gradeStudent() called" << endl;
            break;

        }
        if(option == "q") break;
        //WHTALE008::clear();

    }
    return 0;

}
namespace WHTALE008 {
    void clear(void)
    {system("clear");
    }
}

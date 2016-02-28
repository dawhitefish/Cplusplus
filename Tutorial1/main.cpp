#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{

    string option;
    string stdnum;
    string name;
    string surname;
    string grades;
    for(;;)
    {

        cout<< "0. Add student \n1. Read database \n2. Save database \n3. Display given student data\n4. Grade Student \nq. Quit" << endl;
        cin >> option;
        int numoption = atoi(option.c_str());
        switch(numoption){
        case 0:
            // add student
            cout << "function addStudent() called" << endl;
            cout << "Enter your Student Number(In Capitals): ";
            cin >> stdnum;
            cout<<endl;
             cout << "Enter your Name: ";
            cin >> name;
            cout<<endl;
             cout << "Enter your Surname: ";
            cin >> surname;
            cout<<endl;
             cout << "Enter your Grades(separated by spaces) : ";
            cin >> grades;
            cout<<endl;
            add_student(name,surname,stdnum,grades);
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
       system("clear");

    }
    return 0;

}




/**
*.h file
*/

#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>
namespace WHTALE008 {

void add_student(std::string name, std::string surname, std::string stdnum, std::string record);

void read_data(std::string filename);

void save_data(std::string filename);

void get_student(std::string stdnum);

void grade_student(std::string stdnum);


typedef struct {
 std::string name;
 std::string surname;
 std::string stdnum;
 std::string classRecord;
}StudentRecord;
std::vector<StudentRecord> records;


void make_student(std::string line, WHTALE008::StudentRecord temp);
}
#endif // DATABASE_H

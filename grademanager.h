#ifndef SYSTEMHANDLER_H
#define SYSTEMHANDLER_H
#include <map>
#include <vector>
#include <string>
#include <list>
#include "student.h"

using namespace std;
class GradeManager {
private:
    map<string, Student> mainStorage;
    list<string> systemLog;  // LINKED LIST: Global system history
public:
    bool studentExist(string id);
    void addStudent(string name, string id);
    void deleteStudent(string id);
    void updateGrade(string id,string sub, string comp, double val, string admin);

    vector<Student> getTop3Students();
    Student& getStudent(string id);
    string getSubjectAverage(string subject) ;
    string avgGradeletter(double grade) const;

    void showAllGrades();
};

#endif

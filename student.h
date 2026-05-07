#ifndef STUDENT_H
#define STUDENT_H
#include <map>
#include <string>
#include<list>

using namespace std;

struct courseDetails{
    double quiz=0, midterm=0,finalExam=0,bonus=0, activities=0;
    double totalGrade() const{
        double total=quiz+midterm+finalExam+bonus+ activities;
        return (total>100)? 100: total;
    }
};

class Student {
private:
    string name;
    string id;
    double gpa = 0.0;
    map <string, courseDetails> mainRecords;
    list<string> history;

public:
    // Static ensures this map is shared by ALL students (saves memory)
    static inline map<string, int> credithrs = {
        {"circuits", 3},
        {"control", 3},
        {"electronics", 4}
    };
    static map<string, Student> mainStorage;
    //  Constructor
    Student(string name, string id);
    // Default constructor
    Student() : name(""), id(""), gpa(0.0) {}

    double calculateGPA() const;
    void updateGradeAux(string sub, string comp, double val, string admin);// i add admin and make the course updated according to its component (quiz , mid,..)
    void display() const;
    double getGradeFor(string subject)const;
    string gradeletter(double grade) const;
    double letterToPoints(string letter)const;

    string getName() const { return name; }
    string getID() const { return id; }
    double getInternalGPA() const { return gpa; }
    string showAllCoursesDetails()const;
};
#endif

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <map>
#include <string>
#include<list>
#include<vector>
using namespace std;
struct CourseInfo {
    string name;
    int credits;
};
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
    int currentLevel = 1;

public:
    // Static ensures this map is shared by ALL students (saves memory)
    static inline map<int, vector<CourseInfo>> levels = {
        {1, { {"math1", 3}, {"statics", 3}, {"dynamics", 3},{"drawing", 3}}},
        {2, {{"electronics", 3}, {"circuits", 3}, {"electromagnetic", 3},{"system_dynamics", 3}}},
        {3,{{"programming", 3},{"probability", 3}, {"vibration", 3} , {"control", 3}}},
        {4,{{"measurements", 3},{"logic_design", 3},{"semiconductors",3},{"computer_Architecture",3}}}
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
    void setLevel(int l) { currentLevel = l; }
    int getLevel() const { return currentLevel; }
    int calculateLevel()const;
    int getCompletedHoursForLevel(int level) const ;
    bool canPromote() const { return getCompletedHoursForLevel(currentLevel) >= 12; // according to courses we put at each level
    }
    void displayGradesByLevel(int level) const;
};
#endif

#include "student.h"
#include<cmath>
#include <iostream>
using namespace std;

Student::Student(string name, string id) : name(name), id(id), gpa(0.0) {}

double Student:: calculateGPA() const {
    double totalPoints = 0;
    int totalChrs = 0;
    for (const auto& [subName, record] : mainRecords) {
        // Check if the subject exists in our credit hour registry
        if (credithrs.count(subName)) {
            string letter=gradeletter(record.totalGrade());
            double points=letterToPoints(letter);
            int ch = credithrs[subName];
            totalPoints += points * ch;
            totalChrs += ch;
        }
    }
    double GPA;

    if (totalChrs == 0) return 0.0;
    GPA=  totalPoints / totalChrs;
    //3.786 -> 378.6 -> 379.0 -> 3.79
    //why this? one of the test cases was 3.8756 which is not preferred and the actual GPA not like that
    return round(GPA * 100.0) / 100.0;
}

/*
void Student::updateGradeAux(string subname, double grade) {
        grades[subname] = grade;
        gpa = calculateGPA(); // Update internal GPA immediately
    }
*/
// double quiz=0, midterm=0,finalExam=0,bonus=0, activities=0;
void Student::updateGradeAux(string sub, string comp, double val, string admin){
    if(comp=="quiz")  mainRecords[sub].quiz=val;
    if(comp=="midterm")  mainRecords[sub].midterm=val;
    if(comp=="finalExam")  mainRecords[sub].finalExam=val;
    if(comp=="bonus")  mainRecords[sub].bonus=val;
    if(comp=="activities")  mainRecords[sub].activities=val;
    history.push_back(sub+ " graded by "+ admin );
    gpa = calculateGPA();
}

void Student::display() const {
    cout << "ID: " << id << " | Name: " << name << " | GPA: " << gpa << endl;
}

double Student::getGradeFor(string subject) const {
    if (mainRecords.count(subject)) {
        return (mainRecords.at(subject)).totalGrade();
    }
    return -1.0;
}

string Student::gradeletter(double grade) const {

    if(grade>100 || grade<0) {
        return " Error in grading ,try again";
    }
    if (grade >= 97) return "A+";
    if (grade >= 93) return "A";
    if (grade >= 89) return "A-";
    if (grade >= 84) return "B+";
    if (grade >= 80) return "B";
    if (grade >= 76) return "B-";
    if (grade >= 73) return "C+";
    if (grade >= 70) return "C";
    if (grade >= 67) return "C-";
    if (grade >= 64) return "D+";
    if (grade >= 60) return "D";
    return "F";
}

double Student::letterToPoints(string letter) const {
    if (letter == "A+") return 4.0;
    if (letter == "A")  return 4.0;
    if (letter == "A-") return 3.7;
    if (letter == "B+") return 3.3;
    if (letter == "B")  return 3.0;
    if (letter == "B-") return 2.7;
    if (letter == "C+") return 2.3;
    if (letter == "C")  return 2.0;
    if (letter == "C-") return 1.7;
    if (letter == "D+") return 1.3;
    if (letter == "D")  return 1.0;
    if (letter == "F")  return 0.0;

    return 0.0;
}
string Student::showAllCoursesDetails()const{
    string text;
    for (const auto& [subName, record] : mainRecords) {
    text+="<li>" + subName + " : " +
                gradeletter(record.totalGrade()) + "%</li>";
    }

    return text;
}

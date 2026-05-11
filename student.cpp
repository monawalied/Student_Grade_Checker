#include "student.h"
#include<cmath>
Student::Student(string name, string id) : name(name), id(id), gpa(0.0) {}

double Student::calculateGPA() const {
    double totalPoints = 0;
    int totalChrs = 0;
    //We look through all levels (1, 2, 3, 4)
    for (const auto& [levelNum, coursesInLevel] : levels) {
        for (const auto& course : coursesInLevel) {
            if (mainRecords.count(course.name)) {
                double score = mainRecords.at(course.name).totalGrade();
                double points = letterToPoints(gradeletter(score));
                totalPoints += (points * course.credits);
                totalChrs += course.credits;
            }
        }
    }
    if (totalChrs == 0) return 0.0;
    double GPA = totalPoints / totalChrs;
    return round(GPA * 100.0) / 100.0;
}

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
    cout << "ID: " << id << " | Name: " << name <<" | Level " << getLevel()<<  " | GPA: " << gpa << endl;
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
int Student::getCompletedHoursForLevel(int level) const {
    int total = 0;
    if (levels.count(level)) {
        for (const auto& course : levels.at(level)) {
            if (mainRecords.count(course.name)) {
                if (mainRecords.at(course.name).totalGrade() >= 60) {
                    total += course.credits;
                }
            }
        }
    }
    return total;
}
void Student::displayGradesByLevel(int level) const {
    cout << "Level " << level << " Grades for " << name << " ---" << endl;
    bool found = false;

    if (levels.count(level)) {
        for (const auto& course :levels.at(level)) {
            if (mainRecords.count(course.name)) {
                double score = mainRecords.at(course.name).totalGrade();
                cout << course.name << ": " << score << " (" << gradeletter(score) << ")" << endl;
                found = true;
            }
        }
    }

    if (!found) cout << "No records found for this level." << endl;
    cout << "Total Hours Completed in Level " << level << ": "
         << getCompletedHoursForLevel(level) << "/12" << endl;
}
int Student::calculateLevel()const{
    int totalHours = 0;
    for (const auto& [lvl, courses] : levels) {
        totalHours += getCompletedHoursForLevel(lvl);
    }
    if (totalHours >= 36) return 4;
    if (totalHours >= 24) return 3;
    if (totalHours >= 12) return 2;
    return 1;
}

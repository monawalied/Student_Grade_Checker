#include "grademanager.h"
#include <iostream>
#include <algorithm>


using namespace std;
bool GradeManager::studentExist(string id){
    return mainStorage.find(id)!=mainStorage.end();
}

void GradeManager::addStudent(string name, string id) {
    if (!studentExist(id)) {
        mainStorage[id] = Student(name, id);
        cout << "Student added successfully.\n";
        systemLog.push_back("System: Registered " + name + id);
    }
    else {
        cout << "Error: Student with ID " << id << " already exists.\n";
    }
}
void GradeManager::deleteStudent(string id) {
    if (studentExist(id)) {
        string studentName = mainStorage[id].getName();
        mainStorage.erase(id);

        cout << "Student " << studentName << " (ID: " << id << ") has been deleted." << endl;
        systemLog.push_back("Admin deleted student: " + studentName + " [" + id + "]");
    } else {
        cout << "Error: Cannot delete. Student ID " << id << " not found." << endl;
    }
}

void GradeManager::updateGrade(string id,string course, string comp, double val, string admin) {
    auto it = mainStorage.find(id);
    if (it != mainStorage.end()) {
        Student& currentStudent = it->second; // it->first points to the id , ->next points to the student itself
        currentStudent.updateGradeAux(course, comp,val,admin);
        cout << "Grade updated for " << id << endl;
        systemLog.push_back( admin+" updated the grade of "+ course+" " + comp +"for "+ id);
    } else {
        cout << "Error: Student doesn't exist.\n";
    }
}
vector<Student> GradeManager::getTop3Students(){
    vector<Student> allStudents;
    for (const auto& [id ,student]: mainStorage){
        allStudents.push_back(student);
    }

    // more examples about this exist in templates lab
    sort(allStudents.begin(), allStudents.end(), [](const Student &a, const Student &b) {
        return a.calculateGPA() > b.calculateGPA();
    });
    vector<Student> top_3;
    for (size_t i = 0; i < 3 && i < allStudents.size(); i++)
        top_3.push_back(allStudents[i]);

    return top_3;
}
Student& GradeManager::getStudent(string id) {
    return mainStorage.at(id);
}

string GradeManager::getSubjectAverage(string subject) {
    int totalStudents=0;
    double totalGrades=0.0;
    double average;
    for (const auto& [id ,student]: mainStorage){
        double grade = student.getGradeFor(subject);
        if (grade != -1.0) {
            totalGrades += grade;
            totalStudents++; // Simple increment is safer than ternary logic
        }
    }

    if (totalStudents) average= totalGrades/totalStudents;
    else  return "None of the students registered for " + subject + " yet";
    cout<< "Average of "<< subject<<" is ";
    return (avgGradeletter(average));

}


string GradeManager::avgGradeletter(double grade) const {

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

void GradeManager::showAllGrades(){
    for (const auto& [id ,student]: mainStorage)
        student.display();
}

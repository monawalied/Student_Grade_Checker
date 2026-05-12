#include "mainwindow.h"
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->subjCombo->clear();

    for (auto const& [levelNum, coursesVector] : Student::levels) {
        for (const auto& course : coursesVector) {
            ui->subjCombo->addItem(QString::fromStdString(course.name));
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addBtn_clicked()
{
    QString name = ui->nameInput->text();
    QString id = ui->idInput_page1->text();
    int selectedLevel = ui->levelCombo->currentText().toInt(); // From your new ComboBox

    if (!name.isEmpty() && !id.isEmpty()) {
        manager.addStudent(name.toStdString(), id.toStdString(), selectedLevel);

        int row = ui->studentTable->rowCount();
        ui->studentTable->insertRow(row);
        ui->studentTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->studentTable->setItem(row, 1, new QTableWidgetItem(id));
        ui->studentTable->setItem(row, 2, new QTableWidgetItem(QString::number(selectedLevel)));

        // Clear only the registration inputs
        ui->nameInput->clear();
        ui->idInput_page1->clear();

    }
}

void MainWindow::on_loadCoursesBtn_clicked() {
    string id = ui->idInput_page2->text().toStdString();
    if (manager.studentExist(id)){

        Student& s = manager.getStudent(id);
        auto courses = Student::levels[s.getLevel()];

        ui->updateTable->setRowCount(0);
        for (const auto& course : courses) {
            int row = ui->updateTable->rowCount();
            ui->updateTable->insertRow(row);
            ui->updateTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(course.name)));


            courseDetails details = s.getRecord(course.name);
            ui->updateTable->setItem(row, 1, new QTableWidgetItem(QString::number(details.midterm)));
            ui->updateTable->setItem(row, 2, new QTableWidgetItem(QString::number(details.finalExam)));
            ui->updateTable->setItem(row, 3, new QTableWidgetItem(QString::number(details.activities)));
        }
    }
    else{
        QMessageBox::warning(this, "Error", "Student ID not found!");
    }
}


void MainWindow::on_updateGradeBtn_clicked() {
    string id = ui->idInput_page2->text().toStdString();
    if(manager.studentExist(id)){

        for (int i = 0; i < ui->updateTable->rowCount(); ++i) {
            string course = ui->updateTable->item(i, 0)->text().toStdString();

            double mid = ui->updateTable->item(i, 1) ? ui->updateTable->item(i, 1)->text().toDouble() : 0;
            double fin = ui->updateTable->item(i, 2) ? ui->updateTable->item(i, 2)->text().toDouble() : 0;
            double act = ui->updateTable->item(i, 3) ? ui->updateTable->item(i, 3)->text().toDouble() : 0;

            manager.updateGrade(id, course, "midterm", mid);
            manager.updateGrade(id, course, "finalExam", fin);
            manager.updateGrade(id, course, "activities", act);
        }

        QMessageBox::information(this, "Success", "Grades are updated successfully! ");
    }
    else{
        QMessageBox::warning(this, "Error", "Student ID not found!");
    }
}

void MainWindow::on_chkBtn_clicked()
{
    QString id = ui->idInput_page3->text();

    if (!id.isEmpty()) {
        string stdID = id.toStdString();

        if (manager.studentExist(stdID)) {
            Student& s = manager.getStudent(stdID);
            displayStudentReport(s);
        } else {
            QMessageBox::warning(this, "Error", "Student ID not found!");
        }
    } else {
        QMessageBox::warning(this, "Error", "Please enter a valid ID!");
    }
}

void MainWindow::on_deleteBtn_clicked()
{
    QString id = ui->idInput_page3->text();
    if (!id.isEmpty()) {
        if (manager.studentExist(id.toStdString())) {
            manager.deleteStudent(id.toStdString());
            QString html = "<br>*3";
            html += "<h2> Student with ID : " + id.toStdString() + " is deleted successfully";
            html += "</h2>";
        } else {
            QMessageBox::warning(this, "Error", "Student ID not found!");
        }
    } else {
        QMessageBox::warning(this, "Error", "ENTER A VALID ID!");
    }
}


void MainWindow::displayStudentReport(const Student &s)
{
    // Start the HTML with some styling for the white background
    QString html = "<div style='font-family: Arial; color: #000000; padding: 10px;'>";

    // 1. Header Information
    html += "<h2 style='color: #2980b9;'>Full Academic Transcript</h2>";
    html += "<p><b>Name:</b> " + QString::fromStdString(s.getName()) + "<br>";
    html += "<b>ID:</b> " + QString::fromStdString(s.getID()) + "<br>";
    html += "<b>Current Academic Level:</b> " + QString::number(s.getLevel()) + "</p>";

    // 2. GPA Display
    html += "<h3 style='color: #27ae60;'>Cumulative GPA: " + QString::number(s.getInternalGPA()) + "</h3>";
    html += "<hr>";

    // 3. The Core History: Loop through EVERY course ever taken
    html += "<h4>Course History:</h4><ul>";

    // This is the key: s.showAllCoursesDetails() pulls everything from the map
    html += s.showAllCoursesDetails();

    html += "</ul></div>";

    // 4. Update the actual UI element (make sure the object name is correct)
    ui->studDisplayReport->setHtml(html);
}
void MainWindow::on_subAvgBtn_clicked()
{
    QString subject = ui->subjCombo->currentText();

    if (ui->subjCombo->currentIndex() == -1) {
        QMessageBox::warning(this, "Input Error", "Please select a subject first!");
        return;
    }

    QString result = QString::fromStdString(manager.getSubjectAverage(subject.toStdString()));

    // START WITH A WRAPPER - This ensures visibility
    QString html = "<div style='color: #FFFFFF; font-family: Arial; padding: 10px;'>";

    if (result != "EMPTY") {
        html += "<h2 style='color: #2980b9; margin-bottom: 5px;'>Subject Analysis</h2>";
        html += "<p style='font-size: 16px;'>Average of <b>" + subject + "</b> is: ";
        html += "<span style='color: #27ae60; font-weight: bold;'>" + result + "</span></p>";
    } else {
        // Even the "None" message is now inside the white-text div
        html += "<h2 style='color: #e67e22;'>Notice</h2>";
        html += "<p style='font-size: 16px;'>None of the students registered for <b>" + subject
                + "</b> yet.</p>";
    }

    html += "</div>"; // Close the wrapper
    ui->subjectAvgReport->setHtml(html);
}



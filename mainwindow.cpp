#include "mainwindow.h"
#include <QMessageBox>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->subjCombo->addItem("electronics");
    ui->subjCombo->addItem("control");
    ui->subjCombo->addItem("circuits");

    ui->courseCombo->addItem("circuits");
    ui->courseCombo->addItem("control");
    ui->courseCombo->addItem("electronics");

    ui->componentCombo->addItem("quiz");
    ui->componentCombo->addItem("midterm");
    ui->componentCombo->addItem("finalExam");
    ui->componentCombo->addItem("bonus");
    ui->componentCombo->addItem("activities");

    // 2. Set the "Hints"
    ui->courseCombo->setPlaceholderText("Select a course...");
    ui->componentCombo->setPlaceholderText("Select a category...");
    ui->subjCombo->setPlaceholderText("Select a course...");

    // 3. Start empty
    ui->courseCombo->setCurrentIndex(-1);
    ui->componentCombo->setCurrentIndex(-1);
    ui->subjCombo->setCurrentIndex(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addBtn_clicked()
{
    QString name = ui->nameInput->text();
    QString id = ui->idInput_page1->text();

    if (!name.isEmpty() && !id.isEmpty()) {
        manager.addStudent(
            name.toStdString(),
            id.toStdString()); //tostdstring converts the Qt-specific string into a format your Student constructor understands
        int row = ui->studentTable->rowCount();
        ui->studentTable->insertRow(row);
        ui->studentTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->studentTable->setItem(row, 1, new QTableWidgetItem(id));
        ui->nameInput->clear();
        ui->idInput_page1->clear();
    }
}

void MainWindow::on_updateGradeBtn_clicked()
{
    QString id = ui->idInput_page2->text();
    QString course = ui->courseCombo->currentText();
    QString component = ui->componentCombo->currentText();
    double value = ui->gradeValue->value();
    if (!id.isEmpty() && course != "Select a course..." && component != "Select a category...") {
        if (manager.studentExist(id.toStdString())) {
            manager.updateGrade(id.toStdString(),
                                course.toStdString(),
                                component.toStdString(),
                                value,
                                "Admin");

            Student &s = manager.getStudent(id.toStdString());
            double newGPA
                = s.getInternalGPA(); // instead of calling calculate gpa i just fetched it since it's calculated in update grade auto

            QMessageBox::information(this,
                                     "Success",
                                     "Grade Updated! New GPA for "
                                         + QString::fromStdString(s.getName())
                                         + " is: " + QString::number(newGPA));

        } else {
            QMessageBox::warning(this, "Error", "Student ID not found!");
        }
    } else {
        QMessageBox::warning(this, "Error", "FILL OUT ALL REQUIRED FEILDS!");
    }
    ui->idInput_page2->clear();
    ui->courseCombo->setCurrentIndex(-1);    // Resets to placeholder
    ui->componentCombo->setCurrentIndex(-1); // Resets to placeholder
    ui->gradeValue->setValue(ui->gradeValue->minimum());
}
void MainWindow::on_chkBtn_clicked()
{
    QString id = ui->idInput_page3->text();
    if (!id.isEmpty()) {
        bool found = manager.studentExist(id.toStdString());
        if (found) {
            displayStudentReport(manager.getStudent(id.toStdString()));
        } else {
            QMessageBox::warning(this, "Error", "Student ID not found!");
        }
    } else {
        QMessageBox::warning(this, "Error", "ENTER A VALID ID!");
    }
    ui->idInput_page3->clear();
}
void MainWindow::displayStudentReport(const Student &s)
{
    // 1. Start the HTML string with some basic CSS styling
    QString html = "<div style='font-family: Arial; color:  #FFFFFF;'>";

    // 2. Add a Header
    html += "<h2 style='color: #2980b9;'>Student Academic Record</h2>";
    html += "<p><b>Name:</b> " + QString::fromStdString(s.getName()) + "<br>";
    html += "<b>ID:</b> " + QString::fromStdString(s.getID()) + "</p>";

    // 3. Highlight the GPA with a color
    QString gpaColor = (s.getInternalGPA() >= 3.0) ? "#27ae60" : "#e67e22";
    html += "<h3 style='color: " + gpaColor
            + ";'>Current GPA: " + QString::number(s.getInternalGPA()) + "</h3>";

    html += "<hr><p><b>Course Breakdown:</b></p><ul>";

    // 4. (Logic needed) Loop through your courses here to add list items
    html += s.showAllCoursesDetails();

    html += "</ul></div>";

    // 5. Send the HTML to the Text Edit
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
    ui->idInput_page3->clear();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->courseCombo->addItem("circuits");
    ui->courseCombo->addItem("control");
    ui->courseCombo->addItem("electronics");


    ui->componentCombo->addItem("quiz");
    ui->componentCombo->addItem("midterm");
    ui->componentCombo->addItem("finalExam");
    ui->componentCombo->addItem("bonus");
    ui->componentCombo->addItem("activities");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addBtn_clicked()
{
    QString name = ui->nameInput->text();
    QString id = ui->idInput->text();

    if(!name.isEmpty() && !id.isEmpty()) {
        manager.addStudent(name.toStdString(), id.toStdString());
        int row = ui->studentTable->rowCount();
        ui->studentTable->insertRow(row);
        ui->studentTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->studentTable->setItem(row, 1, new QTableWidgetItem(id));
        ui->nameInput->clear();
        ui->idInput->clear();
    }
}

void MainWindow::on_updateGradeBtn_clicked()
{
    QString id = ui->idInput->text();
    QString course = ui->courseCombo->currentText();
    QString component = ui->componentCombo->currentText();
    double value = ui->gradeValue->value();

    if (manager.studentExist(id.toStdString())) {
        manager.updateGrade(id.toStdString(), course.toStdString(),
                            component.toStdString(), value, "Admin");

        Student& s = manager.getStudent(id.toStdString());
        double newGPA = s.calculateGPA();

        QMessageBox::information(this, "Success",
                                 "Grade Updated! New GPA for " + QString::fromStdString(s.getName()) +
                                     " is: " + QString::number(newGPA));

    } else {
        QMessageBox::warning(this, "Error", "Student ID not found!");
    }

}
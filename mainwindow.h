#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "grademanager.h"
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addBtn_clicked();
    void on_updateGradeBtn_clicked();

    void on_chkBtn_clicked();

    void on_subAvgBtn_clicked();

    void on_deleteBtn_clicked();

    void on_loadCoursesBtn_clicked();

private:
    Ui::MainWindow *ui;
    GradeManager manager;
    void displayStudentReport(const Student &s);

};
#endif // MAINWINDOW_H

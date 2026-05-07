/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *studentRecordPage;
    QWidget *tab;
    QLabel *label;
    QLabel *label_7;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *nameInput;
    QLabel *label_3;
    QLineEdit *idInput_page1;
    QHBoxLayout *horizontalLayout;
    QPushButton *addBtn;
    QTableWidget *studentTable;
    QWidget *tab_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_3;
    QLabel *label_15;
    QComboBox *courseCombo;
    QLabel *label_16;
    QDoubleSpinBox *gradeValue;
    QLabel *label_17;
    QComboBox *componentCombo;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *updateGradeBtn;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_14;
    QLineEdit *idInput_page2;
    QWidget *tab_3;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_18;
    QLineEdit *idInput_page3;
    QPushButton *chkBtn;
    QTextEdit *studDisplayReport;
    QPushButton *deleteBtn;
    QWidget *tab_4;
    QPushButton *subAvgBtn;
    QTextEdit *subjectAvgReport;
    QComboBox *subjCombo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(834, 467);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        studentRecordPage = new QTabWidget(centralwidget);
        studentRecordPage->setObjectName("studentRecordPage");
        studentRecordPage->setGeometry(QRect(0, 0, 841, 461));
        tab = new QWidget();
        tab->setObjectName("tab");
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 20, 431, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Semibold")});
        font.setPointSize(18);
        font.setBold(true);
        label->setFont(font);
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(980, 230, 181, 20));
        QFont font1;
        font1.setPointSize(11);
        label_7->setFont(font1);
        formLayoutWidget = new QWidget(tab);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 70, 453, 161));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(7, 7, 7, 7);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(10);
        label_2->setFont(font2);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_2);

        nameInput = new QLineEdit(formLayoutWidget);
        nameInput->setObjectName("nameInput");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, nameInput);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_3);

        idInput_page1 = new QLineEdit(formLayoutWidget);
        idInput_page1->setObjectName("idInput_page1");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, idInput_page1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        formLayout->setLayout(4, QFormLayout::ItemRole::SpanningRole, horizontalLayout);

        addBtn = new QPushButton(formLayoutWidget);
        addBtn->setObjectName("addBtn");

        formLayout->setWidget(2, QFormLayout::ItemRole::SpanningRole, addBtn);

        studentTable = new QTableWidget(tab);
        if (studentTable->columnCount() < 2)
            studentTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        studentTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        studentTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        studentTable->setObjectName("studentTable");
        studentTable->setGeometry(QRect(490, 70, 251, 311));
        studentRecordPage->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        formLayoutWidget_2 = new QWidget(tab_2);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(190, 90, 511, 321));
        formLayout_3 = new QFormLayout(formLayoutWidget_2);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setContentsMargins(7, 7, 7, 7);
        label_15 = new QLabel(formLayoutWidget_2);
        label_15->setObjectName("label_15");
        label_15->setFont(font2);

        formLayout_3->setWidget(0, QFormLayout::ItemRole::LabelRole, label_15);

        courseCombo = new QComboBox(formLayoutWidget_2);
        courseCombo->addItem(QString());
        courseCombo->addItem(QString());
        courseCombo->addItem(QString());
        courseCombo->setObjectName("courseCombo");

        formLayout_3->setWidget(0, QFormLayout::ItemRole::FieldRole, courseCombo);

        label_16 = new QLabel(formLayoutWidget_2);
        label_16->setObjectName("label_16");
        label_16->setFont(font2);

        formLayout_3->setWidget(1, QFormLayout::ItemRole::LabelRole, label_16);

        gradeValue = new QDoubleSpinBox(formLayoutWidget_2);
        gradeValue->setObjectName("gradeValue");
        gradeValue->setEnabled(true);
        gradeValue->setMaximum(100.989999999999995);

        formLayout_3->setWidget(1, QFormLayout::ItemRole::FieldRole, gradeValue);

        label_17 = new QLabel(formLayoutWidget_2);
        label_17->setObjectName("label_17");
        label_17->setFont(font2);

        formLayout_3->setWidget(2, QFormLayout::ItemRole::LabelRole, label_17);

        componentCombo = new QComboBox(formLayoutWidget_2);
        componentCombo->addItem(QString());
        componentCombo->addItem(QString());
        componentCombo->addItem(QString());
        componentCombo->setObjectName("componentCombo");

        formLayout_3->setWidget(2, QFormLayout::ItemRole::FieldRole, componentCombo);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        updateGradeBtn = new QPushButton(formLayoutWidget_2);
        updateGradeBtn->setObjectName("updateGradeBtn");

        horizontalLayout_3->addWidget(updateGradeBtn);


        formLayout_3->setLayout(4, QFormLayout::ItemRole::SpanningRole, horizontalLayout_3);

        horizontalLayoutWidget = new QWidget(tab_2);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(190, 20, 511, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget);
        label_14->setObjectName("label_14");
        label_14->setFont(font2);
        label_14->setMargin(10);

        horizontalLayout_2->addWidget(label_14);

        idInput_page2 = new QLineEdit(horizontalLayoutWidget);
        idInput_page2->setObjectName("idInput_page2");

        horizontalLayout_2->addWidget(idInput_page2);

        studentRecordPage->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        horizontalLayoutWidget_2 = new QWidget(tab_3);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 511, 51));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(horizontalLayoutWidget_2);
        label_18->setObjectName("label_18");
        label_18->setFont(font2);
        label_18->setMargin(10);

        horizontalLayout_4->addWidget(label_18);

        idInput_page3 = new QLineEdit(horizontalLayoutWidget_2);
        idInput_page3->setObjectName("idInput_page3");

        horizontalLayout_4->addWidget(idInput_page3);

        chkBtn = new QPushButton(tab_3);
        chkBtn->setObjectName("chkBtn");
        chkBtn->setGeometry(QRect(20, 360, 191, 29));
        studDisplayReport = new QTextEdit(tab_3);
        studDisplayReport->setObjectName("studDisplayReport");
        studDisplayReport->setGeometry(QRect(450, 80, 341, 321));
        studDisplayReport->setReadOnly(true);
        deleteBtn = new QPushButton(tab_3);
        deleteBtn->setObjectName("deleteBtn");
        deleteBtn->setGeometry(QRect(20, 310, 191, 29));
        studentRecordPage->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        subAvgBtn = new QPushButton(tab_4);
        subAvgBtn->setObjectName("subAvgBtn");
        subAvgBtn->setGeometry(QRect(450, 310, 231, 29));
        subjectAvgReport = new QTextEdit(tab_4);
        subjectAvgReport->setObjectName("subjectAvgReport");
        subjectAvgReport->setGeometry(QRect(120, 60, 561, 241));
        subjCombo = new QComboBox(tab_4);
        subjCombo->setObjectName("subjCombo");
        subjCombo->setGeometry(QRect(141, 310, 281, 28));
        studentRecordPage->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        studentRecordPage->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Student Management System", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Students Registered", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter the name", nullptr));
        nameInput->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Enter the ID", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "Add Student", nullptr));
        QTableWidgetItem *___qtablewidgetitem = studentTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = studentTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        studentRecordPage->setTabText(studentRecordPage->indexOf(tab), QCoreApplication::translate("MainWindow", "REGISTRATION", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Select the course", nullptr));
        courseCombo->setItemText(0, QCoreApplication::translate("MainWindow", "circuits", nullptr));
        courseCombo->setItemText(1, QCoreApplication::translate("MainWindow", "electronics", nullptr));
        courseCombo->setItemText(2, QCoreApplication::translate("MainWindow", "control", nullptr));

        label_16->setText(QCoreApplication::translate("MainWindow", " Set score", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Select category", nullptr));
        componentCombo->setItemText(0, QCoreApplication::translate("MainWindow", "quiz", nullptr));
        componentCombo->setItemText(1, QCoreApplication::translate("MainWindow", "midterm", nullptr));
        componentCombo->setItemText(2, QCoreApplication::translate("MainWindow", "finalExam", nullptr));

        updateGradeBtn->setText(QCoreApplication::translate("MainWindow", "Update Grade", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Enter the ID", nullptr));
        studentRecordPage->setTabText(studentRecordPage->indexOf(tab_2), QCoreApplication::translate("MainWindow", "UPDATE COURSE GRADE", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Enter the ID", nullptr));
        chkBtn->setText(QCoreApplication::translate("MainWindow", "CHECK STUDENT", nullptr));
        deleteBtn->setText(QCoreApplication::translate("MainWindow", "DELETE STUDENT", nullptr));
        studentRecordPage->setTabText(studentRecordPage->indexOf(tab_3), QCoreApplication::translate("MainWindow", "STUDENT RECORDS MANAGMENT", nullptr));
        subAvgBtn->setText(QCoreApplication::translate("MainWindow", "GET SUBJECT AVERAGE", nullptr));
        studentRecordPage->setTabText(studentRecordPage->indexOf(tab_4), QCoreApplication::translate("MainWindow", "SYSTEM STATISTICS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

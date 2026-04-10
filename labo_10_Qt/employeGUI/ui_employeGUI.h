/********************************************************************************
** Form generated from reading UI file 'employeGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEGUI_H
#define UI_EMPLOYEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeGUIClass
{
public:
    QAction *actionQuitter;
    QAction *actionCommission;
    QAction *actionHoraire;
    QAction *actionPatron;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_employe;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EmployeGUIClass)
    {
        if (EmployeGUIClass->objectName().isEmpty())
            EmployeGUIClass->setObjectName(QString::fromUtf8("EmployeGUIClass"));
        EmployeGUIClass->resize(944, 643);
        actionQuitter = new QAction(EmployeGUIClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionCommission = new QAction(EmployeGUIClass);
        actionCommission->setObjectName(QString::fromUtf8("actionCommission"));
        actionHoraire = new QAction(EmployeGUIClass);
        actionHoraire->setObjectName(QString::fromUtf8("actionHoraire"));
        actionPatron = new QAction(EmployeGUIClass);
        actionPatron->setObjectName(QString::fromUtf8("actionPatron"));
        centralwidget = new QWidget(EmployeGUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 651, 521));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        EmployeGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EmployeGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 944, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_employe = new QMenu(menuMenu);
        menuAjouter_employe->setObjectName(QString::fromUtf8("menuAjouter_employe"));
        EmployeGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(EmployeGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EmployeGUIClass->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_employe->menuAction());
        menuMenu->addAction(actionQuitter);
        menuAjouter_employe->addAction(actionCommission);
        menuAjouter_employe->addAction(actionHoraire);
        menuAjouter_employe->addAction(actionPatron);

        retranslateUi(EmployeGUIClass);
        QObject::connect(actionQuitter, SIGNAL(triggered()), EmployeGUIClass, SLOT(close()));

        QMetaObject::connectSlotsByName(EmployeGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *EmployeGUIClass)
    {
        EmployeGUIClass->setWindowTitle(QApplication::translate("EmployeGUIClass", "MainWindow", nullptr));
        actionQuitter->setText(QApplication::translate("EmployeGUIClass", "Quitter", nullptr));
        actionCommission->setText(QApplication::translate("EmployeGUIClass", "Commission", nullptr));
        actionHoraire->setText(QApplication::translate("EmployeGUIClass", "Horaire", nullptr));
        actionPatron->setText(QApplication::translate("EmployeGUIClass", "Patron", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("EmployeGUIClass", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("EmployeGUIClass", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("EmployeGUIClass", "Date de naissance", nullptr));
        menuMenu->setTitle(QApplication::translate("EmployeGUIClass", "Menu", nullptr));
        menuAjouter_employe->setTitle(QApplication::translate("EmployeGUIClass", "Ajouter employe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeGUIClass: public Ui_EmployeGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEGUI_H

/********************************************************************************
** Form generated from reading UI file 'employegui.ui'
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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeGUIClass
{
public:
    QAction *actionCharger_a_partir_de;
    QAction *actionSauvegarder_dans;
    QAction *actionCommis;
    QAction *actionHoraire;
    QAction *actionPatron;
    QAction *actionCommis_sup;
    QAction *actionHoraire_sup;
    QAction *actionPatron_sup;
    QAction *actionExit;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QTextBrowser *textBrowser;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuActions;
    QMenu *menuAjouter_un_employer;
    QMenu *menuSupprimer_un_employe;
    QToolBar *toolBar;

    void setupUi(QMainWindow *EmployeGUIClass)
    {
        if (EmployeGUIClass->objectName().isEmpty())
            EmployeGUIClass->setObjectName(QString::fromUtf8("EmployeGUIClass"));
        EmployeGUIClass->resize(905, 600);
        actionCharger_a_partir_de = new QAction(EmployeGUIClass);
        actionCharger_a_partir_de->setObjectName(QString::fromUtf8("actionCharger_a_partir_de"));
        actionSauvegarder_dans = new QAction(EmployeGUIClass);
        actionSauvegarder_dans->setObjectName(QString::fromUtf8("actionSauvegarder_dans"));
        actionCommis = new QAction(EmployeGUIClass);
        actionCommis->setObjectName(QString::fromUtf8("actionCommis"));
        actionHoraire = new QAction(EmployeGUIClass);
        actionHoraire->setObjectName(QString::fromUtf8("actionHoraire"));
        actionPatron = new QAction(EmployeGUIClass);
        actionPatron->setObjectName(QString::fromUtf8("actionPatron"));
        actionCommis_sup = new QAction(EmployeGUIClass);
        actionCommis_sup->setObjectName(QString::fromUtf8("actionCommis_sup"));
        actionHoraire_sup = new QAction(EmployeGUIClass);
        actionHoraire_sup->setObjectName(QString::fromUtf8("actionHoraire_sup"));
        actionPatron_sup = new QAction(EmployeGUIClass);
        actionPatron_sup->setObjectName(QString::fromUtf8("actionPatron_sup"));
        actionExit = new QAction(EmployeGUIClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
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
        tableWidget->setGeometry(QRect(10, 10, 561, 521));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setColumnCount(3);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(580, 10, 311, 521));
        EmployeGUIClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(EmployeGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EmployeGUIClass->setStatusBar(statusbar);
        menubar = new QMenuBar(EmployeGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 905, 22));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuActions = new QMenu(menubar);
        menuActions->setObjectName(QString::fromUtf8("menuActions"));
        menuAjouter_un_employer = new QMenu(menuActions);
        menuAjouter_un_employer->setObjectName(QString::fromUtf8("menuAjouter_un_employer"));
        menuSupprimer_un_employe = new QMenu(menuActions);
        menuSupprimer_un_employe->setObjectName(QString::fromUtf8("menuSupprimer_un_employe"));
        EmployeGUIClass->setMenuBar(menubar);
        toolBar = new QToolBar(EmployeGUIClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        EmployeGUIClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuActions->menuAction());
        menuFichier->addAction(actionCharger_a_partir_de);
        menuFichier->addAction(actionSauvegarder_dans);
        menuFichier->addSeparator();
        menuFichier->addAction(actionExit);
        menuActions->addAction(menuAjouter_un_employer->menuAction());
        menuActions->addAction(menuSupprimer_un_employe->menuAction());
        menuAjouter_un_employer->addAction(actionCommis);
        menuAjouter_un_employer->addAction(actionHoraire);
        menuAjouter_un_employer->addAction(actionPatron);
        menuSupprimer_un_employe->addAction(actionCommis_sup);
        menuSupprimer_un_employe->addAction(actionHoraire_sup);
        menuSupprimer_un_employe->addAction(actionPatron_sup);

        retranslateUi(EmployeGUIClass);
        QObject::connect(tableWidget, SIGNAL(cellClicked(int,int)), EmployeGUIClass, SLOT(selectionLigneTable()));

        QMetaObject::connectSlotsByName(EmployeGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *EmployeGUIClass)
    {
        EmployeGUIClass->setWindowTitle(QApplication::translate("EmployeGUIClass", "Gestion Employe GIF-1003", nullptr));
        actionCharger_a_partir_de->setText(QApplication::translate("EmployeGUIClass", "Charger a partir de ..", nullptr));
        actionSauvegarder_dans->setText(QApplication::translate("EmployeGUIClass", "Sauvegarder dans ...", nullptr));
        actionCommis->setText(QApplication::translate("EmployeGUIClass", "Commis", nullptr));
        actionHoraire->setText(QApplication::translate("EmployeGUIClass", "Horaire", nullptr));
        actionPatron->setText(QApplication::translate("EmployeGUIClass", "Patron", nullptr));
        actionCommis_sup->setText(QApplication::translate("EmployeGUIClass", "Commis", nullptr));
        actionHoraire_sup->setText(QApplication::translate("EmployeGUIClass", "Horaire", nullptr));
        actionPatron_sup->setText(QApplication::translate("EmployeGUIClass", "Patron", nullptr));
        actionExit->setText(QApplication::translate("EmployeGUIClass", "Exit", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("EmployeGUIClass", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("EmployeGUIClass", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("EmployeGUIClass", "Date de naissance", nullptr));
        menuFichier->setTitle(QApplication::translate("EmployeGUIClass", "Fichier", nullptr));
        menuActions->setTitle(QApplication::translate("EmployeGUIClass", "Actions", nullptr));
        menuAjouter_un_employer->setTitle(QApplication::translate("EmployeGUIClass", "Ajouter un employer", nullptr));
        menuSupprimer_un_employe->setTitle(QApplication::translate("EmployeGUIClass", "Supprimer un employe", nullptr));
        toolBar->setWindowTitle(QApplication::translate("EmployeGUIClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeGUIClass: public Ui_EmployeGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEGUI_H

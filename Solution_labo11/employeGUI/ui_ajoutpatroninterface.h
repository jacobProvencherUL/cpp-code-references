/********************************************************************************
** Form generated from reading UI file 'ajoutpatroninterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTPATRONINTERFACE_H
#define UI_AJOUTPATRONINTERFACE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutPatronInterfaceClass
{
public:
    QLabel *label_prenom;
    QLineEdit *lineEdit_prenom;
    QLabel *label_titre;
    QSpinBox *spinBox_departement;
    QDateEdit *dateEdit;
    QPushButton *pushButton_validePatron;
    QLabel *label_nom;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_salaireHebdo;
    QLabel *label_salaireHebdo;
    QLabel *label_departement;
    QLabel *label_dateNaissance;

    void setupUi(QDialog *AjoutPatronInterfaceClass)
    {
        if (AjoutPatronInterfaceClass->objectName().isEmpty())
            AjoutPatronInterfaceClass->setObjectName(QString::fromUtf8("AjoutPatronInterfaceClass"));
        AjoutPatronInterfaceClass->resize(440, 413);
        label_prenom = new QLabel(AjoutPatronInterfaceClass);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(40, 130, 111, 31));
        lineEdit_prenom = new QLineEdit(AjoutPatronInterfaceClass);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(170, 130, 221, 31));
        label_titre = new QLabel(AjoutPatronInterfaceClass);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(90, 10, 271, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_titre->setFont(font);
        label_titre->setAlignment(Qt::AlignCenter);
        spinBox_departement = new QSpinBox(AjoutPatronInterfaceClass);
        spinBox_departement->setObjectName(QString::fromUtf8("spinBox_departement"));
        spinBox_departement->setGeometry(QRect(170, 280, 81, 27));
        spinBox_departement->setMinimum(1);
        spinBox_departement->setMaximum(10);
        dateEdit = new QDateEdit(AjoutPatronInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(170, 180, 121, 27));
        dateEdit->setMaximumDate(QDate(7937, 12, 31));
        dateEdit->setMinimumDate(QDate(1770, 1, 1));
        dateEdit->setCalendarPopup(true);
        pushButton_validePatron = new QPushButton(AjoutPatronInterfaceClass);
        pushButton_validePatron->setObjectName(QString::fromUtf8("pushButton_validePatron"));
        pushButton_validePatron->setGeometry(QRect(130, 350, 181, 27));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_validePatron->setFont(font1);
        label_nom = new QLabel(AjoutPatronInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(40, 80, 111, 31));
        lineEdit_nom = new QLineEdit(AjoutPatronInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(170, 80, 221, 31));
        lineEdit_salaireHebdo = new QLineEdit(AjoutPatronInterfaceClass);
        lineEdit_salaireHebdo->setObjectName(QString::fromUtf8("lineEdit_salaireHebdo"));
        lineEdit_salaireHebdo->setGeometry(QRect(170, 230, 221, 31));
        label_salaireHebdo = new QLabel(AjoutPatronInterfaceClass);
        label_salaireHebdo->setObjectName(QString::fromUtf8("label_salaireHebdo"));
        label_salaireHebdo->setGeometry(QRect(40, 230, 111, 31));
        label_departement = new QLabel(AjoutPatronInterfaceClass);
        label_departement->setObjectName(QString::fromUtf8("label_departement"));
        label_departement->setGeometry(QRect(40, 280, 111, 31));
        label_dateNaissance = new QLabel(AjoutPatronInterfaceClass);
        label_dateNaissance->setObjectName(QString::fromUtf8("label_dateNaissance"));
        label_dateNaissance->setGeometry(QRect(40, 180, 111, 31));

        retranslateUi(AjoutPatronInterfaceClass);

        QMetaObject::connectSlotsByName(AjoutPatronInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *AjoutPatronInterfaceClass)
    {
        AjoutPatronInterfaceClass->setWindowTitle(QApplication::translate("AjoutPatronInterfaceClass", "AjoutPatronInterface", nullptr));
        label_prenom->setText(QApplication::translate("AjoutPatronInterfaceClass", "Prenom :", nullptr));
        label_titre->setText(QApplication::translate("AjoutPatronInterfaceClass", "AJout d'un patron", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("AjoutPatronInterfaceClass", "dd-MM-yyyy", nullptr));
        pushButton_validePatron->setText(QApplication::translate("AjoutPatronInterfaceClass", "Enregistrer nouvau patron", nullptr));
        label_nom->setText(QApplication::translate("AjoutPatronInterfaceClass", "Nom :", nullptr));
        label_salaireHebdo->setText(QApplication::translate("AjoutPatronInterfaceClass", "Salaire hebdo :", nullptr));
        label_departement->setText(QApplication::translate("AjoutPatronInterfaceClass", "Departement :", nullptr));
        label_dateNaissance->setText(QApplication::translate("AjoutPatronInterfaceClass", "Date de naissance :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutPatronInterfaceClass: public Ui_AjoutPatronInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTPATRONINTERFACE_H

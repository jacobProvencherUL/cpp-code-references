/********************************************************************************
** Form generated from reading UI file 'patronUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATRONUI_H
#define UI_PATRONUI_H

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
    QLabel *label_AjoutPatronInterface;
    QLabel *label_date;
    QDateEdit *dateEdit;
    QLabel *label_salaire;
    QLabel *label_codeDepartement;
    QLabel *label_nom;
    QSpinBox *spinBox_codeDepartement;
    QLineEdit *lineEdit_prenom;
    QLabel *label_prenom;
    QLineEdit *lineEdit_salaire;
    QPushButton *pushButton;
    QLineEdit *lineEdit_nom;

    void setupUi(QDialog *AjoutPatronInterfaceClass)
    {
        if (AjoutPatronInterfaceClass->objectName().isEmpty())
            AjoutPatronInterfaceClass->setObjectName(QString::fromUtf8("AjoutPatronInterfaceClass"));
        AjoutPatronInterfaceClass->resize(545, 474);
        label_AjoutPatronInterface = new QLabel(AjoutPatronInterfaceClass);
        label_AjoutPatronInterface->setObjectName(QString::fromUtf8("label_AjoutPatronInterface"));
        label_AjoutPatronInterface->setGeometry(QRect(140, 20, 271, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_AjoutPatronInterface->setFont(font);
        label_date = new QLabel(AjoutPatronInterfaceClass);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setGeometry(QRect(50, 200, 121, 41));
        dateEdit = new QDateEdit(AjoutPatronInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(230, 200, 141, 31));
        dateEdit->setMaximumDate(QDate(2037, 12, 31));
        dateEdit->setMinimumDate(QDate(1970, 1, 1));
        dateEdit->setCalendarPopup(true);
        label_salaire = new QLabel(AjoutPatronInterfaceClass);
        label_salaire->setObjectName(QString::fromUtf8("label_salaire"));
        label_salaire->setGeometry(QRect(50, 250, 121, 41));
        label_codeDepartement = new QLabel(AjoutPatronInterfaceClass);
        label_codeDepartement->setObjectName(QString::fromUtf8("label_codeDepartement"));
        label_codeDepartement->setGeometry(QRect(50, 310, 121, 41));
        label_nom = new QLabel(AjoutPatronInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(50, 80, 121, 41));
        spinBox_codeDepartement = new QSpinBox(AjoutPatronInterfaceClass);
        spinBox_codeDepartement->setObjectName(QString::fromUtf8("spinBox_codeDepartement"));
        spinBox_codeDepartement->setGeometry(QRect(230, 310, 61, 31));
        spinBox_codeDepartement->setMinimum(1);
        spinBox_codeDepartement->setMaximum(100);
        lineEdit_prenom = new QLineEdit(AjoutPatronInterfaceClass);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(230, 140, 261, 41));
        label_prenom = new QLabel(AjoutPatronInterfaceClass);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(50, 140, 121, 41));
        lineEdit_salaire = new QLineEdit(AjoutPatronInterfaceClass);
        lineEdit_salaire->setObjectName(QString::fromUtf8("lineEdit_salaire"));
        lineEdit_salaire->setGeometry(QRect(230, 250, 261, 41));
        pushButton = new QPushButton(AjoutPatronInterfaceClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 390, 111, 31));
        lineEdit_nom = new QLineEdit(AjoutPatronInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(230, 80, 261, 41));

        retranslateUi(AjoutPatronInterfaceClass);

        QMetaObject::connectSlotsByName(AjoutPatronInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *AjoutPatronInterfaceClass)
    {
        AjoutPatronInterfaceClass->setWindowTitle(QApplication::translate("AjoutPatronInterfaceClass", "AjoutPatronInterface", nullptr));
        label_AjoutPatronInterface->setText(QApplication::translate("AjoutPatronInterfaceClass", "Ajouter un employe patron", nullptr));
        label_date->setText(QApplication::translate("AjoutPatronInterfaceClass", "Date de naissance", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("AjoutPatronInterfaceClass", "dd-MM-yy", nullptr));
        label_salaire->setText(QApplication::translate("AjoutPatronInterfaceClass", "Salaire", nullptr));
        label_codeDepartement->setText(QApplication::translate("AjoutPatronInterfaceClass", "Code departement", nullptr));
        label_nom->setText(QApplication::translate("AjoutPatronInterfaceClass", "Nom", nullptr));
        label_prenom->setText(QApplication::translate("AjoutPatronInterfaceClass", "Prenom", nullptr));
        pushButton->setText(QApplication::translate("AjoutPatronInterfaceClass", "Enregistrer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutPatronInterfaceClass: public Ui_AjoutPatronInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATRONUI_H

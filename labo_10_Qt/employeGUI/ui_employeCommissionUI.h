/********************************************************************************
** Form generated from reading UI file 'employeCommissionUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYECOMMISSIONUI_H
#define UI_EMPLOYECOMMISSIONUI_H

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

class Ui_AjoutCommisInterfaceClass
{
public:
    QLabel *label_nom;
    QLabel *label_AjoutCommisInterface;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLabel *label_prenom;
    QDateEdit *dateEdit;
    QLabel *label_date;
    QLineEdit *lineEdit_salaire;
    QLabel *label_salaire;
    QLineEdit *lineEdit_commission;
    QLabel *label_commission;
    QSpinBox *spinBox_codeDepartement;
    QLabel *label_codeDepartement;
    QSpinBox *spinBox_quantite;
    QLabel *label_quantite;
    QPushButton *pushButton;

    void setupUi(QDialog *AjoutCommisInterfaceClass)
    {
        if (AjoutCommisInterfaceClass->objectName().isEmpty())
            AjoutCommisInterfaceClass->setObjectName(QString::fromUtf8("AjoutCommisInterfaceClass"));
        AjoutCommisInterfaceClass->resize(559, 546);
        label_nom = new QLabel(AjoutCommisInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(30, 80, 121, 41));
        label_AjoutCommisInterface = new QLabel(AjoutCommisInterfaceClass);
        label_AjoutCommisInterface->setObjectName(QString::fromUtf8("label_AjoutCommisInterface"));
        label_AjoutCommisInterface->setGeometry(QRect(120, 20, 271, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_AjoutCommisInterface->setFont(font);
        lineEdit_nom = new QLineEdit(AjoutCommisInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(210, 80, 261, 41));
        lineEdit_prenom = new QLineEdit(AjoutCommisInterfaceClass);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(210, 140, 261, 41));
        label_prenom = new QLabel(AjoutCommisInterfaceClass);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(30, 140, 121, 41));
        dateEdit = new QDateEdit(AjoutCommisInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(210, 200, 141, 31));
        dateEdit->setMaximumDate(QDate(2037, 12, 31));
        dateEdit->setMinimumDate(QDate(1970, 1, 1));
        dateEdit->setCalendarPopup(true);
        label_date = new QLabel(AjoutCommisInterfaceClass);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setGeometry(QRect(30, 200, 121, 41));
        lineEdit_salaire = new QLineEdit(AjoutCommisInterfaceClass);
        lineEdit_salaire->setObjectName(QString::fromUtf8("lineEdit_salaire"));
        lineEdit_salaire->setGeometry(QRect(210, 250, 261, 41));
        label_salaire = new QLabel(AjoutCommisInterfaceClass);
        label_salaire->setObjectName(QString::fromUtf8("label_salaire"));
        label_salaire->setGeometry(QRect(30, 250, 121, 41));
        lineEdit_commission = new QLineEdit(AjoutCommisInterfaceClass);
        lineEdit_commission->setObjectName(QString::fromUtf8("lineEdit_commission"));
        lineEdit_commission->setGeometry(QRect(210, 310, 261, 41));
        label_commission = new QLabel(AjoutCommisInterfaceClass);
        label_commission->setObjectName(QString::fromUtf8("label_commission"));
        label_commission->setGeometry(QRect(30, 310, 121, 41));
        spinBox_codeDepartement = new QSpinBox(AjoutCommisInterfaceClass);
        spinBox_codeDepartement->setObjectName(QString::fromUtf8("spinBox_codeDepartement"));
        spinBox_codeDepartement->setGeometry(QRect(210, 370, 61, 31));
        spinBox_codeDepartement->setMinimum(1);
        spinBox_codeDepartement->setMaximum(100);
        label_codeDepartement = new QLabel(AjoutCommisInterfaceClass);
        label_codeDepartement->setObjectName(QString::fromUtf8("label_codeDepartement"));
        label_codeDepartement->setGeometry(QRect(30, 370, 121, 41));
        spinBox_quantite = new QSpinBox(AjoutCommisInterfaceClass);
        spinBox_quantite->setObjectName(QString::fromUtf8("spinBox_quantite"));
        spinBox_quantite->setGeometry(QRect(210, 420, 61, 31));
        spinBox_quantite->setMinimum(0);
        spinBox_quantite->setMaximum(100);
        spinBox_quantite->setValue(0);
        label_quantite = new QLabel(AjoutCommisInterfaceClass);
        label_quantite->setObjectName(QString::fromUtf8("label_quantite"));
        label_quantite->setGeometry(QRect(30, 420, 121, 41));
        pushButton = new QPushButton(AjoutCommisInterfaceClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 480, 111, 31));

        retranslateUi(AjoutCommisInterfaceClass);

        QMetaObject::connectSlotsByName(AjoutCommisInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *AjoutCommisInterfaceClass)
    {
        AjoutCommisInterfaceClass->setWindowTitle(QApplication::translate("AjoutCommisInterfaceClass", "AjoutCommisInterface", nullptr));
        label_nom->setText(QApplication::translate("AjoutCommisInterfaceClass", "Nom", nullptr));
        label_AjoutCommisInterface->setText(QApplication::translate("AjoutCommisInterfaceClass", "Ajouter un employe commission", nullptr));
        label_prenom->setText(QApplication::translate("AjoutCommisInterfaceClass", "Prenom", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("AjoutCommisInterfaceClass", "dd-MM-yy", nullptr));
        label_date->setText(QApplication::translate("AjoutCommisInterfaceClass", "Date de naissance", nullptr));
        label_salaire->setText(QApplication::translate("AjoutCommisInterfaceClass", "Salaire", nullptr));
        label_commission->setText(QApplication::translate("AjoutCommisInterfaceClass", "Commission", nullptr));
        label_codeDepartement->setText(QApplication::translate("AjoutCommisInterfaceClass", "Code departement", nullptr));
        label_quantite->setText(QApplication::translate("AjoutCommisInterfaceClass", "Quantite", nullptr));
        pushButton->setText(QApplication::translate("AjoutCommisInterfaceClass", "Enregistrer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutCommisInterfaceClass: public Ui_AjoutCommisInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYECOMMISSIONUI_H

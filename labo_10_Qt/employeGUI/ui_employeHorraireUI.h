/********************************************************************************
** Form generated from reading UI file 'employeHorraireUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEHORRAIREUI_H
#define UI_EMPLOYEHORRAIREUI_H

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

class Ui_AjoutHoraireInterfaceClass
{
public:
    QLineEdit *lineEdit_nom;
    QDateEdit *dateEdit;
    QLabel *label_prenom;
    QSpinBox *spinBox_codeDepartement;
    QLabel *label_nombreHeures;
    QLabel *label_AjoutHoraireInterface;
    QLabel *label_nom;
    QLabel *label_date;
    QLabel *label_codeDepartement;
    QSpinBox *spinBox_nbHeures;
    QLineEdit *lineEdit_prenom;
    QPushButton *pushButton;
    QLabel *label_tauxHoraire;
    QLineEdit *lineEdit_tauxHoraire;

    void setupUi(QDialog *AjoutHoraireInterfaceClass)
    {
        if (AjoutHoraireInterfaceClass->objectName().isEmpty())
            AjoutHoraireInterfaceClass->setObjectName(QString::fromUtf8("AjoutHoraireInterfaceClass"));
        AjoutHoraireInterfaceClass->resize(547, 494);
        lineEdit_nom = new QLineEdit(AjoutHoraireInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(220, 70, 261, 41));
        dateEdit = new QDateEdit(AjoutHoraireInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(220, 190, 141, 31));
        dateEdit->setMaximumDate(QDate(2037, 12, 31));
        dateEdit->setMinimumDate(QDate(1970, 1, 1));
        dateEdit->setCalendarPopup(true);
        label_prenom = new QLabel(AjoutHoraireInterfaceClass);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(40, 130, 121, 41));
        spinBox_codeDepartement = new QSpinBox(AjoutHoraireInterfaceClass);
        spinBox_codeDepartement->setObjectName(QString::fromUtf8("spinBox_codeDepartement"));
        spinBox_codeDepartement->setGeometry(QRect(220, 300, 61, 31));
        spinBox_codeDepartement->setMinimum(1);
        spinBox_codeDepartement->setMaximum(100);
        label_nombreHeures = new QLabel(AjoutHoraireInterfaceClass);
        label_nombreHeures->setObjectName(QString::fromUtf8("label_nombreHeures"));
        label_nombreHeures->setGeometry(QRect(40, 350, 121, 41));
        label_AjoutHoraireInterface = new QLabel(AjoutHoraireInterfaceClass);
        label_AjoutHoraireInterface->setObjectName(QString::fromUtf8("label_AjoutHoraireInterface"));
        label_AjoutHoraireInterface->setGeometry(QRect(170, 10, 231, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_AjoutHoraireInterface->setFont(font);
        label_nom = new QLabel(AjoutHoraireInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(40, 70, 121, 41));
        label_date = new QLabel(AjoutHoraireInterfaceClass);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setGeometry(QRect(40, 190, 121, 41));
        label_codeDepartement = new QLabel(AjoutHoraireInterfaceClass);
        label_codeDepartement->setObjectName(QString::fromUtf8("label_codeDepartement"));
        label_codeDepartement->setGeometry(QRect(40, 300, 121, 41));
        spinBox_nbHeures = new QSpinBox(AjoutHoraireInterfaceClass);
        spinBox_nbHeures->setObjectName(QString::fromUtf8("spinBox_nbHeures"));
        spinBox_nbHeures->setGeometry(QRect(220, 350, 61, 31));
        spinBox_nbHeures->setMinimum(0);
        spinBox_nbHeures->setMaximum(100);
        spinBox_nbHeures->setValue(1);
        lineEdit_prenom = new QLineEdit(AjoutHoraireInterfaceClass);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(220, 130, 261, 41));
        pushButton = new QPushButton(AjoutHoraireInterfaceClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 420, 111, 31));
        label_tauxHoraire = new QLabel(AjoutHoraireInterfaceClass);
        label_tauxHoraire->setObjectName(QString::fromUtf8("label_tauxHoraire"));
        label_tauxHoraire->setGeometry(QRect(40, 240, 121, 41));
        lineEdit_tauxHoraire = new QLineEdit(AjoutHoraireInterfaceClass);
        lineEdit_tauxHoraire->setObjectName(QString::fromUtf8("lineEdit_tauxHoraire"));
        lineEdit_tauxHoraire->setGeometry(QRect(220, 240, 261, 41));

        retranslateUi(AjoutHoraireInterfaceClass);

        QMetaObject::connectSlotsByName(AjoutHoraireInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *AjoutHoraireInterfaceClass)
    {
        AjoutHoraireInterfaceClass->setWindowTitle(QApplication::translate("AjoutHoraireInterfaceClass", "AjoutHoraireInterface", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("AjoutHoraireInterfaceClass", "dd-MM-yy", nullptr));
        label_prenom->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Prenom", nullptr));
        label_nombreHeures->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Nombre d'heures", nullptr));
        label_AjoutHoraireInterface->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Ajouter un employe horaire", nullptr));
        label_nom->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Nom", nullptr));
        label_date->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Date de naissance", nullptr));
        label_codeDepartement->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Code departement", nullptr));
        pushButton->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Enregistrer", nullptr));
        label_tauxHoraire->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Taux horaire", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutHoraireInterfaceClass: public Ui_AjoutHoraireInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEHORRAIREUI_H

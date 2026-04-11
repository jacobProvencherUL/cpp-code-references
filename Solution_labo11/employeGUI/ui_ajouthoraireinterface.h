/********************************************************************************
** Form generated from reading UI file 'ajouthoraireinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTHORAIREINTERFACE_H
#define UI_AJOUTHORAIREINTERFACE_H

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
    QLabel *label_titre;
    QPushButton *pushButton_valideHoraire;
    QLineEdit *lineEdit_tauxHoraire;
    QLabel *label_departement;
    QLabel *label_tauxHoraire;
    QLabel *label_prenom;
    QLabel *label_nom;
    QLineEdit *lineEdit_nom;
    QDateEdit *dateEdit;
    QLabel *label_dateNaissance;
    QLabel *label_nombreHeure;
    QSpinBox *spinBox_nombreHeure;
    QLineEdit *lineEdit_prenom;
    QSpinBox *spinBox_departement;

    void setupUi(QDialog *AjoutHoraireInterfaceClass)
    {
        if (AjoutHoraireInterfaceClass->objectName().isEmpty())
            AjoutHoraireInterfaceClass->setObjectName(QString::fromUtf8("AjoutHoraireInterfaceClass"));
        AjoutHoraireInterfaceClass->resize(451, 430);
        label_titre = new QLabel(AjoutHoraireInterfaceClass);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(90, 10, 271, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_titre->setFont(font);
        label_titre->setAlignment(Qt::AlignCenter);
        pushButton_valideHoraire = new QPushButton(AjoutHoraireInterfaceClass);
        pushButton_valideHoraire->setObjectName(QString::fromUtf8("pushButton_valideHoraire"));
        pushButton_valideHoraire->setGeometry(QRect(130, 390, 181, 27));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_valideHoraire->setFont(font1);
        lineEdit_tauxHoraire = new QLineEdit(AjoutHoraireInterfaceClass);
        lineEdit_tauxHoraire->setObjectName(QString::fromUtf8("lineEdit_tauxHoraire"));
        lineEdit_tauxHoraire->setGeometry(QRect(170, 230, 221, 31));
        label_departement = new QLabel(AjoutHoraireInterfaceClass);
        label_departement->setObjectName(QString::fromUtf8("label_departement"));
        label_departement->setGeometry(QRect(40, 330, 111, 31));
        label_tauxHoraire = new QLabel(AjoutHoraireInterfaceClass);
        label_tauxHoraire->setObjectName(QString::fromUtf8("label_tauxHoraire"));
        label_tauxHoraire->setGeometry(QRect(40, 230, 111, 31));
        label_prenom = new QLabel(AjoutHoraireInterfaceClass);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(40, 130, 111, 31));
        label_nom = new QLabel(AjoutHoraireInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(40, 80, 111, 31));
        lineEdit_nom = new QLineEdit(AjoutHoraireInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(170, 80, 221, 31));
        dateEdit = new QDateEdit(AjoutHoraireInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(170, 180, 121, 27));
        dateEdit->setMaximumDate(QDate(7937, 12, 31));
        dateEdit->setMinimumDate(QDate(1770, 1, 1));
        dateEdit->setCalendarPopup(true);
        label_dateNaissance = new QLabel(AjoutHoraireInterfaceClass);
        label_dateNaissance->setObjectName(QString::fromUtf8("label_dateNaissance"));
        label_dateNaissance->setGeometry(QRect(40, 180, 111, 31));
        label_nombreHeure = new QLabel(AjoutHoraireInterfaceClass);
        label_nombreHeure->setObjectName(QString::fromUtf8("label_nombreHeure"));
        label_nombreHeure->setGeometry(QRect(40, 280, 111, 31));
        spinBox_nombreHeure = new QSpinBox(AjoutHoraireInterfaceClass);
        spinBox_nombreHeure->setObjectName(QString::fromUtf8("spinBox_nombreHeure"));
        spinBox_nombreHeure->setGeometry(QRect(170, 280, 81, 27));
        spinBox_nombreHeure->setMinimum(1);
        spinBox_nombreHeure->setMaximum(500);
        lineEdit_prenom = new QLineEdit(AjoutHoraireInterfaceClass);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(170, 130, 221, 31));
        spinBox_departement = new QSpinBox(AjoutHoraireInterfaceClass);
        spinBox_departement->setObjectName(QString::fromUtf8("spinBox_departement"));
        spinBox_departement->setGeometry(QRect(170, 330, 81, 27));
        spinBox_departement->setMinimum(1);
        spinBox_departement->setMaximum(10);

        retranslateUi(AjoutHoraireInterfaceClass);

        QMetaObject::connectSlotsByName(AjoutHoraireInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *AjoutHoraireInterfaceClass)
    {
        AjoutHoraireInterfaceClass->setWindowTitle(QApplication::translate("AjoutHoraireInterfaceClass", "AjoutHoraireInterface", nullptr));
        label_titre->setText(QApplication::translate("AjoutHoraireInterfaceClass", "AJout d'un employe horaire", nullptr));
        pushButton_valideHoraire->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Enregistrer nouvel employe", nullptr));
        label_departement->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Departement :", nullptr));
        label_tauxHoraire->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Taux horaire :", nullptr));
        label_prenom->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Prenom :", nullptr));
        label_nom->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Nom :", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("AjoutHoraireInterfaceClass", "dd-MM-yyyy", nullptr));
        label_dateNaissance->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Date de naissance :", nullptr));
        label_nombreHeure->setText(QApplication::translate("AjoutHoraireInterfaceClass", "Nombre heures :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutHoraireInterfaceClass: public Ui_AjoutHoraireInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTHORAIREINTERFACE_H

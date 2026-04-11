/********************************************************************************
** Form generated from reading UI file 'ajoutcommisinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTCOMMISINTERFACE_H
#define UI_AJOUTCOMMISINTERFACE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutCommisInterfaceClass
{
public:
    QLabel *label_nom;
    QLineEdit *lineEdit_nom;
    QLabel *label_dateNaissance;
    QLabel *label_commission;
    QLineEdit *lineEdit_salaire;
    QPushButton *pushButton;
    QSpinBox *spinBox_codeDep;
    QLabel *label_codeDepartement;
    QLineEdit *lineEdit_prenom;
    QLabel *label_titre;
    QLineEdit *lineEdit_commission;
    QDateEdit *dateEdit;
    QLabel *label_prenom;
    QLabel *label_salaire;
    QSpinBox *spinBox_quantite;
    QLabel *label_quantite;

    void setupUi(QDialog *AjoutCommisInterfaceClass)
    {
        if (AjoutCommisInterfaceClass->objectName().isEmpty())
            AjoutCommisInterfaceClass->setObjectName(QString::fromUtf8("AjoutCommisInterfaceClass"));
        AjoutCommisInterfaceClass->resize(479, 504);
        label_nom = new QLabel(AjoutCommisInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(30, 80, 91, 41));
        lineEdit_nom = new QLineEdit(AjoutCommisInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(180, 86, 261, 31));
        label_dateNaissance = new QLabel(AjoutCommisInterfaceClass);
        label_dateNaissance->setObjectName(QString::fromUtf8("label_dateNaissance"));
        label_dateNaissance->setGeometry(QRect(30, 180, 121, 41));
        label_commission = new QLabel(AjoutCommisInterfaceClass);
        label_commission->setObjectName(QString::fromUtf8("label_commission"));
        label_commission->setGeometry(QRect(30, 280, 91, 41));
        lineEdit_salaire = new QLineEdit(AjoutCommisInterfaceClass);
        lineEdit_salaire->setObjectName(QString::fromUtf8("lineEdit_salaire"));
        lineEdit_salaire->setGeometry(QRect(180, 230, 261, 31));
        pushButton = new QPushButton(AjoutCommisInterfaceClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 450, 171, 27));
        spinBox_codeDep = new QSpinBox(AjoutCommisInterfaceClass);
        spinBox_codeDep->setObjectName(QString::fromUtf8("spinBox_codeDep"));
        spinBox_codeDep->setGeometry(QRect(180, 380, 49, 27));
        spinBox_codeDep->setMinimum(1);
        spinBox_codeDep->setMaximum(10);
        label_codeDepartement = new QLabel(AjoutCommisInterfaceClass);
        label_codeDepartement->setObjectName(QString::fromUtf8("label_codeDepartement"));
        label_codeDepartement->setGeometry(QRect(30, 380, 151, 41));
        lineEdit_prenom = new QLineEdit(AjoutCommisInterfaceClass);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(180, 130, 261, 31));
        label_titre = new QLabel(AjoutCommisInterfaceClass);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(120, 10, 241, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_titre->setFont(font);
        lineEdit_commission = new QLineEdit(AjoutCommisInterfaceClass);
        lineEdit_commission->setObjectName(QString::fromUtf8("lineEdit_commission"));
        lineEdit_commission->setGeometry(QRect(180, 280, 261, 31));
        dateEdit = new QDateEdit(AjoutCommisInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(180, 180, 181, 27));
        dateEdit->setMaximumDate(QDate(7937, 12, 31));
        dateEdit->setMinimumDate(QDate(1770, 1, 1));
        dateEdit->setCalendarPopup(true);
        label_prenom = new QLabel(AjoutCommisInterfaceClass);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(30, 130, 91, 41));
        label_salaire = new QLabel(AjoutCommisInterfaceClass);
        label_salaire->setObjectName(QString::fromUtf8("label_salaire"));
        label_salaire->setGeometry(QRect(30, 230, 91, 41));
        spinBox_quantite = new QSpinBox(AjoutCommisInterfaceClass);
        spinBox_quantite->setObjectName(QString::fromUtf8("spinBox_quantite"));
        spinBox_quantite->setGeometry(QRect(180, 340, 49, 27));
        spinBox_quantite->setMaximum(100);
        label_quantite = new QLabel(AjoutCommisInterfaceClass);
        label_quantite->setObjectName(QString::fromUtf8("label_quantite"));
        label_quantite->setGeometry(QRect(30, 330, 91, 41));

        retranslateUi(AjoutCommisInterfaceClass);

        QMetaObject::connectSlotsByName(AjoutCommisInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *AjoutCommisInterfaceClass)
    {
        AjoutCommisInterfaceClass->setWindowTitle(QApplication::translate("AjoutCommisInterfaceClass", "AjoutCommisInterface", 0, QApplication::UnicodeUTF8));
        label_nom->setText(QApplication::translate("AjoutCommisInterfaceClass", "Nom :", 0, QApplication::UnicodeUTF8));
        label_dateNaissance->setText(QApplication::translate("AjoutCommisInterfaceClass", "Date de naissance :", 0, QApplication::UnicodeUTF8));
        label_commission->setText(QApplication::translate("AjoutCommisInterfaceClass", "Commission :", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AjoutCommisInterfaceClass", "Valider le nouvel employe", 0, QApplication::UnicodeUTF8));
        label_codeDepartement->setText(QApplication::translate("AjoutCommisInterfaceClass", "Code de departement :", 0, QApplication::UnicodeUTF8));
        label_titre->setText(QApplication::translate("AjoutCommisInterfaceClass", "AJout d\342\200\231un employe commission", 0, QApplication::UnicodeUTF8));
        label_prenom->setText(QApplication::translate("AjoutCommisInterfaceClass", "Prenom :", 0, QApplication::UnicodeUTF8));
        label_salaire->setText(QApplication::translate("AjoutCommisInterfaceClass", "Salaire :", 0, QApplication::UnicodeUTF8));
        label_quantite->setText(QApplication::translate("AjoutCommisInterfaceClass", "Quantite :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AjoutCommisInterfaceClass: public Ui_AjoutCommisInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTCOMMISINTERFACE_H

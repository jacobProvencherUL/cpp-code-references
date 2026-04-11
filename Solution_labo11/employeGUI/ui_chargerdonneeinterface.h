/********************************************************************************
** Form generated from reading UI file 'chargerdonneeinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGERDONNEEINTERFACE_H
#define UI_CHARGERDONNEEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChargerDonneeInterfaceClass
{
public:
    QLineEdit *lineEdit_nom;
    QLabel *label_titre;
    QPushButton *pushButton_saveDonnee;
    QLabel *label_nom;

    void setupUi(QDialog *ChargerDonneeInterfaceClass)
    {
        if (ChargerDonneeInterfaceClass->objectName().isEmpty())
            ChargerDonneeInterfaceClass->setObjectName(QString::fromUtf8("ChargerDonneeInterfaceClass"));
        ChargerDonneeInterfaceClass->resize(400, 248);
        lineEdit_nom = new QLineEdit(ChargerDonneeInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(150, 100, 221, 31));
        label_titre = new QLabel(ChargerDonneeInterfaceClass);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(70, 30, 271, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_titre->setFont(font);
        label_titre->setAlignment(Qt::AlignCenter);
        pushButton_saveDonnee = new QPushButton(ChargerDonneeInterfaceClass);
        pushButton_saveDonnee->setObjectName(QString::fromUtf8("pushButton_saveDonnee"));
        pushButton_saveDonnee->setGeometry(QRect(110, 180, 181, 27));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_saveDonnee->setFont(font1);
        label_nom = new QLabel(ChargerDonneeInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(20, 100, 111, 31));

        retranslateUi(ChargerDonneeInterfaceClass);

        QMetaObject::connectSlotsByName(ChargerDonneeInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *ChargerDonneeInterfaceClass)
    {
        ChargerDonneeInterfaceClass->setWindowTitle(QApplication::translate("ChargerDonneeInterfaceClass", "ChargerDonneeInterface", nullptr));
        label_titre->setText(QApplication::translate("ChargerDonneeInterfaceClass", "Charger les donnees", nullptr));
        pushButton_saveDonnee->setText(QApplication::translate("ChargerDonneeInterfaceClass", "Charger les donnees", nullptr));
        label_nom->setText(QApplication::translate("ChargerDonneeInterfaceClass", "Nom du fichier :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChargerDonneeInterfaceClass: public Ui_ChargerDonneeInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGERDONNEEINTERFACE_H

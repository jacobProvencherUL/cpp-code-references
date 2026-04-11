/********************************************************************************
** Form generated from reading UI file 'enregistrerdonneeinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENREGISTRERDONNEEINTERFACE_H
#define UI_ENREGISTRERDONNEEINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EnregistrerDonneeInterfaceClass
{
public:
    QPushButton *pushButton_saveDonnee;
    QLineEdit *lineEdit_nom;
    QLabel *label_nom;
    QLabel *label_titre;

    void setupUi(QDialog *EnregistrerDonneeInterfaceClass)
    {
        if (EnregistrerDonneeInterfaceClass->objectName().isEmpty())
            EnregistrerDonneeInterfaceClass->setObjectName(QString::fromUtf8("EnregistrerDonneeInterfaceClass"));
        EnregistrerDonneeInterfaceClass->resize(400, 246);
        pushButton_saveDonnee = new QPushButton(EnregistrerDonneeInterfaceClass);
        pushButton_saveDonnee->setObjectName(QString::fromUtf8("pushButton_saveDonnee"));
        pushButton_saveDonnee->setGeometry(QRect(110, 180, 181, 27));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_saveDonnee->setFont(font);
        lineEdit_nom = new QLineEdit(EnregistrerDonneeInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(150, 100, 221, 31));
        label_nom = new QLabel(EnregistrerDonneeInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(20, 100, 111, 31));
        label_titre = new QLabel(EnregistrerDonneeInterfaceClass);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(70, 30, 271, 41));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_titre->setFont(font1);
        label_titre->setAlignment(Qt::AlignCenter);

        retranslateUi(EnregistrerDonneeInterfaceClass);

        QMetaObject::connectSlotsByName(EnregistrerDonneeInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *EnregistrerDonneeInterfaceClass)
    {
        EnregistrerDonneeInterfaceClass->setWindowTitle(QApplication::translate("EnregistrerDonneeInterfaceClass", "EnregistrerDonneeInterface", 0, QApplication::UnicodeUTF8));
        pushButton_saveDonnee->setText(QApplication::translate("EnregistrerDonneeInterfaceClass", "Enregistrer les donnees", 0, QApplication::UnicodeUTF8));
        label_nom->setText(QApplication::translate("EnregistrerDonneeInterfaceClass", "Nom du fichier :", 0, QApplication::UnicodeUTF8));
        label_titre->setText(QApplication::translate("EnregistrerDonneeInterfaceClass", "Enregistrer les donnees", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EnregistrerDonneeInterfaceClass: public Ui_EnregistrerDonneeInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENREGISTRERDONNEEINTERFACE_H

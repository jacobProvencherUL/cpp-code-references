/********************************************************************************
** Form generated from reading UI file 'supprimercommisinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERCOMMISINTERFACE_H
#define UI_SUPPRIMERCOMMISINTERFACE_H

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

class Ui_SupprimerCommisInterfaceClass
{
public:
    QLabel *label_prenom;
    QLabel *label_titre;
    QPushButton *pushButton;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_nom;
    QLabel *label_nom;

    void setupUi(QDialog *SupprimerCommisInterfaceClass)
    {
        if (SupprimerCommisInterfaceClass->objectName().isEmpty())
            SupprimerCommisInterfaceClass->setObjectName(QString::fromUtf8("SupprimerCommisInterfaceClass"));
        SupprimerCommisInterfaceClass->resize(400, 300);
        label_prenom = new QLabel(SupprimerCommisInterfaceClass);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(20, 150, 111, 31));
        label_titre = new QLabel(SupprimerCommisInterfaceClass);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(60, 20, 271, 41));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_titre->setFont(font);
        label_titre->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(SupprimerCommisInterfaceClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 240, 151, 27));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        lineEdit_prenom = new QLineEdit(SupprimerCommisInterfaceClass);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(150, 150, 221, 31));
        lineEdit_nom = new QLineEdit(SupprimerCommisInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(150, 100, 221, 31));
        label_nom = new QLabel(SupprimerCommisInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(20, 100, 111, 31));

        retranslateUi(SupprimerCommisInterfaceClass);

        QMetaObject::connectSlotsByName(SupprimerCommisInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *SupprimerCommisInterfaceClass)
    {
        SupprimerCommisInterfaceClass->setWindowTitle(QApplication::translate("SupprimerCommisInterfaceClass", "SupprimerCommisInterface", 0, QApplication::UnicodeUTF8));
        label_prenom->setText(QApplication::translate("SupprimerCommisInterfaceClass", "Prenom :", 0, QApplication::UnicodeUTF8));
        label_titre->setText(QApplication::translate("SupprimerCommisInterfaceClass", "Suppression d'un employe", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SupprimerCommisInterfaceClass", "Valider suppression", 0, QApplication::UnicodeUTF8));
        label_nom->setText(QApplication::translate("SupprimerCommisInterfaceClass", "Nom :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SupprimerCommisInterfaceClass: public Ui_SupprimerCommisInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERCOMMISINTERFACE_H

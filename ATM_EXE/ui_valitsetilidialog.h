/********************************************************************************
** Form generated from reading UI file 'valitsetilidialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALITSETILIDIALOG_H
#define UI_VALITSETILIDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ValitseTiliDialog
{
public:
    QPushButton *pushButtonCredit;
    QPushButton *pushButtonDebit;
    QLabel *labelValitseTili;

    void setupUi(QDialog *ValitseTiliDialog)
    {
        if (ValitseTiliDialog->objectName().isEmpty())
            ValitseTiliDialog->setObjectName(QStringLiteral("ValitseTiliDialog"));
        ValitseTiliDialog->resize(640, 480);
        pushButtonCredit = new QPushButton(ValitseTiliDialog);
        pushButtonCredit->setObjectName(QStringLiteral("pushButtonCredit"));
        pushButtonCredit->setGeometry(QRect(250, 190, 141, 61));
        pushButtonCredit->setIconSize(QSize(16, 16));
        pushButtonDebit = new QPushButton(ValitseTiliDialog);
        pushButtonDebit->setObjectName(QStringLiteral("pushButtonDebit"));
        pushButtonDebit->setGeometry(QRect(250, 320, 141, 61));
        labelValitseTili = new QLabel(ValitseTiliDialog);
        labelValitseTili->setObjectName(QStringLiteral("labelValitseTili"));
        labelValitseTili->setGeometry(QRect(210, 90, 221, 41));
        QFont font;
        font.setPointSize(22);
        labelValitseTili->setFont(font);
        labelValitseTili->setFrameShape(QFrame::StyledPanel);
        labelValitseTili->setFrameShadow(QFrame::Plain);
        labelValitseTili->setAlignment(Qt::AlignCenter);

        retranslateUi(ValitseTiliDialog);

        QMetaObject::connectSlotsByName(ValitseTiliDialog);
    } // setupUi

    void retranslateUi(QDialog *ValitseTiliDialog)
    {
        ValitseTiliDialog->setWindowTitle(QApplication::translate("ValitseTiliDialog", "Dialog", Q_NULLPTR));
        pushButtonCredit->setText(QApplication::translate("ValitseTiliDialog", "CREDIT", Q_NULLPTR));
        pushButtonDebit->setText(QApplication::translate("ValitseTiliDialog", "DEBIT", Q_NULLPTR));
        labelValitseTili->setText(QApplication::translate("ValitseTiliDialog", "Valitse tili", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ValitseTiliDialog: public Ui_ValitseTiliDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALITSETILIDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'valitsetoimintodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALITSETOIMINTODIALOG_H
#define UI_VALITSETOIMINTODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ValitseToimintoDialog
{
public:
    QPushButton *pushButtonSaldo;
    QLabel *labelValitseToiminto;
    QPushButton *pushButtonNosto;

    void setupUi(QDialog *ValitseToimintoDialog)
    {
        if (ValitseToimintoDialog->objectName().isEmpty())
            ValitseToimintoDialog->setObjectName(QStringLiteral("ValitseToimintoDialog"));
        ValitseToimintoDialog->setEnabled(true);
        ValitseToimintoDialog->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ValitseToimintoDialog->sizePolicy().hasHeightForWidth());
        ValitseToimintoDialog->setSizePolicy(sizePolicy);
        pushButtonSaldo = new QPushButton(ValitseToimintoDialog);
        pushButtonSaldo->setObjectName(QStringLiteral("pushButtonSaldo"));
        pushButtonSaldo->setGeometry(QRect(250, 190, 141, 61));
        labelValitseToiminto = new QLabel(ValitseToimintoDialog);
        labelValitseToiminto->setObjectName(QStringLiteral("labelValitseToiminto"));
        labelValitseToiminto->setGeometry(QRect(210, 90, 221, 41));
        QFont font;
        font.setPointSize(22);
        labelValitseToiminto->setFont(font);
        labelValitseToiminto->setFrameShape(QFrame::StyledPanel);
        labelValitseToiminto->setAlignment(Qt::AlignCenter);
        pushButtonNosto = new QPushButton(ValitseToimintoDialog);
        pushButtonNosto->setObjectName(QStringLiteral("pushButtonNosto"));
        pushButtonNosto->setGeometry(QRect(250, 320, 141, 61));

        retranslateUi(ValitseToimintoDialog);

        QMetaObject::connectSlotsByName(ValitseToimintoDialog);
    } // setupUi

    void retranslateUi(QDialog *ValitseToimintoDialog)
    {
        ValitseToimintoDialog->setWindowTitle(QApplication::translate("ValitseToimintoDialog", "Dialog", Q_NULLPTR));
        pushButtonSaldo->setText(QApplication::translate("ValitseToimintoDialog", "Saldo", Q_NULLPTR));
        labelValitseToiminto->setText(QApplication::translate("ValitseToimintoDialog", "Valitse Toiminto", Q_NULLPTR));
        pushButtonNosto->setText(QApplication::translate("ValitseToimintoDialog", "Nosto", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ValitseToimintoDialog: public Ui_ValitseToimintoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALITSETOIMINTODIALOG_H

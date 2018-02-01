/********************************************************************************
** Form generated from reading UI file 'saldodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALDODIALOG_H
#define UI_SALDODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SaldoDialog
{
public:
    QLabel *labelSaldoOtsikko;
    QPushButton *pushButtonLopeta;
    QPushButton *pushButtonPalaa;
    QLabel *labelTilinNimi;
    QLabel *labelSaldo;

    void setupUi(QDialog *SaldoDialog)
    {
        if (SaldoDialog->objectName().isEmpty())
            SaldoDialog->setObjectName(QStringLiteral("SaldoDialog"));
        SaldoDialog->setWindowModality(Qt::WindowModal);
        SaldoDialog->resize(640, 480);
        SaldoDialog->setModal(false);
        labelSaldoOtsikko = new QLabel(SaldoDialog);
        labelSaldoOtsikko->setObjectName(QStringLiteral("labelSaldoOtsikko"));
        labelSaldoOtsikko->setGeometry(QRect(210, 90, 221, 41));
        QFont font;
        font.setPointSize(22);
        labelSaldoOtsikko->setFont(font);
        labelSaldoOtsikko->setFrameShape(QFrame::StyledPanel);
        labelSaldoOtsikko->setAlignment(Qt::AlignCenter);
        pushButtonLopeta = new QPushButton(SaldoDialog);
        pushButtonLopeta->setObjectName(QStringLiteral("pushButtonLopeta"));
        pushButtonLopeta->setGeometry(QRect(400, 400, 141, 61));
        pushButtonPalaa = new QPushButton(SaldoDialog);
        pushButtonPalaa->setObjectName(QStringLiteral("pushButtonPalaa"));
        pushButtonPalaa->setGeometry(QRect(100, 400, 141, 61));
        labelTilinNimi = new QLabel(SaldoDialog);
        labelTilinNimi->setObjectName(QStringLiteral("labelTilinNimi"));
        labelTilinNimi->setGeometry(QRect(100, 220, 141, 41));
        labelSaldo = new QLabel(SaldoDialog);
        labelSaldo->setObjectName(QStringLiteral("labelSaldo"));
        labelSaldo->setGeometry(QRect(400, 220, 141, 41));
        labelSaldo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(SaldoDialog);

        QMetaObject::connectSlotsByName(SaldoDialog);
    } // setupUi

    void retranslateUi(QDialog *SaldoDialog)
    {
        SaldoDialog->setWindowTitle(QApplication::translate("SaldoDialog", "Dialog", Q_NULLPTR));
        labelSaldoOtsikko->setText(QApplication::translate("SaldoDialog", "Tilin saldo", Q_NULLPTR));
        pushButtonLopeta->setText(QApplication::translate("SaldoDialog", "Lopeta", Q_NULLPTR));
        pushButtonPalaa->setText(QApplication::translate("SaldoDialog", "Palaa", Q_NULLPTR));
        labelTilinNimi->setText(QApplication::translate("SaldoDialog", "Tilin nimi", Q_NULLPTR));
        labelSaldo->setText(QApplication::translate("SaldoDialog", "Saldo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SaldoDialog: public Ui_SaldoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALDODIALOG_H

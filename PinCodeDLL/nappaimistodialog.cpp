#include "nappaimistodialog.h"
#include "ui_nappaimistodialog.h"

NappaimistoDialog::NappaimistoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NappaimistoDialog)
{
    ui->setupUi(this);
}

QString NappaimistoDialog::palautaArvoja()
{
    qDebug()<< salasana;
    emit PINSyotetty();
    return salasana;
}

void NappaimistoDialog::on_pushButton_del_clicked()
{
    emit PIN();
    this->close();
    //palautaArvoja();
}

void AddAsterisk(QLineEdit * lineEdit)
{
    QString text = lineEdit->text();
    lineEdit->insert("*");
}

void NappaimistoDialog::on_pushButton_1_clicked()
{
    salasana += "1";
    AddAsterisk(ui->lineEdit);
}

void NappaimistoDialog::on_pushButton_2_clicked()
{
    salasana += "2";
    AddAsterisk(ui->lineEdit);
}

void NappaimistoDialog::on_pushButton_3_clicked()
{
    salasana += "3";
    AddAsterisk(ui->lineEdit);
}

void NappaimistoDialog::on_pushButton_4_clicked()
{
    salasana += "4";
    AddAsterisk(ui->lineEdit);
}

void NappaimistoDialog::on_pushButton_5_clicked()
{
    salasana += "5";
    AddAsterisk(ui->lineEdit);
}

void NappaimistoDialog::on_pushButton_6_clicked()
{
    salasana += "6";
    AddAsterisk(ui->lineEdit);
}

void NappaimistoDialog::on_pushButton_7_clicked()
{
    salasana += "7";
    AddAsterisk(ui->lineEdit);
}

void NappaimistoDialog::on_pushButton_8_clicked()
{
    salasana += "8";
    AddAsterisk(ui->lineEdit);
}

void NappaimistoDialog::on_pushButton_9_clicked()
{
    salasana += "9";
    AddAsterisk(ui->lineEdit);
}

void NappaimistoDialog::on_pushButton_0_clicked()
{
    salasana += "0";
    AddAsterisk(ui->lineEdit);
}

void NappaimistoDialog::on_pushButton_ok_clicked()
{
    salasana = "";
    ui->lineEdit->setText("");
    emit cancel();
}

NappaimistoDialog::~NappaimistoDialog()
{
    delete ui;
}

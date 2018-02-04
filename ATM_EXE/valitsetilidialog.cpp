#include "valitsetilidialog.h"
#include "ui_valitsetilidialog.h"

ValitseTiliDialog::ValitseTiliDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ValitseTiliDialog)
{
    ui->setupUi(this);
}

ValitseTiliDialog::~ValitseTiliDialog()
{
    delete ui;
}

#ifndef NAPPAIMISTODIALOG_H
#define NAPPAIMISTODIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class NappaimistoDialog;
}

class NappaimistoDialog : public QDialog
{
    Q_OBJECT

signals:
    void cancel();
    //(QString salasana);
    void PIN();
    void PINSyotetty();


private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_del_clicked();
    void on_pushButton_ok_clicked();


public:
    explicit NappaimistoDialog(QWidget *parent = 0);
    ~NappaimistoDialog();
    NappaimistoDialog *olioPalauta;
    QString palautaArvoja();

private:
    Ui::NappaimistoDialog *ui;
    QString salasana;
    QString palautaArvo;

};

#endif // NAPPAIMISTODIALOG_H

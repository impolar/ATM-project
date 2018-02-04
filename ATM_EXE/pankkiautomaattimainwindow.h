#ifndef PANKKIAUTOMAATTIMAINWINDOW_H
#define PANKKIAUTOMAATTIMAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QStackedWidget>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QTimer>
#include "C:\Users\Henkka\Documents\Projekti2\pankkiautomaattiEXE\tietokantaDLL\tietokantadll.h"
#include "C:\Users\Henkka\Documents\Projekti2\pankkiautomaattiEXE\rfidDLL\rfiddll.h"
#include "C:\Users\Henkka\Documents\Projekti2\pankkiautomaattiEXE\PinCodeDLL\pincodedll.h"

namespace Ui {
class PankkiautomaattiMainWindow;
}

class PankkiautomaattiMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PankkiautomaattiMainWindow(QWidget *parent = 0);
    ~PankkiautomaattiMainWindow();
    void tarkistaPin();

private slots:

    void pinKysely();
    void kortinLuku();
    void ulosKirjautuminen();
    void vaaraPin();
    void haeSaldo();
    void timer();
    void haeTapahtumat();
    void nosto();
    void valitseToiminto();
    void nostoSummanValinta();
    void muuSumma();


    void on_pushButtonSaldo_clicked();

    void on_pushButtonNosto_clicked();

    void on_pushButton20e_clicked();

    void on_pushButton40e_clicked();

    void on_pushButton60e_clicked();

    void on_pushButtonTapahtumat_clicked();

    void on_pushButtonSaldoPalaa_clicked();

    void on_pushButtonNostoPalaa_clicked();

    void on_pushButtonTapahtumatPalaa_clicked();

    void on_pushButtonHyvaksy_clicked();

    void on_pushButtonMuuSumma_clicked();

    void on_pushButtonLopeta_2_clicked();

    void on_pushButtonLopeta_clicked();

    void on_pushButtonLopeta_3_clicked();

signals:
    void laskuriStart();
    void pinOnSyotetty();

private:
    Ui::PankkiautomaattiMainWindow *ui;
    QTimer *olioTimer;
    TietokantaDll *olioTietokantaDLL;
    QTableWidgetItem *olioTapahtuma;
    RfidDLL *olioRfidDLL;
    PinCodeDLL *olioPinCodeDLL;

    double nostettavaSumma = 0;

    int pinYritysKerrat = 3;

    bool korttiPaikallaan = true;
    bool pinOk=false;
    bool nostoOk = false;
    bool rahaaTililla;

    QString pin;//="1234";
    QString kortinNumero;// = "0A0079C7BF";
    QString saldo;
    QString tilinumero;

    QSqlTableModel tapahtumat;
};

#endif // PANKKIAUTOMAATTIMAINWINDOW_H

#include "pankkiautomaattimainwindow.h"
#include "ui_pankkiautomaattimainwindow.h"

PankkiautomaattiMainWindow::PankkiautomaattiMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PankkiautomaattiMainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    olioRfidDLL = new RfidDLL;
    olioRfidDLL->palautaPankkikortinNumeroKomponentti();
    connect(olioRfidDLL, SIGNAL(signaaliRpSignaali()), this, SLOT(kortinLuku()));
    connect(this, SIGNAL(laskuriStart()), this, SLOT(timer()));

}

PankkiautomaattiMainWindow::~PankkiautomaattiMainWindow()
{
    delete olioRfidDLL;
    olioRfidDLL = NULL;
    delete ui;
}


void PankkiautomaattiMainWindow::kortinLuku()
{
    //kun kortti on paikallaan signaalilla tähän
    kortinNumero = olioRfidDLL->tulostus();
    pinKysely();

}

void PankkiautomaattiMainWindow::timer()
{
    olioTimer = new QTimer(this);
    if(pinOk&&!nostoOk)
    {
        this->connect(olioTimer, SIGNAL(timeout()), this, SLOT(valitseToiminto()));
    }
    else if(!pinOk)
    {
        this->connect(olioTimer, SIGNAL(timeout()), this, SLOT(vaaraPin()));
    }
    else if(pinOk&&nostoOk)
    {
        this->connect(olioTimer, SIGNAL(timeout()), this, SLOT(ulosKirjautuminen()));
    }

    olioTimer->setSingleShot(true);
    olioTimer->start(3000);

}

void PankkiautomaattiMainWindow::vaaraPin()
{
    delete olioTimer;
    olioTimer = NULL;
    pinKysely();

}

void PankkiautomaattiMainWindow::pinKysely()
{
    ui->stackedWidget->setCurrentIndex(0);

    olioPinCodeDLL = new PinCodeDLL();

    pin= olioPinCodeDLL->rajapintaPinCodeDLL();

    delete olioPinCodeDLL;
    olioPinCodeDLL = NULL;
    tarkistaPin();

}

void PankkiautomaattiMainWindow::tarkistaPin()
{
    olioTietokantaDLL = new TietokantaDll;
    olioTietokantaDLL->avaaTietokanta();

    pinOk = olioTietokantaDLL->rajapintaPinKysely(kortinNumero, pin);

    if(pinOk)
    {
        ui->stackedWidget->setCurrentIndex(5);
        emit laskuriStart();
    }
    else
    {
        delete olioTietokantaDLL;
        olioTietokantaDLL = NULL;

        pinYritysKerrat -= 1;
        ui->stackedWidget->setCurrentIndex(6);
        ui->labelPinCount->setNum(pinYritysKerrat);

        if(pinYritysKerrat == 0)
        {
            ulosKirjautuminen();
        }else
        {
            emit laskuriStart();
        }
    }
}

void PankkiautomaattiMainWindow::haeSaldo()
{    
    saldo = olioTietokantaDLL->rajapintaSaldoKysely(kortinNumero);
    tilinumero = olioTietokantaDLL->rajapintaTiliKysely(kortinNumero);
    ui->labelSaldo->setText(saldo);
    ui->labelTilinNumero->setText(tilinumero);

}

void PankkiautomaattiMainWindow::haeTapahtumat()
{
    tilinumero = olioTietokantaDLL->rajapintaTiliKysely(kortinNumero);
    olioTietokantaDLL->rajapintaTapahtumaKysely(&tapahtumat, tilinumero);
    ui->tableViewTapahtumat->setModel(&tapahtumat);

}

void PankkiautomaattiMainWindow::ulosKirjautuminen()
{

    QMessageBox msg;

    msg.setText("Poista kortti");
    msg.exec();

    ui->stackedWidget->setCurrentIndex(0);

    //Tyhjentää tiedot kun kirjautuu ulos
    nostoOk = false;
    pinOk=false;

    pinYritysKerrat = 3;
    nostettavaSumma = 0;
    saldo.clear();
    kortinNumero.clear();
    tilinumero.clear();
    pin.clear();

    delete olioTietokantaDLL;
    olioTietokantaDLL = NULL;

}

void PankkiautomaattiMainWindow::nosto()
{

    nostoOk=olioTietokantaDLL->rajapintaRahanNosto(tilinumero, nostettavaSumma);
    if(nostoOk)
    {
        saldo = olioTietokantaDLL->rajapintaSaldoKysely(kortinNumero);
        ui->labelNostoOkSummaNum->setNum(nostettavaSumma);
        ui->labelNostoOkTilinum->setText(tilinumero);
        ui->labelNostoOkKateSum->setText(saldo);
        ui->stackedWidget->setCurrentIndex(7);
        emit laskuriStart();
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(8);
        emit laskuriStart();
    }
}

void PankkiautomaattiMainWindow::valitseToiminto()
{
    delete olioTimer;
    olioTimer = NULL;
    ui->stackedWidget->setCurrentIndex(1);

}

void PankkiautomaattiMainWindow::nostoSummanValinta()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->labelSumma->setNum(nostettavaSumma);

    if(nostettavaSumma<20)
        ui->pushButtonHyvaksy->setEnabled(false);
}

void PankkiautomaattiMainWindow::muuSumma()
{
    olioPinCodeDLL = new PinCodeDLL();

    QString muuSumma;
    muuSumma = olioPinCodeDLL->rajapintaMuuSummaDialog();
    nostettavaSumma = muuSumma.toDouble();

    delete olioPinCodeDLL;
    olioPinCodeDLL = NULL;
    if(nostettavaSumma>=20)
    {
        ui->pushButtonHyvaksy->setEnabled(true);
    }
    nostoSummanValinta();
}


void PankkiautomaattiMainWindow::on_pushButtonSaldo_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    haeSaldo();
}

void PankkiautomaattiMainWindow::on_pushButtonNosto_clicked()
{  
    nostoSummanValinta();
}

void PankkiautomaattiMainWindow::on_pushButton20e_clicked()
{
    nostettavaSumma = 20;
    ui->labelSumma->setNum(nostettavaSumma);
    ui->pushButtonHyvaksy->setEnabled(true);

}

void PankkiautomaattiMainWindow::on_pushButton40e_clicked()
{
    nostettavaSumma = 40;
    ui->labelSumma->setNum(nostettavaSumma);
    ui->pushButtonHyvaksy->setEnabled(true);

}

void PankkiautomaattiMainWindow::on_pushButton60e_clicked()
{
    nostettavaSumma = 60;
    ui->labelSumma->setNum(nostettavaSumma);
    ui->pushButtonHyvaksy->setEnabled(true);

}

void PankkiautomaattiMainWindow::on_pushButtonTapahtumat_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    haeTapahtumat();
}


void PankkiautomaattiMainWindow::on_pushButtonSaldoPalaa_clicked()
{
    valitseToiminto();
}

void PankkiautomaattiMainWindow::on_pushButtonNostoPalaa_clicked()
{
    nostettavaSumma = 0;
    valitseToiminto();

}

void PankkiautomaattiMainWindow::on_pushButtonTapahtumatPalaa_clicked()
{
    valitseToiminto();
}

void PankkiautomaattiMainWindow::on_pushButtonHyvaksy_clicked()
{
    if(nostettavaSumma != 0)
        nosto();
}

void PankkiautomaattiMainWindow::on_pushButtonMuuSumma_clicked()
{
    muuSumma();
}

void PankkiautomaattiMainWindow::on_pushButtonLopeta_2_clicked()
{
    ulosKirjautuminen();
}

void PankkiautomaattiMainWindow::on_pushButtonLopeta_clicked()
{
    ulosKirjautuminen();
}

void PankkiautomaattiMainWindow::on_pushButtonLopeta_3_clicked()
{
    ulosKirjautuminen();
}

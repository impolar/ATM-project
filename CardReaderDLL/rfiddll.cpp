#include "rfiddll.h"
#include <QDebug>
RfidDLL::RfidDLL()
{
}

void RfidDLL::palautaPankkikortinNumeroKomponentti()
{
    oliomoottoriRfidDLL = new moottoriRfidDLL;
    oliomoottoriRfidDLL->LueKortinNumero();
    connect(oliomoottoriRfidDLL,SIGNAL(luettu()),this,SLOT(rajapintaSignaali()));

}

void RfidDLL::rajapintaSignaali()
{
    emit signaaliRpSignaali();
}

QString RfidDLL::tulostus()
{
    palautettavaArvo = oliomoottoriRfidDLL->serialReceived();
    qDebug()<< palautettavaArvo;

    //ui->label->setText(palautettavaArvo);
    return palautettavaArvo;
}

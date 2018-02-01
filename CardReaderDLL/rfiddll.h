#ifndef RFIDDLL_H
#define RFIDDLL_H
#include <QSerialPort>
#include "moottorirfiddll.h"
#include <QObject>
#include "rfiddll_global.h"


class RFIDDLLSHARED_EXPORT RfidDLL: public QObject
{
    Q_OBJECT
public:
    RfidDLL();
    void RFIDDLLSHARED_EXPORT palautaPankkikortinNumeroKomponentti();
private:

    QString palautettavaArvo;
    moottoriRfidDLL* oliomoottoriRfidDLL;
    QSerialPort *serial;
    QString cardSerialNumber;

signals:
    void RFIDDLLSHARED_EXPORT signaaliRpSignaali();

public slots:
    void RFIDDLLSHARED_EXPORT rajapintaSignaali();
    QString RFIDDLLSHARED_EXPORT tulostus();
};

#endif // RFIDDLL_H

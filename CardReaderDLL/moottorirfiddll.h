#ifndef MOOTTORIRFIDDLL_H
#define MOOTTORIRFIDDLL_H
#include <QObject>
#include <QString>
#include <QSerialPort>


class moottoriRfidDLL:public QObject
{
    Q_OBJECT

public:
    //moottoriRfidDLL();
    void LueKortinNumero();
    QString kortti();
private:
    int KortinNumero;
    QSerialPort *serial;
    int numero;
    QString cardSerialNumber;
    QString str;
signals:
    void strCliked(QString);
    void luettu();
public slots:
    void send();
    QString serialReceived();

};

#endif // MOOTTORIRFIDDLL_H

#include "moottorirfiddll.h"
#include <QDebug>
//#include <QSerialPort>

/*moottoriRfidDLL::moottoriRfidDLL()
{

}*/

void moottoriRfidDLL::LueKortinNumero()
{
    serial = new QSerialPort(this);
    serial->setPortName("com3");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    // serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->setFlowControl(QSerialPort::HardwareControl);

    if (serial->open(QIODevice::ReadWrite))
    {
        qDebug() << serial->portName();
        //connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));
    }else {
        qDebug() << "Portin avaaminen ei onnistunut!";

    }
    //return cardSerialNumber;
    connect(serial,SIGNAL(readyRead()),this,SLOT(send()));
}

QString moottoriRfidDLL::kortti()
{
    return cardSerialNumber;
}

void moottoriRfidDLL::send()
{
    emit luettu();
}

QString moottoriRfidDLL::serialReceived()
{

    char data[20];
    int bytesread;
    bytesread= serial->read(data,20);
    data[bytesread] = '\0';
    if (bytesread>10)
    {
        for (int i=0;i<=9;i++)
        {

            cardSerialNumber = data;


        }

        cardSerialNumber.remove(0, 3);
        cardSerialNumber.chop(3);

        qDebug() << "Kortin numero: " << cardSerialNumber << endl;

        //emit luettu();
        //str = cardSerialNumber;
        //connect(serial,SIGNAL(readyRead()), SLOT(send()));
    }
    else
        qDebug()<<"Virhe korttia luettaessa!";
return cardSerialNumber;

}

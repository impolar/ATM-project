#ifndef PINCODEDLL_H
#define PINCODEDLL_H

#include "pincodedll_global.h"
#include "nappaimistodialog.h"
#include <QObject>

class PINCODEDLLSHARED_EXPORT PinCodeDLL:public QObject
{
Q_OBJECT


public:
    PinCodeDLL();
    void PINCODEDLLSHARED_EXPORT rajapintaPinCodeDLL();
    //QString PINCODEDLLSHARED_EXPORT rajapintaPIN();
   // ~PinCodeDLL();

public slots:
    QString PINCODEDLLSHARED_EXPORT rajapintaPIN();
    void PINCODEDLLSHARED_EXPORT PINsyotto();
signals:
    void PINCODEDLLSHARED_EXPORT PinSyotetty();

private:
    NappaimistoDialog *olioNappaimistoDialog;
    QString PIN;
};

#endif // PINCODEDLL_H

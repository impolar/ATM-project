#include "pincodedll.h"


PinCodeDLL::PinCodeDLL()
{

}

void PinCodeDLL::rajapintaPinCodeDLL()
{

    olioNappaimistoDialog = new NappaimistoDialog;
    olioNappaimistoDialog->show();
    connect(olioNappaimistoDialog, SIGNAL(PIN()), this, SLOT(PINsyotto()));
    //QString PIN = olioNappaimistoDialog->palautaArvoja();
    //return PIN;
}

QString PinCodeDLL::rajapintaPIN()
{
   olioNappaimistoDialog->palautaArvoja();
   return PIN;
  // connect(olioNappaimistoDialog,SIGNAL(PINSyotetty()),this,SLOT(PINsyotto()));
}

void PinCodeDLL::PINsyotto()
{
    emit PinSyotetty();
    rajapintaPIN();
}

/*PinCodeDLL::~PinCodeDLL()
{

}*/

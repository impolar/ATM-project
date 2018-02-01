#include "tietokantadll.h"

//TietokantaDll::TietokantaDll()
//{
//}

bool TietokantaDll::rajapintaPinKysely(QString kortinNumero, QString pin)
{
    odotaYhteys();
    olioTietokantaMoottori = new tietokantaMoottori;
    pinTila = olioTietokantaMoottori->varmistaPin(kortinNumero, pin);

    delete olioTietokantaMoottori;

    if(pinTila)
        return true;
    else
        return false;
    db.close();
}

QString TietokantaDll::rajapintaSaldoKysely(QString kortinNumero)
{
    odotaYhteys();
    olioTietokantaMoottori = new tietokantaMoottori;

    saldo = olioTietokantaMoottori->haeSaldo(kortinNumero);

    delete olioTietokantaMoottori;
    return saldo;
    db.close();
}

QString TietokantaDll::rajapintaTiliKysely(QString kortinNumero)
{
    odotaYhteys();
    olioTietokantaMoottori = new tietokantaMoottori;

    tilinumero = olioTietokantaMoottori->haeTilinumero(kortinNumero);

    delete olioTietokantaMoottori;
    return tilinumero;
    db.close();
}

void TietokantaDll::rajapintaTapahtumaKysely(QSqlQueryModel *model, QString tilinumero)
{
    odotaYhteys();
    olioTietokantaMoottori = new tietokantaMoottori;

    olioTietokantaMoottori->haeTapahtumat(model, tilinumero);

    delete olioTietokantaMoottori;
    db.close();
}

bool TietokantaDll::rajapintaRahanNosto(QString tilinumero, double nosto)
{
    odotaYhteys();
    olioTietokantaMoottori = new tietokantaMoottori;

    rahanNosto = olioTietokantaMoottori->nostaRahaa(tilinumero, nosto);

    if(rahanNosto)
        return true;
    else
        return false;
    delete olioTietokantaMoottori;
    db.close();
}

void TietokantaDll::avaaTietokanta()
{
    db = QSqlDatabase::addDatabase(dbTyyppi);
    db.setHostName(host);
    db.setDatabaseName(dbNimi);
    db.setUserName(kayttaja);
    db.setPassword(salasana);
}

void TietokantaDll::odotaYhteys()
{
    db.open();
    while(!db.isOpen())
    {
    }
}

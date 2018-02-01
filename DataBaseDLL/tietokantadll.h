// v0.05 Moottoriluokan pinvarmistus muutettu query-mallista model-malliin
// ja tapahtumakysely muokattiin tableviewistä void-malliin
// v0.06 rahan nosto lisätty
// v0.07 Kaikki muuttujien esittely siirretty header tiedostoihin (model->malli ja query->tiedustelu)
// v0.08 rahan nosto lisää nyt tapahtuman tietokantaan

#ifndef TIETOKANTADLL_H
#define TIETOKANTADLL_H

#include "tietokantamoottori.h"
#include "tietokantadll_global.h"
#include <QtSql>
#include <QSqlTableModel>
#include <QDebug>
#include <QString>
#include <QStringList>

class TietokantaDll
{

public:
    //TietokantaDll();
    bool TIETOKANTADLLSHARED_EXPORT rajapintaPinKysely(QString kortinNumero, QString pin);
    QString TIETOKANTADLLSHARED_EXPORT rajapintaSaldoKysely(QString kortinNumero);
    QString TIETOKANTADLLSHARED_EXPORT rajapintaTiliKysely(QString kortinNumero);
    void TIETOKANTADLLSHARED_EXPORT rajapintaTapahtumaKysely(QSqlQueryModel *model, QString tilinumero);
    bool TIETOKANTADLLSHARED_EXPORT rajapintaRahanNosto(QString tilinumero, double nosto);
    void TIETOKANTADLLSHARED_EXPORT avaaTietokanta();
    void odotaYhteys();

private:
    tietokantaMoottori *olioTietokantaMoottori;
    bool pinTila, rahanNosto;
    QString saldo, tilinumero;
    QSqlDatabase db;
    QString dbTyyppi = "QMYSQL";
    QString host = "mysli.oamk.fi";
    QString dbNimi = "opisk_t6kaat01";
    QString kayttaja = "t6kaat01";
    QString salasana = "fEoztLW2PzUXWoRW";
};

#endif // TIETOKANTADLL_H

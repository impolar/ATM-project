#include "tietokantamoottori.h"

tietokantaMoottori::tietokantaMoottori()
{

}

bool tietokantaMoottori::varmistaPin(QString kortinNumero, QString pin)
{
    malli = new QSqlTableModel;
    malli->setTable("korttiTable");
    malli->setFilter(QString("idkortti = '%1'").arg(kortinNumero));
    malli->select();

    oikeaPin = malli->data(malli->index(0,3)).toString();
    if(pin == oikeaPin)
        return true;
    else
        return false;
    delete malli;
}

QString tietokantaMoottori::haeSaldo(QString kortinNumero)
{
    tiedustelu.prepare("SELECT korttiTable.tilinumero,saldo FROM korttiTable LEFT JOIN tiliTable ON korttiTable.tilinumero=tiliTable.tilinumero WHERE idkortti = :kortinNumero");
    tiedustelu.bindValue(":kortinNumero", kortinNumero);
    tiedustelu.exec();

    while(tiedustelu.next())
    {
        saldo = tiedustelu.value(1).toString();
    }
    return saldo;
}

QString tietokantaMoottori::haeTilinumero(QString kortinNumero)
{
    tiedustelu.prepare("SELECT korttiTable.tilinumero,saldo FROM korttiTable LEFT JOIN tiliTable ON korttiTable.tilinumero=tiliTable.tilinumero WHERE idkortti = :kortinNumero");
    tiedustelu.bindValue(":kortinNumero", kortinNumero);
    tiedustelu.exec();

    while(tiedustelu.next())
    {
        tilinumero = tiedustelu.value(0).toString();
    }
    return tilinumero;
}

void tietokantaMoottori::haeTapahtumat(QSqlQueryModel *model, QString tilinumero)
{
    model->setQuery(QString("SELECT tilinumeroKaksi AS 'Tilinumero',pvm AS 'Pvm',tapahtuma AS 'Tapahtuma',summa AS 'Summa' FROM tapahtumatTable WHERE tilinumeroKaksi = '%1' ORDER BY pvm DESC").arg(tilinumero));
}

bool tietokantaMoottori::nostaRahaa(QString tilinumero, double nosto)
{
    tiedustelu.prepare("SELECT saldo FROM tiliTable WHERE tilinumero = :tilinumero");
    tiedustelu.bindValue(":tilinumero", tilinumero);
    tiedustelu.exec();

    while(tiedustelu.next())
    {
        nykyinenSaldo = tiedustelu.value(0).toDouble();
    }
    if(nosto > nykyinenSaldo)
        return false;
    else
    {
        tiedustelu.prepare("UPDATE tiliTable SET saldo = :nykyinenSaldo - :nosto WHERE tilinumero = :tilinumero");
        tiedustelu.bindValue(":nykyinenSaldo", nykyinenSaldo);
        tiedustelu.bindValue(":nosto", nosto);
        tiedustelu.bindValue(":tilinumero", tilinumero);
        tiedustelu.exec();
        return true;
    }
}


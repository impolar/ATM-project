#ifndef TIETOKANTAMOOTTORI_H
#define TIETOKANTAMOOTTORI_H

#include <QString>
#include <QMainWindow>
#include <QtSql>
#include <QSqlTableModel>
#include <QDebug>
#include <QString>
#include <QSqlTableModel>

class tietokantaMoottori
{
public:
    tietokantaMoottori();
    bool varmistaPin(QString kortinNumero, QString pin);
    QString haeSaldo(QString kortinNumero);
    QString haeTilinumero(QString kortinNumero);
    void haeTapahtumat(QSqlQueryModel *model, QString tilinumero);
    bool nostaRahaa(QString tilinumero, double nosto);

private:
    QString saldo, tilinumero, oikeaPin;
    QSqlQuery tiedustelu;
    double nykyinenSaldo;
    QSqlTableModel *malli;

};

#endif // TIETOKANTAMOOTTORI_H

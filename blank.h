#ifndef BLANK_H
#define BLANK_H

#include <QString>

struct FIO
{
    QString name, surname, otc;
};

class Blank
{
public:
    Blank();
    Blank (QString d, QString f, QString i, QString o, QString num, QString em);
    FIO fio;
    QString dish, number, email;
    int pop;

};

#endif // BLANK_H

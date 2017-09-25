#include "blank.h"

Blank::Blank()
{
    pop=0;
}

Blank::Blank(QString d, QString f, QString i, QString o, QString num, QString em)
{
    dish = d;
    fio.surname = f;
    fio.name = i;
    fio.otc = o;
    number = num;
    email = em;
    pop=0;
}

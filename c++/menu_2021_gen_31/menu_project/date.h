#ifndef DATE_H
#define DATE_H
#include <QString>
#include <QDate>
#include <QDebug>


class Date
{
public:
    int day;
    QString month;
    int year;
    QString dayOfWeek;

public:
    Date();
    ~Date();
    void conversion(QDate &q);
};

#endif // DATE_H

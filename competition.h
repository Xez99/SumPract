#ifndef COMPETITION_H
#define COMPETITION_H

#include "QDate"
#include "QTime"

class Competition
{
private:
    QString name;
    QDate date;
    QTime time;
public:
    Competition();

    void setName(QString name);
    void setDate(QDate date); 
    void setTime(QTime time);

    QString getName() const;
    QDate getDate() const;
    QTime getTime() const;
};

#endif // COMPETITION_H

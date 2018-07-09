#include "competition.h"

Competition::Competition()
{

}

void Competition::setDate(QDate date)
{
    this->date = date;
}

void Competition::setName(QString name)
{
    this->name = name;
}

void Competition::setTime(QTime time)
{
    this->time = time;
}

QDate Competition::getDate() const
{
    return date;
}

QString Competition::getName() const
{
    return name;
}

QTime Competition::getTime() const
{
    return time;
}

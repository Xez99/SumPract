#ifndef TEAM_H
#define TEAM_H

#include "QString"
#include "person.h"
#include "QList"

class Person;
class Team
{
private:
    QString name;
public:
    QList<Person> Racers;
public:
    Team();
    void setName(QString name);
    void addRacer(Person *person);
    void removeRacer(int index);
    QString getName() const;
    QList<Person> getRacers();
    unsigned getTotalPoints() const;
};

#endif // TEAM_H

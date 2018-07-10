#ifndef TEAM_H
#define TEAM_H

#include "person.h"

class Person;
class Team
{

private:
    QString name;

public:
    Team();
    void setName(QString name);

    QList<Person> Racers;

    QString getName() const;

    unsigned getTotalPoints() const;

    void addRacer(Person *person);
    void removeRacer(int index);

};

#endif // TEAM_H

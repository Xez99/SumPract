#ifndef TEAM_H
#define TEAM_H

#include "QString"
#include "person.h"
#include "list"

class Team
{
private:
    QString name;
    std::list<Person> Racers;
public:
    Team();
    void setName(QString name);
    void addRacer(Person person);
    QString getName();
    std::list<Person> getRacers();
    unsigned getTotalPoints();
};

#endif // TEAM_H

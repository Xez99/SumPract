#ifndef PERSON_H
#define PERSON_H

#include "QString"
#include "QDate"
#include "team.h"

class Team;
class Person
{
private:
    Team *team;
    QString name;
    QString secondName;
    QString fatherName;
    QDate birthDate;
    unsigned points;

public:
    Person();
    Person(Team *team);

    void setTeam(Team *team);
    void setName(QString name);
    void setSecondName(QString secondName);
    void setFatherName(QString fatherName);
    void setBirthDate(QDate birthDate);
    void setPoints(unsigned points);
    void addPoints(unsigned points);

    Team* getTeam() const;
    QString getName() const;
    QString getSecondName() const;
    QString getFarherName() const;
    QString getFullName() const;
    QDate getBirthDate() const;
    unsigned getPoints() const;
};

#endif // PERSON_H

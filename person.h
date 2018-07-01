#ifndef PERSON_H
#define PERSON_H

#include "QString"
#include "QDate"

class Person
{
private:
    QString team;
    QString name;
    QString secondName;
    QString fatherName;
    QDate birthDate;
    unsigned points;
public:
    Person();

    void setTeam(QString team);
    void setName(QString name);
    void setSecondName(QString secondName);
    void setFatherName(QString fatherName);
    void setBirthDate(QDate birthDate);
    void setPoints(unsigned points);
    void addPoints(unsigned points);

    QString getTeam();
    QString getName();
    QString getSecondName();
    QString getFarherName();
    QDate getBirthDate();
    unsigned getPoints();
};

#endif // PERSON_H

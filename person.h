#ifndef PERSON_H
#define PERSON_H

#include "QString"

class Person
{
private:
    QString name;
    QString secondName;
    QString fatherName;
    unsigned short age;
    unsigned points;
public:
    Person();
};

#endif // PERSON_H

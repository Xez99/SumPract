#ifndef TRACK_H
#define TRACK_H

#include "person.h"


class Track
{
private:
    QString name;
    QString description;
    Person *goldP;
    Person *silvP;
    Person *bronP;

public:
    Track();

    void setName(QString name);
    void setDescription(QString description);
    void setGoldP(Person *goldP);
    void setSilvP(Person *silvP);
    void setBronP(Person *bronP);

    QString getName() const;
    QString getDescription() const;
    Person* getGoldP() const;
    Person* getSilvP() const;
    Person* getBronP() const;

};
#endif // TRACK_H

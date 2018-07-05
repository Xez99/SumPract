#ifndef TRACK_H
#define TRACK_H

#include "QString"
#include "QListWidgetItem"
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
    void setGoldP(Person &goldP);
    void setSilvP(QString &silvP);
    void setBronP(QString &bronP);

    QString getName() const;
    QString getDescription() const;
    Person *getGoldP();
    Person *getSilvP();
    Person *getBronP();
};
#endif // TRACK_H

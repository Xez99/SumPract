#include "track.h"

Track::Track()
{
    goldP = nullptr;
    silvP = nullptr;
    bronP = nullptr;
}

void Track::setName(QString name)
{
    this->name = name;
}

void Track::setDescription(QString description)
{
    this->description = description;
}

void Track::setGoldP(Person *goldP)
{
    this->goldP = goldP;
}

void Track::setSilvP(Person *silvP)
{
    this->silvP = silvP;
}

void Track::setBronP(Person *bronP)
{
    this->bronP = bronP;
}

QString Track::getName() const
{
    return name;
}

QString Track::getDescription() const
{
    return description;
}

Person *Track::getGoldP() const
{
    return goldP;
}

Person *Track::getSilvP() const
{
    return silvP;
}

Person *Track::getBronP() const
{
    return bronP;
}

/*
Track Track::operator = (const Track& from)
{
    if(this != &from){
        this->setName(from.getName());
        this->setDescription(from.getDescription());
        this->setGoldP(from.getGoldP());
        this->setSilvP(from.getSilvP());
        this->setBronP(from.getBronP());
    }
    return *this;
}
*/

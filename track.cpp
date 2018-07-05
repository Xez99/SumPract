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

void Track::setGoldP(Person &goldP)
{

}

void Track::setSilvP(QString &silvP)
{

}

void Track::setBronP(QString &bronP)
{

}

QString Track::getName() const
{
    return name;
}

QString Track::getDescription() const
{
    return description;
}

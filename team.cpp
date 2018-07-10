#include "team.h"

Team::Team()
{

}

void Team::setName(QString name){
    this->name = name;
}

void Team::addRacer(Person *person){
    person->setTeam(this);
    this->Racers << *person;
}

void Team::removeRacer(int index)
{
    Racers.removeAt(index);
}

QString Team::getName() const{
    return name;
}

unsigned Team::getTotalPoints() const{

    unsigned TP = 0;

    for(auto it = Racers.begin(); it != Racers.end(); it++){
        TP+= it->getPoints();
    }
    return TP;
}

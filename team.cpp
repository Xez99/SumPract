#include "team.h"

Team::Team()
{

}

void Team::setName(QString name){
    this->name = name;
}

void Team::addRacer(Person person){
    this->Racers.push_back(person);
}

QString Team::getName(){
    return name;
}
std::list<Person> Team::getRacers(){
    return this->Racers;
}
unsigned Team::getTotalPoints(){

    unsigned TP = 0;
    /*
    //for_each(Racers.begin(), Racers.end(), TP += )
    for(auto it = Racers.begin(); it != Racers.end(); it++){
        TP+= it->getPoints();
    }*/
    for(auto it = Racers.begin(); it != Racers.end(); it++){
        TP+= it->getPoints();}
    return TP;
}

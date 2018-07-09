#include "person.h"
#include "team.h"

Person::Person(){

}

Person::Person(Team *team){
    this->team = team;
}

void Person::setTeam(Team *team){
    this->team = team;
}

void Person::setName(QString name){
    this->name = name;
}

void Person::setSecondName(QString secondName){
    this->secondName = secondName;
}

void Person::setFatherName(QString fatherName){
    this->fatherName = fatherName;
}
void Person::setBirthDate(QDate birthDate){
    this->birthDate = birthDate;
}

void Person::setPoints(unsigned points){
    this->points = points;
}

void Person::addPoints(unsigned points){
    this->points+=points;
}

Team* Person::getTeam() const{
    return team;
}

QString Person::getName() const{
    return name;
}

QString Person::getSecondName() const{
    return secondName;
}

QString Person::getFarherName() const{
    return fatherName;
}

QString Person::getFullName() const
{
    return secondName + " " + name + " " + fatherName;
}

QDate Person::getBirthDate() const{
    return birthDate;
}

unsigned Person::getPoints() const{
    return points;
}


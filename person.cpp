#include "person.h"

Person::Person(){

}

void Person::setTeam(QString team){
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

QString Person::getTeam(){
    return team;
}

QString Person::getName(){
    return name;
}

QString Person::getSecondName(){
    return secondName;
}

QString Person::getFarherName(){
    return fatherName;
}

QDate Person::getBirthDate(){
    return birthDate;
}

unsigned Person::getPoints(){
    return points;
}

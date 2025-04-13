#include "passenger.h"

Passenger::Passenger() {}

QString Passenger::getfirstName() const{
    return firstName;
}

QString Passenger::getLastName() const{
    return lastName;
}

QString Passenger::getEmail() const{
    return email;
}

QString Passenger::getPhoneNumber() const{
    return phoneNumber;
}

QDate Passenger::getBirthDate() const{
    return birthDate;
}

int Passenger::getPassengerID() const{
    return ID;
}

void Passenger::setFirstName(QString firstName){
    this->firstName = firstName;
}

void Passenger::setLastName(QString lastName){
    this->lastName = lastName;
}

void Passenger::setEmail(QString email){
    this->email = email;
}

void Passenger::setPhoneNumber(QString phoneNumber){
    this->phoneNumber = phoneNumber;
}

void Passenger::setBirthDate(QDate birthDate){
    this->birthDate = birthDate;
}



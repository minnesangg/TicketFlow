/*
 * TicketFlow
 * Copyright (C) 2025 minnesang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


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

void Passenger::setPassengerID(int ID){
    this->ID = ID;
}


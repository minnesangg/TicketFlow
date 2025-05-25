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

#include "headers/ticket.h"

Ticket::Ticket() {}

void Ticket::setPassengerID(int passengerID){
    this->passengerID = passengerID;
}

void Ticket::setPlaneID(int planeID){
    this->planeID = planeID;
}

void Ticket::setPrice(float price){
    this->price = price;
}

void Ticket::setSeatNumber(QString seatNumber){
    this->seatNumber = seatNumber;
}

void Ticket::setDepartureCity(QString departureCity){
    this->departureCity = departureCity;
}

void Ticket::setArrivalCity(QString arrivalCity){
    this->arrivalCity = arrivalCity;
}

void Ticket::setDepartureTime(QDateTime departureTime){
    this->departureTime = departureTime;
}

void Ticket::setArrivalTime(QDateTime arrivalTime){
    this->arrivalTime = arrivalTime;
}

int Ticket::getPassengerID() const {
    return passengerID;
}

int Ticket::getPlaneID() const {
    return planeID;
}

float Ticket::getPrice() const {
    return price;
}

QString Ticket::getSeatNumber() const {
    return seatNumber;
}

QString Ticket::getDepartureCity() const {
    return departureCity;
}

QString Ticket::getArrivalCity() const {
    return arrivalCity;
}

QDateTime Ticket::getDepartureTime() const {
    return departureTime;
}

QDateTime Ticket::getArrivalTime() const {
    return arrivalTime;
}

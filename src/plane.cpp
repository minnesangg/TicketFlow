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

#include "headers/plane.h"

Plane::Plane() {}

void Plane::setModel(QString model){
    this->model = model;
}

void Plane::setAirline(QString airline){
    this->airline = airline;
}

void Plane::setCapacity(int capacity){
    this->capacity = capacity;
}

void Plane::setPlaneID(int ID){
    this->ID = ID;
}

QString Plane::getModel() const{
    return model;
}

QString Plane::getAirline() const{
    return airline;
}

int Plane::getCapacity() const{
    return capacity;
}

int Plane::getPlaneID() const{
    return ID;
}

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

#include "database.h"

Database::Database() {
    connectToDB();
}

Database::~Database(){
    if (db.isOpen()) {
        db.close();
    }
}

bool Database::connectToDB() {
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("postgres");

    if (!db.open()) {
        qDebug() << "Error: " << db.lastError().text();
        return false;
    }

    qDebug() << "Database connected successfully!";
    return true;
}

void Database::selectData() {
    QSqlQuery query("SELECT * FROM Passengers");

    while (query.next()) {
        int id = query.value(0).toInt();
        QString firstName = query.value(1).toString();
        QString lastName = query.value(2).toString();

        qDebug() << id << ": " << firstName << " " << lastName;
    }
}

bool Database::loadComboBoxData(QComboBox* comboBox, const QString& table, const QString& column){
    QSqlQuery query;
    query.prepare("SELECT id, " + column + " FROM " + table);

    if (!query.exec()) {
        qDebug() << "Error loading data for " << table << ":" << query.lastError().text();
        return false;
    }

    comboBox->clear();
    while (query.next()) {
        int id = query.value(0).toInt();
        QString value = query.value(1).toString();
        comboBox->addItem(value, id);
    }

    return true;
}

int Database::getPassengerIdFromComboBoxes(QComboBox* nameComboBox, QComboBox* lastNameComboBox) {
    QString firstName = nameComboBox->currentText();
    QString lastName = lastNameComboBox->currentText();

    if (firstName.isEmpty() || lastName.isEmpty()) {
        qDebug() << "Please select both name and last name!";
        return -1;
    }

    QSqlQuery query;
    query.prepare("SELECT id FROM Passengers WHERE first_name = :firstName AND last_name = :lastName");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    } else {
        qDebug() << "Passenger not found!";
        return -1;
    }
}

bool Database::addTicketToDatabase(const Ticket& ticket) {
    QSqlQuery query;
    query.prepare("INSERT INTO Tickets (passenger_id, plane_id, departure_city, arrival_city, departure_time, arrival_time, seat_number, price) "
                  "VALUES (:passenger_id, :plane_id, :departure_city, :arrival_city, :departure_time, :arrival_time, :seat_number, :price)");

    bindQueryForTickets(query, ticket);
    return query.exec();
}

bool Database::deleteTicketFromDatabase(const Ticket& ticket){
    QSqlQuery query;
    query.prepare("DELETE FROM Tickets "
                  "WHERE passenger_id = :passenger_id "
                  "AND plane_id = :plane_id "
                  "AND departure_city = :departure_city "
                  "AND arrival_city = :arrival_city "
                  "AND departure_time = :departure_time "
                  "AND arrival_time = :arrival_time "
                  "AND seat_number = :seat_number "
                  "AND price = :price");

    bindQueryForTickets(query, ticket);
    return query.exec();
}

void Database::bindQueryForTickets(QSqlQuery& query, const Ticket& ticket){
    query.bindValue(":passenger_id", ticket.getPassengerID());
    query.bindValue(":plane_id", ticket.getPlaneID());
    query.bindValue(":departure_city", ticket.getDepartureCity());
    query.bindValue(":arrival_city", ticket.getArrivalCity());
    query.bindValue(":departure_time", ticket.getDepartureTime().toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":arrival_time", ticket.getArrivalTime().toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":seat_number", ticket.getSeatNumber());
    query.bindValue(":price", ticket.getPrice());
}

bool Database::addPlaneToDatabase(const Plane& plane){
    QSqlQuery query;
    query.prepare("INSERT INTO Planes (model, airline, capacity)"
                  "VALUES (:model, :airline, :capacity)");


    bindQueryForPlanes(query, plane);
    return query.exec();
}

bool Database::deletePlaneFromDatabase(const Plane& plane){
    if (hasTicketsForPlane(plane)){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(nullptr, "Warning",
                                     "This plane has associated tickets. Deleting them will remove all related tickets!",
                                     QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::No) {
            return false;
        }
        if (!deleteTicketsForPlane(plane)) {
            qDebug() << "Failed to delete tickets for the plane!";
            return false;
        }
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Planes WHERE id = :plane_id");
    query.bindValue(":plane_id", plane.getPlaneID());

    return query.exec();
}

void Database::bindQueryForPlanes(QSqlQuery& query, const Plane& plane){
    query.bindValue(":model", plane.getModel());
    query.bindValue(":airline", plane.getAirline());
    query.bindValue(":capacity", plane.getCapacity());
}

bool Database::hasTicketsForPlane(const Plane& plane) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Tickets WHERE plane_id = :plane_id");
    query.bindValue(":plane_id", plane.getPlaneID());

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    qDebug() << "Error checking for tickets: " << query.lastError().text();
    return false;
}

bool Database::deleteTicketsForPlane(const Plane& plane) {
    QSqlQuery query;
    query.prepare("DELETE FROM Tickets WHERE plane_id = :plane_id");
    query.bindValue(":plane_id", plane.getPlaneID());

    return query.exec();
}

bool Database::addPassengerToDatabase(const Passenger& passenger){
    QSqlQuery query;
    query.prepare("INSERT INTO Passengers (first_name, last_name, birth_date, email, phone_number) "
                  "VALUES (:first_name, :last_name, :birth_date, :email, :phone_number)");

    bindQueryForPassengers(query, passenger);
    return query.exec();
}

bool Database::deletePassengerFromDatabase(const Passenger& passenger) {
    if (hasTicketsForPassenger(passenger)) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(nullptr, "Warning",
                                     "This passenger has associated tickets. Deleting them will remove all related tickets!",
                                     QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::No) {
            return false;
        }
        if (!deleteTicketsForPassenger(passenger)) {
            qDebug() << "Failed to delete tickets for passenger:" << passenger.getPassengerID();
            return false;
        }
    }

    QSqlQuery query;
    query.prepare("DELETE FROM passengers WHERE id = :id");
    query.bindValue(":id", passenger.getPassengerID());
    if (!query.exec()) {
        qDebug() << "Error deleting passenger:" << query.lastError().text();
        return false;
    }

    return true;
}

void Database::bindQueryForPassengers(QSqlQuery& query, const Passenger& passenger){
    query.bindValue(":first_name", passenger.getfirstName());
    query.bindValue(":last_name", passenger.getLastName());
    query.bindValue(":birth_date", passenger.getBirthDate().toString("yyyy-MM-dd"));
    query.bindValue(":email", passenger.getEmail());
    query.bindValue(":phone_number", passenger.getPhoneNumber());
}

bool Database::hasTicketsForPassenger(const Passenger& passenger) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Tickets WHERE passenger_id = :passenger_id");
    query.bindValue(":passenger_id", passenger.getPassengerID());

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    qDebug() << "Error checking for tickets: " << query.lastError().text();
    return false;
}

bool Database::deleteTicketsForPassenger(const Passenger& passenger) {
    QSqlQuery query;
    query.prepare("DELETE FROM Tickets WHERE passenger_id = :passenger_id");
    query.bindValue(":passenger_id", passenger.getPassengerID());

    return query.exec();
}

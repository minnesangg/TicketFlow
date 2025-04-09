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

    query.bindValue(":passenger_id", ticket.passengerID);
    query.bindValue(":plane_id", ticket.planeID);
    query.bindValue(":departure_city", ticket.departureCity);
    query.bindValue(":arrival_city", ticket.arrivalCity);
    query.bindValue(":departure_time", ticket.departureTime.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":arrival_time", ticket.arrivalTime.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":seat_number", ticket.seatNumber);
    query.bindValue(":price", ticket.price);

    return query.exec();
}



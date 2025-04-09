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

#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QComboBox>
#include "ticket.h"

/**
 * @brief Database schema for airline ticket management.
 *
 * This class handles the connection to the database and facilitates the manipulation of data in the following tables:
 * - Passengers
 * - Planes
 * - Tickets
 *
 * @note The following schema is used in the database:
 *
 * @verbatim
 * Table Passengers {
 *   id SERIAL [pk]
 *   first_name VARCHAR(100)
 *   last_name VARCHAR(100)
 *   birth_date DATE
 *   email VARCHAR(100)
 *   phone_number VARCHAR(20)
 * }
 *
 * Table Planes {
 *   id SERIAL [pk]
 *   model VARCHAR(100)
 *   capacity INT
 *   airline VARCHAR(100)
 * }
 *
 * Table Tickets {
 *   id SERIAL [pk]
 *   passenger_id INT [ref: > Passengers.id]
 *   plane_id INT [ref: > Planes.id]
 *   departure_city VARCHAR(100)
 *   arrival_city VARCHAR(100)
 *   departure_time TIMESTAMP
 *   arrival_time TIMESTAMP
 *   seat_number VARCHAR(10)
 *   price DECIMAL(10, 2)
 * }
 * @endverbatim
 *
 * ![Database Schema](./DBschema.png)
 */
class Database
{
public:
    /**
     * @brief Constructor of Database class.
     *
     * Initializes a connection to the database.
     */
    Database();

    /**
     * @brief Destructor.
     *
     * Closes the database connection if it's open.
     */
    ~Database();

    /**
     * @brief Selects all data from the Passengers table and outputs it to the debug console.
     *
     * This method retrieves all the passengers' data (id, first name, last name)
     * from the database and prints them for debugging purposes.
     */
    void selectData();

    /**
     * @brief Loads data into a combo box from a specified table and column.
     *
     * @param comboBox The combo box to populate.
     * @param table The name of the table to fetch data from.
     * @param column The column name to fetch data for.
     *
     * @return true if the data was loaded successfully, otherwise false.
     */
    bool loadComboBoxData(QComboBox* comboBox, const QString& table, const QString& column);

    /**
     * @brief Retrieves the passenger ID from the selected name and last name from combo boxes.
     *
     * This method searches the Passengers table using the selected first name and last name
     * to retrieve the corresponding passenger ID.
     *
     * @param nameComboBox The combo box containing the first names.
     * @param lastNameComboBox The combo box containing the last names.
     *
     * @return The ID of the selected passenger, or -1 if not found or if selection is incomplete.
     */
    int getPassengerIdFromComboBoxes(QComboBox* nameComboBox, QComboBox* lastNameComboBox);

    /**
     * @brief Adds a ticket to the Tickets table in the database.
     *
     * This method inserts a new ticket entry into the Tickets table.
     *
     * @param ticket The ticket object to be added.
     *
     * @return true if the ticket was successfully added, otherwise false.
     */
    bool addTicketToDatabase(const Ticket& ticket);

private:
    /**
     * @brief Connects to the PostgreSQL database.
     *
     * This method attempts to establish a connection to the PostgreSQL database.
     *
     * @return true if the connection was successful, otherwise false.
     */
    bool connectToDB();

    QSqlDatabase db; ///< Database connection instance.
};

#endif // DATABASE_H

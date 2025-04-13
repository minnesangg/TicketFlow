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
#include <QMessageBox>
#include <QDebug>
#include <QComboBox>
#include "ticket.h"
#include "plane.h"
#include "passenger.h"

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

    /**
     * @brief Deletes a ticket from the database.
     *
     * Removes a ticket record from the Tickets table that matches all fields of the provided Ticket object.
     *
     * @param ticket The Ticket object containing the details of the ticket to delete.
     * @return true if the deletion was successful, false otherwise.
     *
     * @note All fields must exactly match for the ticket to be deleted.
     *       If no matching ticket is found, the method will still return true, but no row will be affected.
     */
    bool deleteTicketFromDatabase(const Ticket& ticket);

    /**
     * @brief Binds the Ticket object values to the SQL query for execution.
     *
     * This method binds the attributes of the provided Ticket object to the corresponding SQL query placeholders
     * for insertion or deletion operations in the Tickets table.
     *
     * @param query The QSqlQuery object to bind the values to.
     * @param ticket The Ticket object whose values will be bound to the query.
     */
    void bindQueryForTickets(QSqlQuery& query, const Ticket& ticket);

    /**
     * @brief Adds a new plane record to the database.
     *
     * This method inserts a new plane record into the `Planes` table in the database.
     * The plane data (model, airline, and capacity) are bound to the SQL query
     * using the `bindQueryForPlanes` method and then executed.
     *
     * @param plane The Plane object containing the data to be inserted into the database.
     * @return `true` if the query was successfully executed and the plane was added, `false` otherwise.
     */
    bool addPlaneToDatabase(const Plane& plane);

    /**
     * @brief Deletes a plane record from the database.
     *
     * This method deletes a plane record from the `Planes` table in the database.
     * The plane to be deleted is identified by its model, airline, and capacity, which
     * are bound to the SQL query using the `bindQueryForPlanes` method before execution.
     *
     * @param plane The Plane object identifying the plane to be deleted.
     * @return `true` if the query was successfully executed and the plane was deleted, `false` otherwise.
     */
    bool deletePlaneFromDatabase(const Plane& plane);

    /**
     * @brief Binds plane data to the SQL query.
     *
     * This method binds the plane data (model, airline, and capacity) from the `Plane` object
     * to the provided SQL query using named placeholders. This allows the query to be executed
     * with the plane-specific data.
     *
     * @param query The QSqlQuery object that will be prepared and executed with the bound data.
     * @param plane The Plane object containing the data to be bound to the query.
     */
    void bindQueryForPlanes(QSqlQuery& query, const Plane& plane);

    /**
     * @brief Checks if there are any tickets associated with the given plane.
     *
     * This method queries the database to determine whether any records exist in the Tickets table
     * for the specified plane ID. If an error occurs during the query execution, it will be logged.
     *
     * @param plane The Plane object for which ticket association is checked.
     * @return true if there are associated tickets, false otherwise.
     */
    bool hasTicketsForPlane(const Plane& plane);

    /**
     * @brief Deletes all tickets associated with the given plane.
     *
     * This method removes all entries from the Tickets table that are linked to the specified plane ID.
     * If the query fails, the error is logged and the method returns false.
     *
     * @param plane The Plane object whose associated tickets are to be deleted.
     * @return true if the deletion was successful, false otherwise.
     */
    bool deleteTicketsForPlane(const Plane& plane);

    /**
     * @brief Adds a new passenger to the database.
     *
     * This method inserts a new record into the Passengers table using the provided Passenger object's details.
     * The query parameters are bound using the bindQueryForPassengers helper method.
     *
     * @param passenger The Passenger object containing the data to be inserted.
     * @return true if the insertion is successful, false otherwise.
     */
    bool addPassengerToDatabase(const Passenger& passenger);

    /**
     * @brief Binds passenger details to a SQL query.
     *
     * This helper method binds the Passenger object's fields to the corresponding placeholders in the SQL query.
     * It is typically used before executing queries involving passenger information.
     *
     * @param query The QSqlQuery object where the values will be bound.
     * @param passenger The Passenger object containing the data to bind.
     */
    void bindQueryForPassengers(QSqlQuery& query, const Passenger& passenger);

    /**
     * @brief Deletes a passenger from the database.
     *
     * This method first retrieves the passenger's ID by matching their personal information.
     * If the passenger has associated tickets, it prompts the user for confirmation and deletes the tickets if agreed.
     * Finally, it deletes the passenger from the database. If any database operation fails, an error is logged.
     *
     * @param passenger The Passenger object representing the passenger to delete.
     * @return true if the deletion is successful, false otherwise.
     */

    bool deletePassengerFromDatabase(const Passenger& passenger);

    /**
     * @brief Deletes all tickets associated with a given passenger.
     *
     * This method removes all entries from the Tickets table that are linked to the specified passenger.
     *
     * @param passenger The Passenger object whose tickets should be deleted.
     * @return true if the operation was successful, false otherwise.
     */
    bool deleteTicketsForPassenger(const Passenger& passenger);

    /**
     * @brief Checks if a passenger has associated tickets.
     *
     * This method executes a SQL query to determine whether any tickets are linked to the given passenger
     * in the Tickets table, based on the passenger's ID.
     *
     * @param passenger The Passenger object whose associated tickets are being checked.
     * @return true if the passenger has at least one associated ticket, false otherwise.
     */
    bool hasTicketsForPassenger(const Passenger& passenger);

    void reconnectDatabase();
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

#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

/**
 * @brief Database schema for airline ticket management
 *
 * Includes the following tables:
 * - Passengers
 * - Planes
 * - Tickets
 *
 * Database schema:
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
     */
    Database();

    /**
     * @brief Selects all data from DB
     */
    void selectData();
private:

    /**
     * @brief This method provides connection to postgres DB.
     * @return true if DB succesfully opened, etherwise - false.
     */
    bool connectToDB();



};

#endif // DATABASE_H

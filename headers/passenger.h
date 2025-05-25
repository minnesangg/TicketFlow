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


#ifndef PASSENGER_H
#define PASSENGER_H

#include <QString>
#include <QDate>

/**
 * @brief This file defines the Passenger class, which represents a passenger in the flight ticketing system.
 *
 * The Passenger class provides attributes and methods for storing and managing a passenger's personal details,
 * including name, email, phone number, birth date, and a unique passenger ID.
 *
 * Public Methods:
 * - `Passenger()`: Default constructor for initializing a passenger object.
 * - `getFirstName()`: Returns the first name of the passenger.
 * - `getLastName()`: Returns the last name of the passenger.
 * - `getEmail()`: Returns the email of the passenger.
 * - `getPhoneNumber()`: Returns the phone number of the passenger.
 * - `getBirthDate()`: Returns the birth date of the passenger.
 * - `getPassengerID()`: Returns the unique ID of the passenger.
 * - `setFirstName(QString firstName)`: Sets the first name of the passenger.
 * - `setLastName(QString lastName)`: Sets the last name of the passenger.
 * - `setEmail(QString email)`: Sets the email of the passenger.
 * - `setPhoneNumber(QString phoneNumber)`: Sets the phone number of the passenger.
 * - `setBirthDate(QDate birthDate)`: Sets the birth date of the passenger.
 * - `setPassengerID(int ID)`: Sets the unique ID of the passenger.
 *
 * Attributes:
 * - `firstName`: The first name of the passenger.
 * - `lastName`: The last name of the passenger.
 * - `email`: The email address of the passenger.
 * - `phoneNumber`: The phone number of the passenger.
 * - `birthDate`: The birth date of the passenger.
 * - `ID`: The unique ID assigned to the passenger.
 */
class Passenger
{
public:
    /**
     * @brief Default constructor for the Passenger class.
     * Initializes a passenger object with default values.
     */
    Passenger();

    /**
     * @brief Gets the first name of the passenger.
     * @return The first name of the passenger.
     */
    QString getfirstName() const;

    /**
     * @brief Gets the last name of the passenger.
     * @return The last name of the passenger.
     */
    QString getLastName() const;

    /**
     * @brief Gets the email of the passenger.
     * @return The email of the passenger.
     */
    QString getEmail() const;

    /**
     * @brief Gets the phone number of the passenger.
     * @return The phone number of the passenger.
     */
    QString getPhoneNumber() const;

    /**
     * @brief Gets the birth date of the passenger.
     * @return The birth date of the passenger.
     */
    QDate getBirthDate() const;

    /**
     * @brief Gets the unique ID of the passenger.
     * @return The unique ID of the passenger.
     */
    int getPassengerID() const;

    /**
     * @brief Sets the first name of the passenger.
     * @param firstName The first name of the passenger.
     */
    void setFirstName(QString firstName);

    /**
     * @brief Sets the last name of the passenger.
     * @param lastName The last name of the passenger.
     */
    void setLastName(QString lastName);

    /**
     * @brief Sets the email of the passenger.
     * @param email The email address of the passenger.
     */
    void setEmail(QString email);

    /**
     * @brief Sets the phone number of the passenger.
     * @param phoneNumber The phone number of the passenger.
     */
    void setPhoneNumber(QString phoneNumber);

    /**
     * @brief Sets the birth date of the passenger.
     * @param birthDate The birth date of the passenger.
     */
    void setBirthDate(QDate birthDate);

    /**
     * @brief Sets the unique ID of the passenger.
     * @param ID The unique ID of the passenger.
     */
    void setPassengerID(int ID);

private:
    QString firstName; ///< The first name of the passenger.
    QString lastName; ///< The last name of the passenger.
    QString email; ///< The email address of the passenger.
    QString phoneNumber; ///< The phone number of the passenger.
    QDate birthDate; ///< The birth date of the passenger.
    int ID; ///< The unique ID assigned to the passenger.
};

#endif // PASSENGER_H

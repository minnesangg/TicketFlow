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

#ifndef TICKET_H
#define TICKET_H

#include <QString>
#include <QDateTime>

/**
 * @brief This file defines the Ticket class, which represents a flight ticket in the system.
 *
 * The Ticket class provides attributes and methods for storing and managing flight ticket details, including:
 * 1. Passenger and plane information.
 * 2. Departure and arrival details.
 * 3. Price, seat number, and ticket ID.
 *
 * Public Methods:
 * - `Ticket()`: Constructor for initializing a ticket.
 * - `setPassengerID(int passengerID)`: Sets the ID of the passenger associated with the ticket.
 * - `setPlaneID(int planeID)`: Sets the ID of the plane associated with the ticket.
 * - `setPrice(int price)`: Sets the price of the ticket.
 * - `setSeatNumber(int seatNumber)`: Sets the seat number for the ticket.
 * - `setDepartureCity(QString departureCity)`: Sets the departure city for the flight.
 * - `setArrivalCity(QString arrivalCity)`: Sets the arrival city for the flight.
 * - `setDepartureTime(QDateTime departureTime)`: Sets the departure time for the flight.
 * - `setArrivalTime(QDateTime arrivalTime)`: Sets the arrival time for the flight.
 * - `getPassengerID()`: Gets the ID of the passenger.
 * - `getPlaneID()`: Gets the ID of the plane.
 * - `getPrice()`: Gets the price of the ticket.
 * - `getSeatNumber()`: Gets the seat number for the ticket.
 * - `getDepartureCity()`: Gets the departure city for the flight.
 * - `getArrivalCity()`: Gets the arrival city for the flight.
 * - `getDepartureTime()`: Gets the departure time for the flight.
 * - `getArrivalTime()`: Gets the arrival time for the flight.
 *
 * Attributes:
 * - `departureCity`: The city from which the flight departs.
 * - `arrivalCity`: The city where the flight arrives.
 * - `departureTime`: The date and time of departure.
 * - `arrivalTime`: The date and time of arrival.
 * - `price`: The price of the ticket.
 * - `seatNumber`: The seat number assigned to the passenger.
 * - `ticketID`: The unique ID of the ticket.
 * - `passengerID`: The ID of the passenger who owns the ticket.
 * - `planeID`: The ID of the plane for the flight.
 */

class Ticket
{
public:
    /**
     * @brief Default constructor for the Ticket class.
     * Initializes a ticket object.
     */
    Ticket();

    /**
     * @brief Sets the passenger ID for the ticket.
     * @param passengerID The ID of the passenger.
     */
    void setPassengerID(int passengerID);

    /**
     * @brief Sets the plane ID for the ticket.
     * @param planeID The ID of the plane.
     */
    void setPlaneID(int planeID);

    /**
     * @brief Sets the price for the ticket.
     * @param price The price of the ticket.
     */
    void setPrice(float price);

    /**
     * @brief Sets the seat number for the ticket.
     * @param seatNumber The seat number on the flight.
     */
    void setSeatNumber(QString seatNumber);

    /**
     * @brief Sets the departure city for the ticket.
     * @param departureCity The city of departure.
     */
    void setDepartureCity(QString departureCity);

    /**
     * @brief Sets the arrival city for the ticket.
     * @param arrivalCity The city of arrival.
     */
    void setArrivalCity(QString arrivalCity);

    /**
     * @brief Sets the departure time for the ticket.
     * @param departureTime The date and time of departure.
     */
    void setDepartureTime(QDateTime departureTime);

    /**
     * @brief Sets the arrival time for the ticket.
     * @param arrivalTime The date and time of arrival.
     */
    void setArrivalTime(QDateTime arrivalTime);

    /**
     * @brief Gets the passenger ID for the ticket.
     * @return The ID of the passenger.
     */
    int getPassengerID() const;

    /**
     * @brief Gets the plane ID for the ticket.
     * @return The ID of the plane.
     */
    int getPlaneID() const;

    /**
     * @brief Gets the price for the ticket.
     * @return The price of the ticket.
     */
    float getPrice() const;

    /**
     * @brief Gets the seat number for the ticket.
     * @return The seat number on the flight.
     */
    QString getSeatNumber() const;

    /**
     * @brief Gets the departure city for the ticket.
     * @return The city of departure.
     */
    QString getDepartureCity() const;

    /**
     * @brief Gets the arrival city for the ticket.
     * @return The city of arrival.
     */
    QString getArrivalCity() const;

    /**
     * @brief Gets the departure time for the ticket.
     * @return The date and time of departure.
     */
    QDateTime getDepartureTime() const;

    /**
     * @brief Gets the arrival time for the ticket.
     * @return The date and time of arrival.
     */
    QDateTime getArrivalTime() const;

private:
    QString departureCity; ///< The city from which the flight departs.
    QString arrivalCity; ///< The city where the flight arrives.
    QDateTime departureTime; ///< The date and time of departure.
    QDateTime arrivalTime; ///< The date and time of arrival.
    QString seatNumber; ///< The seat number assigned to the passenger.
    float price; ///< The price of the ticket.
    int ticketID; ///< The unique ID of the ticket.
    int passengerID; ///< The ID of the passenger.
    int planeID; ///< The ID of the plane.
};

#endif // TICKET_H

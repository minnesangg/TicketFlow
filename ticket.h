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
 * @brief The Ticket class represents a flight ticket with attributes such as passenger, plane, and flight details.
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
    void setPrice(int price);

    /**
     * @brief Sets the seat number for the ticket.
     * @param seatNumber The seat number on the flight.
     */
    void setSeatNumber(int seatNumber);

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

    // Public member variables for ticket details
    QString departureCity; ///< The city from which the flight departs.
    QString arrivalCity; ///< The city where the flight arrives.
    QDateTime departureTime; ///< The date and time of departure.
    QDateTime arrivalTime; ///< The date and time of arrival.
    int price; ///< The price of the ticket.
    int seatNumber; ///< The seat number assigned to the passenger.
    int ticketID; ///< The unique ID of the ticket.
    int passengerID; ///< The ID of the passenger.
    int planeID; ///< The ID of the plane.
};

#endif // TICKET_H

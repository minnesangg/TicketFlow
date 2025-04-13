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

#ifndef PLANE_H
#define PLANE_H

#include <QString>

/**
 * @brief This file defines the Plane class, which represents an airplane in the system.
 *
 * The Plane class provides attributes and methods for storing and managing information about airplanes, including:
 * 1. The model of the airplane.
 * 2. The airline operating the airplane.
 * 3. The seating capacity of the airplane.
 *
 * Public Methods:
 * - `Plane()`: Constructor for initializing a plane object with default values.
 * - `setModel(QString model)`: Sets the model of the airplane (e.g., "Boeing 737").
 * - `setAirline(QString airline)`: Sets the airline operating the airplane (e.g., "American Airlines").
 * - `setCapacity(int capacity)`: Sets the seating capacity of the airplane.
 * - `getModel()`: Gets the model of the airplane.
 * - `getAirline()`: Gets the airline operating the airplane.
 * - `getCapacity()`: Gets the seating capacity of the airplane.
 *
 * Attributes:
 * - `model`: The model of the airplane (e.g., "Boeing 737").
 * - `airline`: The airline operating the airplane (e.g., "American Airlines").
 * - `capacity`: The seating capacity of the airplane, representing the maximum number of passengers it can carry.
 */
class Plane
{
public:
    /**
     * @brief Default constructor for the Plane class.
     *
     * Initializes an empty plane object. The model, airline, and capacity will be set to default values.
     */
    Plane();

    /**
     * @brief Sets the model of the plane.
     *
     * @param model The model of the plane (e.g., "Boeing 737").
     */
    void setModel(QString model);

    /**
     * @brief Sets the airline operating the plane.
     *
     * @param airline The airline of the plane (e.g., "American Airlines").
     */
    void setAirline(QString airline);

    /**
     * @brief Sets the capacity of the plane.
     *
     * @param capacity The maximum number of passengers the plane can carry.
     */
    void setCapacity(int capacity);

    /**
     * @brief Retrieves the model of the plane.
     *
     * @return The model of the plane (e.g., "Boeing 737").
     */
    QString getModel() const;

    /**
     * @brief Retrieves the airline operating the plane.
     *
     * @return The airline of the plane (e.g., "American Airlines").
     */
    QString getAirline() const;

    /**
     * @brief Retrieves the capacity of the plane.
     *
     * @return The capacity of the plane, which is the maximum number of passengers it can carry.
     */
    int getCapacity() const;

    int getPlaneID() const;

private:
    QString model;    /**< Model of the plane (e.g., "Boeing 737") */
    QString airline;  /**< Airline of the plane (e.g., "American Airlines") */
    int capacity, ID;     /**< Maximum number of passengers the plane can carry */
};

#endif // PLANE_H

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


#ifndef MANAGER_H
#define MANAGER_H

#include "database.h"
#include "ticket.h"
#include "plane.h"
#include "passenger.h"
#include <QString>
#include <QDialog>
#include <QVector>
#include <QDebug>
#include <QTimer>

namespace Ui {
class Manager;
}

/**
 * @brief The Manager class provides the main functionality for managing tickets, passengers, and planes.
 * It includes options for adding tickets to the database and managing passengers and planes via a simple user interface.
 *
 * Public Methods:
 * - `Manager(QWidget *parent = nullptr)`: Constructor for initializing the manager dialog.
 * - `~Manager()`: Destructor for cleaning up resources.
 *
 * Private Slots:
 * - `on_addTicketButton_clicked()`: Handles the addition of a new ticket to the database.
 *
 * Private Methods:
 * - `listWidgetSettings()`: Configures the list widget for navigation between different management pages.
 * - `changePage(int index)`: Changes the page based on the user's selection in the list widget.
 * - `loadInfo()`: Loads data from the database into combo boxes for passengers and planes.
 * - `setTicketOptions()`: Sets the ticket details (e.g., passenger, plane, departure time) for a new ticket.
 */
class Manager : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the Manager class.
     * Initializes the manager dialog, sets up the UI, and loads necessary information.
     * @param parent Parent widget for the dialog.
     */
    explicit Manager(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the Manager class.
     * Cleans up allocated resources.
     */
    ~Manager();

private slots:
    /**
     * @brief Slot for handling the add ticket button click.
     * Gathers ticket details and attempts to add the ticket to the database.
     */
    void on_addTicketButton_clicked();

    /**
     * @brief Handles the ticket deletion process when the delete button is clicked.
     *
     * Reads input fields, validates them, and attempts to delete the corresponding ticket from the database.
     * Displays a success or error message in the status bar based on the operation result.
     *
     * @note If any input field is empty, the deletion will not be attempted and a warning will be shown.
     */
    void on_deleteTicketButton_clicked();

    /**
     * @brief Slot for handling the "Add Plane" button click event.
     *
     * This method is triggered when the "Add Plane" button is clicked. It checks if the necessary fields
     * (model, airline, and capacity) are filled. If they are, it attempts to add the plane to the database.
     * A success or failure message is displayed on the status bar accordingly.
     *
     * @note If any of the fields are not filled, an error message is shown prompting the user to fill all lines.
     */
    void on_addPlaneButton_clicked();

    /**
     * @brief Slot for handling the "Delete Plane" button click event.
     *
     * This method is triggered when the "Delete Plane" button is clicked. It checks if the necessary fields
     * (model, airline, and capacity) are filled. If they are, it attempts to delete the plane from the database.
     * A success or failure message is displayed on the status bar accordingly.
     *
     * @note If any of the fields are not filled, an error message is shown prompting the user to fill all lines.
     */
    void on_deletePlaneButton_clicked();

    void on_deletePassButton_clicked();

    void on_addPassButton_clicked();

private:
    Ui::Manager *ui; ///< Pointer to the user interface of the manager window.
    Database db; ///< Manages interactions with the database.
    Ticket ticket; ///< Holds ticket details.
    Plane plane; ///< Holds plane details.
    Passenger passenger; ///< Holds passenger details.
    QVector<Ticket> tickets; ///< List of tickets.


    QVector<QLineEdit*> ticketsLines;
    QVector<QLineEdit*> planesLines;
    QVector<QLineEdit*> passengersLines;
    /**
     * @brief Configures the list widget for the manager window.
     * Adds navigation items to switch between different management pages (tickets, passengers, planes).
     */
    void listWidgetSettings();

    /**
     * @brief Changes the current page based on the selected item in the list widget.
     * @param index The index of the selected item in the list widget.
     */
    void changePage(int index);

    /**
     * @brief Loads relevant information into combo boxes from the database (e.g., passengers, planes).
     */
    void loadInfo();

    /**
     * @brief Sets the options for the new ticket based on the user inputs.
     * This includes passenger, plane, departure/arrival details, and pricing.
     */
    void setTicketOptions();

    /**
     * @brief Sets the plane options based on user input.
     *
     * This method retrieves the values from the UI fields (model, airline, and capacity) and sets them in the
     * `plane` object. This data will later be used for adding or deleting the plane from the database.
     */
    void setPlaneOptions();

    void setPassengerOptions();

    /**
     * @brief Clears the status bar message after a delay.
     *
     * Clears the text in the status bar line edit 3 seconds after being triggered.
     */
    void clearStatusBar();

    /**
     * @brief Checks if all required input fields are filled.
     *
     * Iterates through specific QLineEdit fields and verifies that none are empty.
     *
     * @return true if all fields are filled, false otherwise.
     */
    bool ifLineFilled(QVector<QLineEdit*> lines);
};

#endif // MANAGER_H

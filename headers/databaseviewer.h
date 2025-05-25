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

#ifndef DATABASEVIEWER_H
#define DATABASEVIEWER_H

#include <QDialog>
#include "headers/database.h"
#include <QDebug>
#include <QString>
#include <QTableWidgetItem>
#include <QStringList>
#include <QMap>

/**
 * @brief DatabaseViewer class for displaying and interacting with database tables in a GUI.
 *
 * The DatabaseViewer class provides methods to display data from the "Tickets", "Passengers", and "Planes"
 * tables in a QTableWidget. It allows the user to select a table from a combo box, perform searches within
 * the displayed table, and manage the display of data through various functions for setting up the table headers
 * and filling the table with data.
 */

namespace Ui {
class DatabaseViewer;
}

class DatabaseViewer : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a DatabaseViewer object.
     *
     * This constructor initializes the UI, sets up the combo box to select the table to view,
     * and calls methods to load data and set up searching functionality.
     *
     * @param parent The parent QWidget.
     */
    explicit DatabaseViewer(QWidget *parent = nullptr);

    /**
     * @brief Destroys the DatabaseViewer object.
     *
     * This destructor cleans up any allocated resources, such as the UI.
     */
    ~DatabaseViewer();

private:
    /**
     * @brief Loads the table selection data into the combo box.
     *
     * Adds entries for "Tickets", "Passengers", and "Planes" to the combo box.
     */
    void loadComboBoxData();

    /**
     * @brief Loads data for the selected table and populates the QTableWidget.
     *
     * @param table The name of the selected table (e.g., "Tickets", "Passengers", "Planes").
     */
    void loadDataToTable(QString& table);

    /**
     * @brief Slot to handle changes in the combo box selection.
     *
     * @param index The index of the selected table in the combo box.
     */
    void comboBoxChanged(int index);

    /**
     * @brief Sets up the table display for the "Tickets" table.
     *
     * Configures the column headers and settings specific to displaying "Tickets" data.
     *
     * @param ticketsHeaders The list of column headers for the Tickets table.
     */
    void setupTableForTickets(QStringList& ticketsHeaders);

    /**
     * @brief Sets up the table display for the "Passengers" table.
     *
     * Configures the column headers and settings specific to displaying "Passengers" data.
     *
     * @param ticketsHeaders The list of column headers for the Passengers table.
     */
    void setupTableForPassengers(QStringList& ticketsHeaders);

    /**
     * @brief Sets up the table display for the "Planes" table.
     *
     * Configures the column headers and settings specific to displaying "Planes" data.
     *
     * @param ticketsHeaders The list of column headers for the Planes table.
     */
    void setupTableForPlanes(QStringList& ticketsHeaders);

    /**
     * @brief Fills the table with data from the "Tickets" table.
     *
     * Executes an SQL query to fetch data from the "Tickets" table and populates the QTableWidget.
     *
     * @param row The starting row for inserting data into the table.
     */
    void fillTableForTickets(int row);

    /**
     * @brief Fills the table with data from the "Passengers" table.
     *
     * Executes an SQL query to fetch data from the "Passengers" table and populates the QTableWidget.
     *
     * @param row The starting row for inserting data into the table.
     */
    void fillTableForPassengers(int row);

    /**
     * @brief Fills the table with data from the "Planes" table.
     *
     * Executes an SQL query to fetch data from the "Planes" table and populates the QTableWidget.
     *
     * @param row The starting row for inserting data into the table.
     */
    void fillTableForPlanes(int row);

    /**
     * @brief Sets up the search functionality for filtering the data in the table.
     *
     * Connects a text change signal from the search input field to filter the rows displayed in
     * the QTableWidget based on the search text.
     */
    void setupSearch();

    Ui::DatabaseViewer *ui; ///< The UI object for the DatabaseViewer dialog.
    Database db; ///< The database object used to interact with the database.
};

#endif // DATABASEVIEWER_H

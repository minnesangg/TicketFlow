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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "manager.h"
#include "databaseviewer.h"
#include "exportwindow.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief The MainWindow class represents the main window of the application.
 * It provides the user interface for interacting with the main functionality of the application.
 *
 * It includes the following actions:
 * - Exit the application with a confirmation prompt.
 * - Open the manage window for CRUD operations on applications.
 *
 * Slots:
 * - `on_exitButton_clicked()`: Handles the click event of the exit button, asking for confirmation to close the application.
 * - `on_manageButton_clicked()`: Opens the manage window for managing ticket applications.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the MainWindow class.
     * Initializes the user interface and sets up the layout.
     * @param parent The parent widget of this main window.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the MainWindow class.
     * Cleans up resources used by the main window.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Slot for handling the exit button click event.
     * Prompts the user for confirmation before closing the program.
     */
    void on_exitButton_clicked();

    /**
     * @brief Slot for handling the manage button click event.
     * Opens the management window for handling CRUD operations on applications.
     */
    void on_manageButton_clicked();

    /**
     * @brief Slot for handling the database viewer button click event.
     * Opens the database viewer window for handling find and view operations on applications.
     */
    void on_dbViewerButton_clicked();

    /**
     * @brief Slot for handling the pdf export button click event.
     * Opens the pdf export window for handling export one or all tables to PDF on applications.
     */
    void on_exportButton_clicked();

private:
    Ui::MainWindow *ui; ///< Pointer to the user interface of the main window.
    Database db; ///< Database instance for managing interactions with the database.
    Manager manager; ///< Manager instance for handling application-specific logic.
    DatabaseViewer dbViewer; ///< Database Viewer instance for handling database-view and find options.
    ExportWindow exportWindow; ///< PDF Export instance for handling one or all tables export as PDF options.
};

#endif // MAINWINDOW_H

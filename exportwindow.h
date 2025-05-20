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

#ifndef EXPORTWINDOW_H
#define EXPORTWINDOW_H

#include <QDialog>
#include <QFile>
#include <QPrinter>
#include <QFileDialog>
#include "database.h"


/**
 * @brief ExportWindow class. Dialog window for exporting database tables to PDF files.
 *
 * This class provides a GUI dialog that allows the user to select database tables,
 * generate HTML representations of their data, and export them as PDF files.
 *
 * Features:
 * - ComboBox to choose a single table to export.
 * - Button to export the selected table.
 * - Button to export all predefined tables.
 * - Displays the number of fields (columns) in the selected table.
 * - Generates HTML tables from SQL query results.
 * - Saves the generated HTML to a PDF file via a file dialog.
 *
 * Usage:
 * Instantiate this dialog, connect signals if needed, and show it.
 * User interactions trigger exports handled asynchronously.
 */

namespace Ui {
class ExportWindow;
}

class ExportWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the ExportWindow dialog.
     * @param parent Pointer to parent QWidget.
     */
    explicit ExportWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor.
     * Cleans up UI and allocated resources.
     */
    ~ExportWindow();

private slots:
    /**
     * @brief Triggered when the "Export Chosen" button is clicked.
     * Generates HTML for the selected table and saves it as a PDF.
     * Shows error message if table is empty or missing.
     */
    void on_exportChoosenButton_clicked();

    /**
     * @brief Triggered when the "Export All" button is clicked.
     * Generates HTML for all predefined tables and saves combined output as a PDF.
     * Shows error if no data available for export.
     */
    void on_exportAllButton_clicked();

    /**
     * @brief Handles changes in the table selection ComboBox.
     * Updates the label displaying the number of columns in the selected table.
     * @param index Index of the newly selected item.
     */
    void comboBoxChanged(int index);

private:
    Ui::ExportWindow *ui; ///< Pointer to the UI elements of the Login dialog.

    /**
     * @brief Handles database connection.
     */
    Database db;

    /**
     * @brief Fills the ComboBox with the list of tables available for export.
     */
    void setupComboBox();

    /**
     * @brief Generates an HTML table representation of the specified database table.
     * @param tableName Name of the database table.
     * @return HTML string containing the table data formatted as an HTML table.
     *         Returns an empty string if the table is empty or does not exist.
     */
    QString generateHtmlForTable(const QString& tableName);

    /**
     * @brief Saves the provided HTML content as a PDF file.
     * Opens a file dialog to select the output location.
     * @param html The HTML content to save.
     */
    void saveHtmlToPdf(const QString &html);
};

#endif // EXPORTWINDOW_H

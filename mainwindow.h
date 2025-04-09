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

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief The MainWindow class represents the main window of the application.
 * It provides the user interface for the main functionality of the application.
 * Here are the buttons for navigating the application:
 *      1. Go to the CRUD window (manage applications).
 *      2. Go to the search window (search applications by category, such as airports, airlines, etc.).
 *      3. Open application settings (language, theme, and other settings).
 *      4. Exit the application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief Constructor for the MainWindow class.
     * @param parent The parent widget of this main window.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the MainWindow class.
     */
    ~MainWindow();

private slots:

    /**
     * @brief Exit Button. When clicked, it asks the user if they are sure they want to close the program.
     * If they confirm, the program is closed.
     */
    void on_exitButton_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui; ///< Pointer to the user interface of the main window.
};
#endif // MAINWINDOW_H

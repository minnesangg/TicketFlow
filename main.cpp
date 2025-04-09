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


#include "mainwindow.h"
#include "login.h"
#include <QApplication>

/**
 * @brief The main function initializes the application and handles the login process.
 * It creates a Login dialog and shows it to the user. If the user successfully logs in,
 * it creates and shows the main window of the application.
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return The exit code of the application.
 */

int main(int argc, char *argv[])
{
    // Create a QApplication object, which is required for any Qt-based application
    QApplication app(argc, argv);
    // Create the login dialog
    Login login;

    login.show();
    
    // If the login dialog is accepted (user successfully logs in), open the main window
    if(login.exec() == QDialog::Accepted){
        MainWindow window;
        window.show();
        window.resize(800, 550);
        return app.exec();
    }

    return 0;
}

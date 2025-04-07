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


#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QStackedWidget>

namespace Ui {
class Login;
}

/**
    * @brief The Login class handles the login functionality of the application.
    * It provides a user interface for entering a password and verifies it against
    * a stored hash. If the password is correct, it allows access to the main
    * application.
 */
class Login : public QDialog
{
    Q_OBJECT

public:
    /**
        * @brief Constructor for the Login class.
        * @param parent The parent widget of this dialog.
        */
    explicit Login(QWidget *parent = nullptr);

    /**
        * @brief Destructor for the Login class.
        */
    ~Login();

private slots:
    /**
        * @brief Slot for handling the "Check Password" button click event.
        * It verifies the entered password and either allows access or shows an error message.
        */
    void on_checkPassButton_clicked();

    /**
        * @brief Slot for handling the "Sign In" button click event.
        * when pressed, two passwords are compared, and if they are equal, 
        * they are saved in the password.ini file(Then used to log in.)
        */
    void on_signInButton_clicked();

private:

    Ui::Login *ui; ///< Pointer to the UI elements of the Login dialog.

    /**
        * @brief Checks if the entered password matches the stored hash.
        * @param password The password to check.
        * @return True if the password is correct, false otherwise.
        */
    bool checkPassword(QString password);

    /**
        * @brief Checks if the entered password matches the stored hash.
        * @param password The password to hash.
        * @return True if password is equal to the stored hash, false otherwise.
        */
    bool verifyPassword(const QString& inputPassword);

    /**
        * @brief Retrieves the stored password hash from the configuration file.
        * @return The stored password hash as a QByteArray.
        */
    QByteArray getPasswordHash();

    /**
        * @brief Saves the entered password to the configuration file.
        * @param password The password to save.
        */
    void savePassword(QString password);

    QStackedWidget *stackedWidget; ///<! Pointer to the stacked widget for switching between different views.

};

#endif // LOGIN_H

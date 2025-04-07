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

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_checkPassButton_clicked();

    void on_signInButton_clicked();

private:
    Ui::Login *ui;
    bool checkPassword(QString password);
    bool verifyPassword(const QString& inputPassword);
    QByteArray getPasswordHash();
    void savePassword(QString password);
    QStackedWidget *stackedWidget;

};

#endif // LOGIN_H

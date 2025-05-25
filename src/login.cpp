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


#include "headers/login.h"
#include "forms/ui_login.h"


Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->resize(600, 400);
    QWidget *loginPage = ui->loginPage;
    QWidget *signInPage = ui->signInPage;
    stackedWidget = ui->stackedWidget;
    QSettings settings(QCoreApplication::applicationDirPath() + "/password.ini", QSettings::IniFormat);

    if(!settings.contains("PasswordHash") || !QFile::exists(QCoreApplication::applicationDirPath() + "/password.ini")) {
        stackedWidget->setCurrentWidget(signInPage);
    } else {
        stackedWidget->setCurrentWidget(loginPage);
    }
}

Login::~Login()
{
    delete ui;
}


void Login::on_checkPassButton_clicked()
{
    QString enterdPassword = ui->passwordLine->text();

    if(enterdPassword.isEmpty()){
        QMessageBox::critical(this, "Error", "Empty password line. Please try again.");
        return;
    }

    if(checkPassword(enterdPassword)){
        accept();
    } else {
        ui->passwordLine->clear();
    }
}


bool Login::checkPassword(QString password) {
    QSettings settings(QCoreApplication::applicationDirPath() + "/password.ini", QSettings::IniFormat);

    if (!verifyPassword(password)) {
        QMessageBox::critical(this, "Error", "Wrong Master Password. Please try again.");
        return false;
    }

    return true;
}

bool Login::verifyPassword(const QString& inputPassword){
    QByteArray inputHashed = QCryptographicHash::hash(inputPassword.toUtf8(), QCryptographicHash::Sha256);
    QByteArray savedHashed = getPasswordHash();

    return inputHashed == savedHashed;
}

QByteArray Login::getPasswordHash(){
    QSettings settings(QCoreApplication::applicationDirPath() + "/password.ini", QSettings::IniFormat);
    QString savedHashedHex = settings.value("PasswordHash", "").toString();

    if(savedHashedHex.isEmpty()){
        return QByteArray();
    }
    return QByteArray::fromHex(savedHashedHex.toUtf8());
}

void Login::savePassword(QString password){
    QByteArray hashedPass = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    QSettings settings(QCoreApplication::applicationDirPath() + "/password.ini", QSettings::IniFormat);
    settings.setValue("PasswordHash", QString(hashedPass.toHex()));
}


void Login::on_signInButton_clicked()
{
    QString password = ui->signInLine->text();
    QString repeatedPassword = ui->signInLineRepeat->text();

    if(password == repeatedPassword){
        savePassword(password);
        QMessageBox::information(this, "Success", "Password has been set! Please log in.");
        stackedWidget->setCurrentWidget(ui->loginPage);
    } else{
        QMessageBox::critical(this, "Error", "The repeated password does not match the original password.");
        ui->signInLine->clear();
        ui->signInLineRepeat->clear();
    }
}


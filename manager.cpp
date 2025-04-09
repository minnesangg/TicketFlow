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

#include "manager.h"
#include "ui_manager.h"

Manager::Manager(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Manager)
{
    ui->setupUi(this);
    listWidgetSettings();
    loadInfo();
}

Manager::~Manager()
{
    delete ui;
}

void Manager::listWidgetSettings(){
    QListWidgetItem *manageItem = new QListWidgetItem("Manage tickets");
    ui->listWidget->addItem(manageItem);

    QListWidgetItem *generateItem = new QListWidgetItem("Manage passengers");
    ui->listWidget->addItem(generateItem);

    QListWidgetItem *categoriesItem = new QListWidgetItem("Manage planes");
    ui->listWidget->addItem(categoriesItem);

    connect(ui->listWidget, &QListWidget::currentRowChanged, this, &Manager::changePage);
    ui->listWidget->setAlternatingRowColors(false);
    ui->listWidget->setUniformItemSizes(true);
    ui->listWidget->setSpacing(2);

}

void Manager::changePage(int index) {
    switch (index) {
    case 0:
        ui->stackedWidget->setCurrentWidget(ui->addTicketPage);
        break;
    case 1:
        ui->stackedWidget->setCurrentWidget(ui->addHumanPage);
        break;
    case 2:
        ui->stackedWidget->setCurrentWidget(ui->addPlanePage);
        break;
    default:
        break;
    }
}

void Manager::loadInfo(){
    db.loadComboBoxData(ui->nameCombo, "Passengers", "first_name");
    db.loadComboBoxData(ui->surnameCombo, "Passengers", "last_name");
    db.loadComboBoxData(ui->planeCombo, "Planes", "model");
}

void Manager::on_addTicketButton_clicked()
{
    setTicketOptions();
    if (db.addTicketToDatabase(ticket)) {
        qDebug() << "Ticket added successfully!";
    } else {
        qDebug() << "Failed to add ticket!";
    }
}

void Manager::setTicketOptions(){
    int passengerID = db.getPassengerIdFromComboBoxes(ui->nameCombo, ui->surnameCombo);
    int selectedPlaneId = ui->planeCombo->currentData().toInt();

    QString departureTimeString = ui->departureTimeLine->text();
    QString format = "yyyy-MM-dd HH:mm:ss";
    QDateTime departureTime = QDateTime::fromString(departureTimeString, format);

    QString arrivalTimeString = ui->arrivalTimeLine->text();
    QDateTime arrivalTime = QDateTime::fromString(arrivalTimeString, format);

    ticket.setPassengerID(passengerID);
    ticket.setPlaneID(selectedPlaneId);
    ticket.setDepartureCity(ui->departureCityLine->text());
    ticket.setArrivalCity(ui->arrivalCityLine->text());
    ticket.setDepartureTime(departureTime);
    ticket.setArrivalTime(arrivalTime);
    ticket.setSeatNumber(ui->seatNumberLine->text().toInt());
    ticket.setPrice(ui->priceLine->text().toInt());
}

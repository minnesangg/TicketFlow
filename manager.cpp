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

    QVector<QLineEdit*> ticketsLines = {ui->arrivalCityLine, ui->arrivalTimeLine, ui->departureCityLine, ui->departureTimeLine, ui->priceLine,
                                  ui->seatNumberLine};
    QVector<QLineEdit*> planesLines = {ui->modelLine, ui->airlineLine, ui->capacityLine};
    QVector<QLineEdit*> passengersLines = {ui->firstNameLine, ui->lastNameLine, ui->emailLine, ui->birthDateLine, ui->phoneNumberLine};
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
    if(ifLineFilled(ticketsLines)){
        if (db.addTicketToDatabase(ticket)) {
            ui->statusBarLine->setText("Ticket added successfully!");
            clearStatusBar();
        } else {
            ui->statusBarLine->setText("Failed to add ticket! Database Error.");
            clearStatusBar();
        }
    } else {
        ui->statusBarLine->setText("Failed to add ticket. Fill all lines!");
        clearStatusBar();
    }
}

void Manager::on_deleteTicketButton_clicked()
{
    setTicketOptions();
    if(ifLineFilled(ticketsLines)){
        if(db.deleteTicketFromDatabase(ticket)){
            ui->statusBarLine->setText("Ticket succesfully deleted!");
            clearStatusBar();
        } else {
            ui->statusBarLine->setText("Failed to delete ticket! Database Error.");
            clearStatusBar();
        }
    } else {
        ui->statusBarLine->setText("Failed to add ticket. Fill all lines!");
        clearStatusBar();
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
    ticket.setSeatNumber(ui->seatNumberLine->text());
    ticket.setPrice(ui->priceLine->text().toFloat());
}

void Manager::clearStatusBar(){
    QTimer::singleShot(3000, this, [=]() {
        ui->statusBarLine->clear();
    });
}

bool Manager::ifLineFilled(QVector<QLineEdit*> lines){
    for(int i = 0; i < lines.size(); i++){
        if (lines[i]->text().isEmpty()) {
            return false;
        }
    }
    return true;
}


void Manager::on_addPlaneButton_clicked() {
    setPlaneOptions();

    if(ifLineFilled(planesLines)){
        if(db.addPlaneToDatabase(plane)){
            ui->statusBarLine->setText("Plane added succesfully!");
            clearStatusBar();
        } else {
            ui->statusBarLine->setText("Failed to add plane! Database Error.");
            clearStatusBar();
        }
    } else {
        ui->statusBarLine->setText("Failed to add plane. Fill all lines!");
        clearStatusBar();
    }
}

void Manager::on_deletePlaneButton_clicked() {
    setPlaneOptions();

    if (!ifLineFilled(planesLines)) {
        ui->statusBarLine->setText("Failed to delete plane. Fill all lines!");
        clearStatusBar();
        return;
    }

    if (!db.deletePlaneFromDatabase(plane)) {
        ui->statusBarLine->setText("Failed to delete plane! Database Error.");
        clearStatusBar();
        return;
    }

    ui->statusBarLine->setText("Plane deleted successfully!");
    clearStatusBar();
}

void Manager::setPlaneOptions(){
    plane.setModel(ui->modelLine->text());
    plane.setAirline(ui->airlineLine->text());
    plane.setCapacity(ui->capacityLine->text().toInt());
}

void Manager::on_addPassButton_clicked() {
    setPassengerOptions();

    if(ifLineFilled(passengersLines)){
        if(db.addPassengerToDatabase(passenger)){
            ui->statusBarLine->setText("Passenger added succesfully!");
            clearStatusBar();
        } else {
            ui->statusBarLine->setText("Failed to add passenger! Database Error.");
            clearStatusBar();
        }
    } else {
        ui->statusBarLine->setText("Failed to add passenger. Fill all lines!");
        clearStatusBar();
    }
}

void Manager::on_deletePassButton_clicked() {
    setPassengerOptions();

    if (!ifLineFilled(passengersLines)) {
        ui->statusBarLine->setText("Failed to delete passenger. Fill all lines!");
        clearStatusBar();
        return;
    }

    if (!db.deletePassengerFromDatabase(passenger)) {
        ui->statusBarLine->setText("Failed to delete passenger! Database Error.");
        clearStatusBar();
        return;
    }

    ui->statusBarLine->setText("Passenger deleted successfully!");
    clearStatusBar();
}

void Manager::setPassengerOptions(){
    passenger.setFirstName(ui->firstNameLine->text());
    passenger.setLastName(ui->lastNameLine->text());
    passenger.setBirthDate(QDate::fromString(ui->birthDateLine->text(), "yyyy-MM-dd"));
    passenger.setEmail(ui->emailLine->text());
    passenger.setPhoneNumber(ui->phoneNumberLine->text());
}

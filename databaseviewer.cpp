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

#include "databaseviewer.h"
#include "ui_databaseviewer.h"

DatabaseViewer::DatabaseViewer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DatabaseViewer)
{
    ui->setupUi(this);
    ui->dbViewerLayout->setAlignment(Qt::AlignCenter);
    ui->findAndOptLayout->setAlignment(Qt::AlignCenter);
    loadComboBoxData();
    connect(ui->tableSelectComboBox, &QComboBox::currentIndexChanged,
            this, &DatabaseViewer::comboBoxChanged);

    QString defaultTable = "Tickets";

    setupSearch();
    loadDataToTable(defaultTable);
}

DatabaseViewer::~DatabaseViewer()
{
    delete ui;
}

void DatabaseViewer::loadComboBoxData(){
    ui->tableSelectComboBox->clear();
    ui->tableSelectComboBox->addItem("Tickets");
    ui->tableSelectComboBox->addItem("Passengers");
    ui->tableSelectComboBox->addItem("Planes");

    ui->tableSelectComboBox->setCurrentIndex(0);
}

void DatabaseViewer::comboBoxChanged(int index){
    QString selectedText = ui->tableSelectComboBox->itemText(index);
    qDebug() << "Выбрана таблица:" << selectedText;
    loadDataToTable(selectedText);
}

void DatabaseViewer::setupSearch(){
    connect(ui->finderLineEdit, &QLineEdit::textChanged, this, [=](const QString& text){
        for(int row = 0; row < ui->databaseViewer->rowCount(); row++){
            bool found = false;

            for(int column = 0; column < ui->databaseViewer->columnCount(); column++){
                auto* item = ui->databaseViewer->item(row, column);
                if(item && item->text().contains(text, Qt::CaseInsensitive)){
                    found = true;
                    break;
                }
            }
            ui->databaseViewer->setRowHidden(row, !found);
        }
    });
}

void DatabaseViewer::loadDataToTable(QString& table){
    int id = 0;
    QStringList ticketsHeaders;
    QStringList passengersHeaders;
    QStringList planesHeaders;

    if(table == "Tickets"){
        id = 0;
    } else if(table == "Passengers"){
        id = 1;
    } else if(table == "Planes"){
        id = 2;
    } else {
        qDebug() << "Unknown table(loadDataToTable func)";
    }

    switch(id){
        case 0:
            setupTableForTickets(ticketsHeaders);
            fillTableForTickets(8);
            break;
        case 1:
            setupTableForPassengers(passengersHeaders);
            fillTableForPassengers(5);
            break;
        case 2:
            setupTableForPlanes(planesHeaders);
            fillTableForPlanes(3);
            break;
        default:
            return;
    }
}

void DatabaseViewer::setupTableForTickets(QStringList& ticketsHeaders){
    ui->databaseViewer->setColumnCount(8);
    ticketsHeaders << "Passenger ID" << "Plane ID" << "Departure City" << "Arrival City" << "Departure Time" << "Arrival Time"
                   << "Seat Number" << "Price";
    ui->databaseViewer->setHorizontalHeaderLabels(ticketsHeaders);
    ui->databaseViewer->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->databaseViewer->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->databaseViewer->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->databaseViewer->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DatabaseViewer::setupTableForPassengers(QStringList& passengersHeaders){
    ui->databaseViewer->setColumnCount(5);
    passengersHeaders << "First Name" << "Last Name" << "Birth Date" << "Email" << "Phone Number";
    ui->databaseViewer->setHorizontalHeaderLabels(passengersHeaders);
    ui->databaseViewer->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->databaseViewer->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->databaseViewer->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->databaseViewer->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DatabaseViewer::setupTableForPlanes(QStringList& planesHeaders){
    ui->databaseViewer->setColumnCount(3);
    planesHeaders << "Model" << "Capacity" << "Airline";
    ui->databaseViewer->setHorizontalHeaderLabels(planesHeaders);
    ui->databaseViewer->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->databaseViewer->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->databaseViewer->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->databaseViewer->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DatabaseViewer::fillTableForTickets(int row){
    ui->databaseViewer->setRowCount(0);

    QSqlQuery query("SELECT passenger_id, plane_id, departure_city, arrival_city, "
                    "departure_time, arrival_time, seat_number, price FROM Tickets");

    row = 0;
    while (query.next()) {
        ui->databaseViewer->insertRow(row);
        for (int col = 0; col < 8; ++col) {
            QString value = query.value(col).toString();
            ui->databaseViewer->setItem(row, col, new QTableWidgetItem(value));
        }
        ++row;
    }

    ui->databaseViewer->show();
}


void DatabaseViewer::fillTableForPassengers(int row){
    ui->databaseViewer->setRowCount(0);

    QSqlQuery query("SELECT first_name, last_name, birth_date, email, phone_number FROM Passengers");

    row = 0;
    while (query.next()) {
        ui->databaseViewer->insertRow(row);
        for (int col = 0; col < 8; ++col) {
            QString value = query.value(col).toString();
            ui->databaseViewer->setItem(row, col, new QTableWidgetItem(value));
        }
        ++row;
    }

    ui->databaseViewer->show();
}

void DatabaseViewer::fillTableForPlanes(int row){
    ui->databaseViewer->setRowCount(0);

    QSqlQuery query("SELECT model, capacity, airline FROM Planes");

    row = 0;
    while (query.next()) {
        ui->databaseViewer->insertRow(row);
        for (int col = 0; col < 8; ++col) {
            QString value = query.value(col).toString();
            ui->databaseViewer->setItem(row, col, new QTableWidgetItem(value));
        }
        ++row;
    }

    ui->databaseViewer->show();
}

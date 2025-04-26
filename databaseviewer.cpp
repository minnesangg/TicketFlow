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
    ui->databaseViewer->setSelectionMode(QAbstractItemView::NoSelection);
    ui->databaseViewer->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DatabaseViewer::setupTableForPassengers(QStringList& passengersHeaders){
    ui->databaseViewer->setColumnCount(5);
    passengersHeaders << "First Name" << "Last Name" << "Birth Date" << "Email" << "Phone Number";
    ui->databaseViewer->setHorizontalHeaderLabels(passengersHeaders);
    ui->databaseViewer->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->databaseViewer->setSelectionMode(QAbstractItemView::NoSelection);
    ui->databaseViewer->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DatabaseViewer::setupTableForPlanes(QStringList& planesHeaders){
    ui->databaseViewer->setColumnCount(3);
    planesHeaders << "Model" << "Capacity" << "Airline";
    ui->databaseViewer->setHorizontalHeaderLabels(planesHeaders);
    ui->databaseViewer->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->databaseViewer->setSelectionMode(QAbstractItemView::NoSelection);
    ui->databaseViewer->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DatabaseViewer::fillTableForTickets(int row){
    QMap<QString, Ticket> tickets;
    ui->databaseViewer->insertRow(row);
    ui->databaseViewer->setItem(row, 0, new QTableWidgetItem("ticket"));
    ui->databaseViewer->setItem(row, 1, new QTableWidgetItem("chtoto"));
    ui->databaseViewer->show();
}

void DatabaseViewer::fillTableForPassengers(int row){
    ui->databaseViewer->insertRow(row);
}

void DatabaseViewer::fillTableForPlanes(int row){
    ui->databaseViewer->insertRow(row);
}

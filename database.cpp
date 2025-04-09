#include "database.h"

Database::Database() {
    connectToDB();
}

bool Database::connectToDB(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("postgres");

    if (!db.open()) {
        qDebug() << "Error: " << db.lastError().text();
        return false;
    }

    qDebug() << "Database connected successfully!";
    return true;
}

void Database::selectData() {

    QSqlQuery query("SELECT * FROM Passengers");

    while (query.next()) {
        int id = query.value(0).toInt();
        QString firstName = query.value(1).toString();
        QString lastName = query.value(2).toString();

        qDebug() << id << ": " << firstName << " " << lastName;
    }
}

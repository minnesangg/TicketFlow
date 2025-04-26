#ifndef DATABASEVIEWER_H
#define DATABASEVIEWER_H

#include <QDialog>
#include "database.h"
#include <QDebug>
#include <QString>
#include <QTableWidgetItem>
#include <QStringList>
#include <QMap>

namespace Ui {
class DatabaseViewer;
}

class DatabaseViewer : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseViewer(QWidget *parent = nullptr);
    ~DatabaseViewer();

private:

    void loadComboBoxData();

    void loadDataToTable(QString& table);

    void comboBoxChanged(int index);

    void setupTableForTickets(QStringList& ticketsHeaders);

    void setupTableForPassengers(QStringList& ticketsHeaders);

    void setupTableForPlanes(QStringList& ticketsHeaders);

    void fillTableForTickets(int row);

    void fillTableForPassengers(int row);

    void fillTableForPlanes(int row);

    Ui::DatabaseViewer *ui;
    Database db;
};

#endif // DATABASEVIEWER_H

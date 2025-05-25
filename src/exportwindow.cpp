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

#include "headers/exportwindow.h"
#include "forms/ui_exportwindow.h"

ExportWindow::ExportWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ExportWindow)
{
    ui->setupUi(this);

    connect(ui->chooseTableBox, &QComboBox::currentIndexChanged,
            this, &ExportWindow::comboBoxChanged);

    setupComboBox();
}

ExportWindow::~ExportWindow()
{
    delete ui;
}

void ExportWindow::setupComboBox(){
    ui->chooseTableBox->clear();
    ui->chooseTableBox->addItem("Tickets");
    ui->chooseTableBox->addItem("Passengers");
    ui->chooseTableBox->addItem("Planes");
}


void ExportWindow::comboBoxChanged(int index){
    QString selectedText = ui->chooseTableBox->itemText(index);
    int countOfFields = db.getColumnCount(selectedText);
    QString countOfFieldsStr = "         " + QString::number(countOfFields);
    ui->tableNumberLabel->setText(countOfFieldsStr);

}

void ExportWindow::on_exportChoosenButton_clicked(){
    QString tableName = ui->chooseTableBox->currentText();
    QString html = "<html><head><meta charset='utf-8'></head><body>";

    QString tableHtml = generateHtmlForTable(tableName);
    if (tableHtml.isEmpty()) {
        QMessageBox::warning(this, "Error", "Table is empty, or table is not existing.");
        return;
    }

    html += tableHtml;
    html += "</body></html>";

    saveHtmlToPdf(html);
}


void ExportWindow::on_exportAllButton_clicked(){
    QStringList tables = {"Tickets", "Passengers", "Planes"};
    QString html = "<html><head><meta charset='utf-8'></head><body>";

    for (const QString &tableName : tables) {
        QString tableHtml = generateHtmlForTable(tableName);
        if (!tableHtml.isEmpty())
            html += tableHtml;
    }

    html += "</body></html>";

    if (html == "<html><head><meta charset='utf-8'></head><body></body></html>") {
        QMessageBox::warning(this, "Error", "No data for export.");
        return;
    }

    saveHtmlToPdf(html);
}

QString ExportWindow::generateHtmlForTable(const QString& tableName){
    QSqlQueryModel model;
    model.setQuery(QString("SELECT * FROM %1").arg(tableName));

    if (model.rowCount() == 0)
        return "";

    QString html = QString("<h2>Таблица: %1</h2>").arg(tableName);
    html += "<table border='1' cellspacing='0' cellpadding='2'>";

    html += "<tr>";
    for (int col = 0; col < model.columnCount(); ++col) {
        html += QString("<th>%1</th>").arg(model.headerData(col, Qt::Horizontal).toString());
    }
    html += "</tr>";

    for (int row = 0; row < model.rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < model.columnCount(); ++col) {
            html += QString("<td>%1</td>").arg(model.data(model.index(row, col)).toString());
        }
        html += "</tr>";
    }

    html += "</table><br><br>";

    return html;
}

void ExportWindow::saveHtmlToPdf(const QString &html){
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);

    QString filename = QFileDialog::getSaveFileName(this, "Save as PDF", "", "PDF files (*.pdf)");
    if (filename.isEmpty()) return;
    if (!filename.endsWith(".pdf")) filename += ".pdf";

    printer.setOutputFileName(filename);

    QTextDocument doc;
    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Success", "Export done!");
}

#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QMessageBox>
#include <QSettings>
#include <QCryptographicHash>
#include <QByteArray>
#include <QFile>


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


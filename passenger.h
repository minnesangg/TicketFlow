#ifndef PASSENGER_H
#define PASSENGER_H

#include <QString>
#include <QDate>

class Passenger
{
public:
    Passenger();

    QString getfirstName() const;
    QString getLastName() const;
    QString getEmail() const;
    QString getPhoneNumber() const;
    QDate getBirthDate() const;

    void setFirstName(QString firstName);
    void setLastName(QString lastName);
    void setEmail(QString email);
    void setPhoneNumber(QString phoneNumber);
    void setBirthDate(QDate birthDate);

private:
    QString firstName, lastName, email, phoneNumber;
    QDate birthDate;
};

#endif // PASSENGER_H

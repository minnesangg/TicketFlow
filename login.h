#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QStackedWidget>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_checkPassButton_clicked();

    void on_signInButton_clicked();

private:
    Ui::Login *ui;
    bool checkPassword(QString password);
    bool verifyPassword(const QString& inputPassword);
    QByteArray getPasswordHash();
    void savePassword(QString password);
    QStackedWidget *stackedWidget;

};

#endif // LOGIN_H

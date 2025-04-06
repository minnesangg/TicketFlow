#include "mainwindow.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Login login;

    login.show();

    if(login.exec() == QDialog::Accepted){
        MainWindow window;
        window.show();
        window.resize(1000, 700);
        return app.exec();
    }

    return 0;
}

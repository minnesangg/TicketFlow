#   TicketFlow
#   Copyright (C) 2025 minnesang
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program. If not, see <https://www.gnu.org/licenses/>.
#

QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/database.cpp \
    src/databaseviewer.cpp \
    src/login.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/manager.cpp \
    src/passenger.cpp \
    src/plane.cpp \
    src/ticket.cpp \
    src/exportwindow.cpp

HEADERS += \
    headers/database.h \
    headers/databaseviewer.h \
    headers/login.h \
    headers/mainwindow.h \
    headers/manager.h \
    headers/passenger.h \
    headers/plane.h \
    headers/ticket.h \
    headers/exportwindow.h

FORMS += \
    forms/databaseviewer.ui \
    forms/login.ui \
    forms/mainwindow.ui \
    forms/manager.ui \
    forms/exportwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

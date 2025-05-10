# TicketFlow - Airline Ticket Request Manager

**TicketFlow** is an application built with **Qt (C++)**, using a **Postgres** database for storage.  
It allows users to **manage airline ticket requests** through a clean and functional interface.  
All data is stored **locally** to ensure security and privacy.

Future updates will include **report generation, improved search filters, documentation with Doxygen, and more.**

## 📚 Documentation

For detailed documentation visit [TicketFlow Documentation](https://minnesangg.github.io/TicketFLowDocs/).

## 📌 Features

✅ Password-protected login. Passwords are securely hashed with **SHA-256**.

✅ User-friendly and minimalistic interface.

✅ Local storage using **Postgres**.

✅ Add new airline ticket requests to the database.

✅ Delete or archive ticket requests/passengers/planes.

✅ Edit and update existing ticket requests/passengers/planes.

✅ Advanced search and filtering options.

✅ Full documentation via **Doxygen**.

## 🚀 Future Improvements

🔹 Generate reports based on ticket requests.

## 🛠️ Technologies

- **Language**: C++
- **Framework**: Qt
- **Database**: Postgre SQL(Beekeeper Studio)

## 📜 License and Third-Party Components

1. This project is licensed under the **GNU General Public License v3.0 (GPLv3)**.  
You are free to use, modify, and distribute this software, but any derivative work must also be released under the GPLv3 license.

### Installation & Setup

#### Prerequisites:

- PostgreSQL database server (version 12 or higher recommended)
- Basic database administration knowledge

#### Database Connection:

Default connection parameters:

- **Host**: localhost
- **Port**: 5432
- **Database name**: ticketflowdb
- **Username**: postgres
- **Password**: postgres

#### Initial Setup:

1. Run the SQL scripts from `creatingTables.sql` to create the database schema.

---

### Database Structure

The system consists of three main tables:

- **Passengers**: Stores passenger information.
- **Planes**: Contains aircraft data.
- **Tickets**: Manages flight tickets and their relations.

---

### Usage

After successful setup, you can:

- Add new passengers and planes.
- Create, update, and cancel tickets.
- Generate reports on flight occupancy.
- Track passenger flight history.

---

### Troubleshooting

Common issues:

- **Connection problems**: Verify PostgreSQL service is running.
- **Permission errors**: Check database user privileges.
- **Schema errors**: Ensure all tables were created correctly.


## 🌟 Authors

Developed by **Minnesang**.  
Contributions are welcome!

---

# TicketFlow - Менеджер заявок на авиабилеты

**TicketFlow** — это приложение, разработанное на **Qt (C++)** с использованием базы данных **Postgres**.  
Оно позволяет **управлять заявками на авиабилеты** через удобный и функциональный интерфейс.  
Все данные хранятся **локально**, что обеспечивает безопасность и конфиденциальность.

В будущем планируется **генерация отчетов, расширенный поиск, документация через Doxygen** и многое другое.

## 📚 Документация

Для подробной документации посетите [Документацию TicketFlow](https://minnesangg.github.io/TicketFLowDocs/).

## 📌 Возможности

✅ Защита входа паролем. Пароль надёжно хешируется с помощью **SHA-256**.

✅ Удобный и минималистичный интерфейс.

✅ Локальное хранение данных через **Postgres**.

✅ Удаление или архивирование заявок/самолетов/пассажиров.

✅ Добавление новых заявок на авиабилеты/самолетов/пассажиров в базу данных.

✅ Редактирование и обновление существующих заявок/самолетов/пассажиров.

✅ Расширенные опции поиска и фильтрации.

✅ Полная документация через **Doxygen**.

## 🚀 Будущие улучшения

🔹  Генерация отчетов на основе заявок.

## 🛠️ Технологии

- **Язык**: C++
- **Фреймворк**: Qt
- **База данных**: Postgre SQL(Beekeeper Studio)

### Установка и настройка

#### Требования:

- Сервер PostgreSQL (рекомендуется версия 12 или выше)
- Базовые знания администрирования БД

#### Подключение к базе данных:

Параметры подключения по умолчанию:

- **Хост**: localhost
- **Порт**: 5432
- **Имя базы данных**: ticketflowdb
- **Пользователь**: postgres
- **Пароль**: postgres

#### Первоначальная настройка:

1. Выполните SQL-скрипты из файла `creatingTables.sql` для создания структуры БД.

---

### Структура базы данных

Система состоит из трех основных таблиц:

- **Passengers**: Хранит информацию о пассажирах.
- **Planes**: Содержит данные о самолетах.
- **Tickets**: Управляет билетами и их связями.

---

### Использование

После успешной настройки вы можете:

- Добавлять новых пассажиров и самолеты.
- Создавать, обновлять и отменять билеты.
- Формировать отчеты о загрузке рейсов.
- Отслеживать историю перелетов пассажиров.

---

### Решение проблем

Частые проблемы:

- **Проблемы с подключением**: Убедитесь, что служба PostgreSQL запущена.
- **Ошибки прав доступа**: Проверьте привилегии пользователя БД.
- **Ошибки структуры**: Убедитесь, что все таблицы созданы правильно.


## 📜 Лицензия и сторонние компоненты

1. Этот проект распространяется под лицензией **GNU General Public License v3.0 (GPLv3)**.  
Вы можете использовать, модифицировать и распространять программу, но любые производные работы также должны быть выпущены под лицензией GPLv3.

## 🌟 Авторы

Разработано **Minnesang**.  
Любые вклады приветствуются!

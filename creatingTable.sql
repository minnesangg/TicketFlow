-- Creating Passengers table
CREATE TABLE Passengers (
    id SERIAL PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
    birth_date DATE NOT NULL,
    email VARCHAR(100) UNIQUE,
    phone_number VARCHAR(20)
);

-- Creating Planes table
CREATE TABLE Planes (
    id SERIAL PRIMARY KEY,
    model VARCHAR(100) NOT NULL,
    capacity INT NOT NULL,
    airline VARCHAR(100) NOT NULL
);

-- Creating Tickets table
CREATE TABLE Tickets (
    id SERIAL PRIMARY KEY,
    passenger_id INT NOT NULL,
    plane_id INT NOT NULL,
    departure_city VARCHAR(100) NOT NULL,
    arrival_city VARCHAR(100) NOT NULL,
    departure_time TIMESTAMP NOT NULL,
    arrival_time TIMESTAMP NOT NULL,
    seat_number VARCHAR(10) NOT NULL,
    price DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (passenger_id) REFERENCES Passengers(id),
    FOREIGN KEY (plane_id) REFERENCES Planes(id)
);

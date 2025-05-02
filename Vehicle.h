#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
public:
    std::string regNumber;
    std::string model;
    double rentPerDay;
    bool isAvailable;

    Vehicle(std::string reg, std::string m, double rent)
        : regNumber(reg), model(m), rentPerDay(rent), isAvailable(true) {
    }

    void display() const {
        std::cout << "Reg No: " << regNumber << ", Model: " << model
            << ", Rent/Day: $" << rentPerDay
            << ", Status: " << (isAvailable ? "Available" : "Rented") << "\n";
    }
};

#endif


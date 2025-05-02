#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include "Vehicle.h"
#include "Customer.h"
#include <vector>
#include <algorithm>

class RentalSystem {
private:
    std::vector<Vehicle> vehicles;
    std::vector<Customer> customers;

public:
    void addVehicle(const std::string& reg, const std::string& model, double rent) {
        vehicles.emplace_back(reg, model, rent);
        std::cout << "Vehicle added.\n";
    }

    void addCustomer(const std::string& name, const std::string& license) {
        customers.emplace_back(name, license);
        std::cout << "Customer added.\n";
    }

    void viewVehicles() {
        for (const auto& v : vehicles) {
            v.display();
        }
    }

    void viewCustomers() {
        for (const auto& c : customers) {
            c.display();
        }
    }

    void rentVehicle(const std::string& reg) {
        for (auto& v : vehicles) {
            if (v.regNumber == reg) {
                if (v.isAvailable) {
                    v.isAvailable = false;
                    std::cout << "Vehicle rented.\n";
                    return;
                }
                else {
                    std::cout << "Vehicle already rented.\n";
                    return;
                }
            }
        }
        std::cout << "Vehicle not found.\n";
    }

    void returnVehicle(const std::string& reg) {
        for (auto& v : vehicles) {
            if (v.regNumber == reg) {
                v.isAvailable = true;
                std::cout << "Vehicle returned.\n";
                return;
            }
        }
        std::cout << "Vehicle not found.\n";
    }

    void sortVehiclesByRent() {
        std::sort(vehicles.begin(), vehicles.end(), [](Vehicle& a, Vehicle& b) {
            return a.rentPerDay < b.rentPerDay;
            });
        std::cout << "Vehicles sorted by rent.\n";
    }

    void searchVehicle(const std::string& reg) {
        for (auto& v : vehicles) {
            if (v.regNumber == reg) {
                v.display();
                return;
            }
        }
        std::cout << "Vehicle not found.\n";
    }
};

#endif

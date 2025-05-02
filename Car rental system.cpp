#include <iostream>
#include "RentalSystem.h"

void menu() {
    std::cout << "\n===== Car Rental System =====\n";
    std::cout << "1. Add Vehicle\n";
    std::cout << "2. Add Customer\n";
    std::cout << "3. View Vehicles\n";
    std::cout << "4. View Customers\n";
    std::cout << "5. Rent Vehicle\n";
    std::cout << "6. Return Vehicle\n";
    std::cout << "7. Search Vehicle\n";
    std::cout << "8. Sort Vehicles by Rent\n";
    std::cout << "9. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    RentalSystem rs;
    int choice;
    std::string reg, model, name, license;
    double rent;

    do {
        menu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            std::cout << "Enter Registration Number: ";
            getline(std::cin, reg);
            std::cout << "Enter Model: ";
            getline(std::cin, model);
            std::cout << "Enter Rent per Day: ";
            std::cin >> rent;
            std::cin.ignore();
            rs.addVehicle(reg, model, rent);
            break;

        case 2:
            std::cout << "Enter Customer Name: ";
            getline(std::cin, name);
            std::cout << "Enter License Number: ";
            getline(std::cin, license);
            rs.addCustomer(name, license);
            break;

        case 3:
            rs.viewVehicles();
            break;

        case 4:
            rs.viewCustomers();
            break;

        case 5:
            std::cout << "Enter Vehicle Registration Number: ";
            getline(std::cin, reg);
            rs.rentVehicle(reg);
            break;

        case 6:
            std::cout << "Enter Vehicle Registration Number: ";
            getline(std::cin, reg);
            rs.returnVehicle(reg);
            break;

        case 7:
            std::cout << "Enter Vehicle Registration Number: ";
            getline(std::cin, reg);
            rs.searchVehicle(reg);
            break;

        case 8:
            rs.sortVehiclesByRent();
            break;

        case 9:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid option.\n";
        }

    } while (choice != 9);

    return 0;
}

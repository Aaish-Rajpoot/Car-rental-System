#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    std::string name;
    std::string licenseNo;

    Customer(std::string n, std::string l)
        : name(n), licenseNo(l) {
    }

    void display() const {
        std::cout << "Customer: " << name << ", License No: " << licenseNo << "\n";
    }
};

#endif

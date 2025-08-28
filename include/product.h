#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    int product_id;
    string name;
    double price;
    int stock_quantity;

    Product() {}
    Product(int p, string n, double pt, int s);
    bool is_available();
    void update_stock_quantity(int new_quantity);
    double discount();
    void printdetails() const;
};

#endif

#include "product.h"

Product::Product(int p, string n, double pt, int s)
    : product_id(p), name(n), price(pt), stock_quantity(s) {}

bool Product::is_available() { return stock_quantity > 0; }

void Product::update_stock_quantity(int new_quantity) { stock_quantity = new_quantity; }

double Product::discount() {
    if (price > 10000) return price * 0.85;
    return price * 0.95;
}

void Product::printdetails() const{
    cout << product_id << ":" << name << ":" << price << ":" << stock_quantity << endl;
}

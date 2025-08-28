#ifndef CART_H
#define CART_H

#include "product.h"
#include "exception.h"

const int MAX_CART = 50;

class Cart {
public:
    int cart_id;
    int buyer_id;
    double tot = 0;
    Product p[MAX_CART];
    int p_count = 0;

    Cart() {}
    Cart(int c, int bid, double p);
    void addCart(const Product &prod);
    void removefrom_cart(int pid);
    void applyDiscount();
    void displaydetails();
    void clear_cart();
};

#endif

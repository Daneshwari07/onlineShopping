#ifndef WISHLIST_H
#define WISHLIST_H

#include "product.h"
#include "exception.h"

class Wishlist {
public:
    Product p[50];
    int p_count = 0;

    Wishlist() {}
    void searchProduct(int pid);
    void addWishlist(const Product &pt);
    void remove_wishlist(int pid);
    void display();
};

#endif

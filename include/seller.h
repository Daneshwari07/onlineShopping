
#ifndef SELLER_H
#define SELLER_H

#include "user.h"
#include "product.h"
#include "exception.h"

class Seller : public User {
public:
    int sellerid;
    string store;
    float rating;
    Product p[50];
    int p_count = 0;

    Seller() {}
    Seller(string n, string e, string p, string a, int sid, string st, float r);
    void login() override;
    void logout() override;
    void addProduct(const Product &pt);
    void deleteProduct(int pid);
    void list_product();
};

#endif

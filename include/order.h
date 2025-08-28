#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "exception.h"
#include "cart.h"
class Order {
public:
    int order_id;
    string buyer_name;
    Product products[MAX_CART];
    int product_count;
    double total_amount;

    Order() {}
    Order(int oid, string bname);
    void addProduct(const Product &product);
    void printOrderDetails() const;
};

#endif

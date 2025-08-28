#ifndef BUYER_H
#define BUYER_H

#include "user.h"
#include "wishlist.h"
#include "cart.h"
#include "order.h"

const int MAX_ORDER = 30;

class Buyer : public User {
public:
    int buyer_id;
    Wishlist w;
    int w_count;
    Cart c;
    int num_cart;
    Order *orders;
    int o_count;

    Buyer();
    Buyer(string n, string e, string p, string a, int bid);
    ~Buyer();

    void add_to_cart(Product &pt);
    void list_Wishlist(Product &pt);
    void remove_from_cart(int product_id);
    void place_order();
    void view_order_status(int order_id);
    void invoice() const;
    void cancel_order(int order_id);
};

#endif

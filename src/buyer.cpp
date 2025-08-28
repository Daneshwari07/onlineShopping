#include "buyer.h"

Buyer::Buyer() : buyer_id(0), w_count(0), num_cart(0), o_count(0) {
    orders = new Order[MAX_ORDER];
}

Buyer::Buyer(string n, string e, string p, string a, int bid)
    : User(n, e, p, a), buyer_id(bid), w_count(0), num_cart(0), o_count(0) {
    orders = new Order[MAX_ORDER];
}

Buyer::~Buyer() { delete[] orders; }

void Buyer::add_to_cart(Product &pt) { c.addCart(pt); }

void Buyer::list_Wishlist(Product &pt) { w.addWishlist(pt); }

void Buyer::remove_from_cart(int product_id) { c.removefrom_cart(product_id); }

void Buyer::place_order() {
    if (c.p_count == 0) throw Exception(501, "Cart is empty!");
    Order o(++o_count, name);
    for (int i = 0; i < c.p_count; i++) o.addProduct(c.p[i]);
    orders[o_count - 1] = o;
    c.clear_cart();
}

void Buyer::view_order_status(int order_id) {
    for (int i = 0; i < o_count; i++) {
        if (orders[i].order_id == order_id) {
            orders[i].printOrderDetails();
            return;
        }
    }
    throw Exception(502, "Order not found!");
}

void Buyer::invoice() const {
    cout << "--- Invoice ---" << endl;
    for (int i = 0; i < o_count; i++) orders[i].printOrderDetails();
}

void Buyer::cancel_order(int order_id) {
    for (int i = 0; i < o_count; i++) {
        if (orders[i].order_id == order_id) {
            for (int j = i; j < o_count - 1; j++) orders[j] = orders[j + 1];
            o_count--;
            return;
        }
    }
    throw Exception(503, "Order not found for cancellation!");
}
